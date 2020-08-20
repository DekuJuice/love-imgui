/**
* Copyright (c) 2006-2016 LOVE Development Team
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

#include "imgui/imgui.h"
#include "imgui_impl.h"
#include "wrap_imgui_impl.h"
#include "dostring_cache.h"

#include <vector>
#include <cstring>

// dostring cache hack
#ifdef luaL_dostring
#undef luaL_dostring
#define luaL_dostring DoStringCache::doString
#endif

#if defined(_WIN32) || defined(_WIN64)

#include <math.h>

// strndup() is not available on Windows
char *strndup( const char *s1, size_t n)
{
	char *copy= (char*)malloc( n+1 );
	memcpy( copy, s1, n );
	copy[n] = 0;
	return copy;
};

#endif

/*
** Love implentation functions
*/
static int	g_textures[250]; // Should be enough
static bool	g_returnValueLast = true;

static int w_Init(lua_State *L)
{
	// Initialize imgui
	int top = lua_gettop(L);
	Init(L);
	lua_settop(L, top);
    return 0;
}

static int w_ShutDown(lua_State *L)
{
	ShutDown();
	return 0;
}

static int w_NewFrame(lua_State *L)
{
	NewFrame();
	return 0;
}

// Util
const char* getRealDirectoryIfExists(lua_State *L, const char* relativePath)
{
	if (L == nullptr || relativePath == nullptr)
	{
		return nullptr;
	}

	int originalStackSize = lua_gettop(L);
	lua_getglobal(L, "love");
	if (lua_isnil(L, -1))
	{
		lua_pop(L, 1);
		return nullptr;
	}

	lua_getfield(L, -1, "filesystem");
	lua_getfield(L, -1, "getRealDirectory");
	lua_pushstring(L, relativePath);
	lua_call(L, 1, 1);

	char* result = nullptr;
	if (!lua_isnil(L, -1))
	{
		size_t size = 0;
		const char* tmp = lua_tolstring(L, -1, &size);
		result = strndup(tmp, size);
	}

	lua_pop(L, lua_gettop(L) - originalStackSize);
	return result;
}

// Inputs

static int w_MouseMoved(lua_State *L)
{
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	MouseMoved(x, y);
	return 0;
}

static int w_MousePressed(lua_State *L)
{
	int button = (int)luaL_checknumber(L, 1);
	MousePressed(button);
	return 0;
}

static int w_MouseReleased(lua_State *L)
{
	int button = (int)luaL_checknumber(L, 1);
	MouseReleased(button);
	return 0;
}

static int w_WheelMoved(lua_State *L)
{
	int y = (int)luaL_checknumber(L, 1);
	WheelMoved(y);
	return 0;
}

static int w_KeyPressed(lua_State *L)
{
	size_t size;
	const char *key = luaL_checklstring(L, 1, &size);
	KeyPressed(key);
	return 0;
}

static int w_KeyReleased(lua_State *L)
{
	size_t size;
	const char *key = luaL_checklstring(L, 1, &size);
	KeyReleased(key);
	return 0;
}

static int w_TextInput(lua_State *L)
{
	size_t size;
	const char *text = luaL_checklstring(L, 1, &size);
	TextInput(text);
	return 0;
}

static int w_GetWantCaptureMouse(lua_State *L)
{
	lua_pushboolean(L, GetWantCaptureMouse());
	return 1;
}

static int w_GetWantCaptureKeyboard(lua_State *L)
{
	lua_pushboolean(L, GetWantCaptureKeyboard());
	return 1;
}

static int w_GetWantTextInput(lua_State *L)
{
	lua_pushboolean(L, GetWantTextInput());
	return 1;
}

static int w_SetReturnValueLast(lua_State *L)
{
	g_returnValueLast = (bool)lua_toboolean(L, 1);
	return 0;
}

/*
** Custom bindings
*/

static int w_GetStyleColorName(lua_State *L)
{
	int idx = luaL_checkint(L, 1);
	lua_pushstring(L, ImGui::GetStyleColorName(idx - 1));
	return 1;
}

static int w_GetStyleColCount(lua_State *L)
{
	lua_pushinteger(L, ImGuiCol_COUNT);
	return 1;
}

static int w_AddFontDefault(lua_State *L)
{
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();
    return 0;
}

// AddFontFromFileTTF(filename, pixelSize, merge, glyphRange)
// Glyph range format is the same as imgui (pairs of ints, 0 to indicate end)
static int w_AddFontFromFileTTF(lua_State *L) {
    
    int max_args = lua_gettop(L);
    
	size_t filenameSize;
	const char* filename = luaL_checklstring(L, 1, &filenameSize);
	float pixelSize = luaL_checknumber(L, 2);
    bool merge = false;
        
    if (max_args >= 3) {
        merge = (bool)lua_toboolean(L, 3);        
    }
    
    bool custom_ranges = false;
    std::vector<ImWchar> glyph_ranges;
    
    if (max_args >= 4) {        
        luaL_checktype(L, 4, LUA_TTABLE);
        custom_ranges = true;
        int len = lua_objlen(L, 4);
        for (int i = 0; i < len; ++i) {
            lua_pushinteger(L, i + 1);
            lua_gettable(L, 4);
            glyph_ranges.push_back((ImWchar)luaL_checkinteger(L, -1));
        }
    }

	const char* basePath = getRealDirectoryIfExists(L, filename);
	if (basePath == nullptr) {
		lua_pushstring(L, "File does not exist.");
		lua_error(L);
		return 0;
	}

	char fullPath[4096] = {0};
	sprintf(fullPath, "%s/%s", basePath, filename);

    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig config;
    config.MergeMode = merge;

	ImFont* font = io.Fonts->AddFontFromFileTTF(
        &(fullPath[0]),
        pixelSize,
        &config,
        custom_ranges ? glyph_ranges.data() : NULL
    );
    io.Fonts->Build(); // We need to immediately build the font atlas before the glyph array goes out of scope
        
	lua_settop(L, 0);

	if (font == nullptr) {
		return luaL_error(L, "Could not load font");
	} else {
        lua_pushlightuserdata(L, (void*)font);
		return 1;
	}
}


static const char* const g_drawListTargets[] = {"background", "window", "foreground"};

/*
** Wrapped functions
*/

#define IMGUI_FUNCTION(name) \
static int impl_##name(lua_State *L) { \
	int max_args = lua_gettop(L); \
	int arg = 1; \
	int stackval = 0;

#define IMGUI_FUNCTION_DRAW_LIST(name) \
static int impl_##name(lua_State *L) { \
    int max_args = lua_gettop(L); \
    int arg = 1; \
    int stackval = 0; \
    int t_index = luaL_checkoption(L, arg++, "window", g_drawListTargets); \
    ImDrawList *draw_list = NULL; \
    if (t_index == 0) { \
        draw_list = ImGui::GetBackgroundDrawList(); \
    } else if (t_index == 1) { \
        draw_list = ImGui::GetWindowDrawList(); \
    } else if (t_index == 2) { \
        draw_list = ImGui::GetForegroundDrawList(); \
    } \
    if (!draw_list) { \
        return stackval; \
    } \
    
#define TEXTURE_ARG(name) \
	DoStringCache::getImgui(L); \
	lua_pushvalue(L, arg++); \
	lua_setfield(L, -2, "textureID"); \
	luaL_dostring(L, \
		"imgui.textures = imgui.textures or {} " \
		"table.insert(imgui.textures, imgui.textureID) " \
		"return #imgui.textures"); \
	lua_pop(L, 1); \
	int index = luaL_checkint(L, 0);\
	g_textures[index - 1] = index; \
	void *name = &g_textures[index - 1]; \

#define OPTIONAL_LABEL_ARG(name, value) \
	const char* name; \
	if (arg <= max_args) { \
		name = lua_tostring(L, arg++); \
					} else { \
		name = value; \
					}

#define LABEL_ARG(name) \
	size_t i_##name##_size; \
	const char * name = luaL_checklstring(L, arg++, &(i_##name##_size));

#define LABEL_POINTER_ARG(name) \
	size_t i_##name##_size; \
	const char * content = luaL_checklstring(L, arg++, &(i_##name##_size)); \
	size_t buf_size = luaL_checknumber(L, arg++); \
	char * name = new char [buf_size]; \
	std::strcpy(name, content);

#define END_LABEL_POINTER(name) \
	if (name != NULL) { \
		lua_pushstring(L, name); \
	delete[] name; \
		stackval++; \
				}

#define LABEL_ARRAY_ARG(name) \
	luaL_checktype(L, arg, LUA_TTABLE); \
	int len = lua_objlen(L, arg++); \
	std::vector<const char *> list; \
	for (int i = 0; i < len; i++) \
		{ \
	lua_pushinteger(L, i + 1); \
	lua_gettable(L, arg - 1); \
	size_t current_size; \
	list.push_back(luaL_checklstring(L, -1, &(current_size))); \
		} \
	const char **name = list.data(); \

#define IM_VEC_2_ARG(name)\
	const lua_Number i_##name##_x = luaL_checknumber(L, arg++); \
	const lua_Number i_##name##_y = luaL_checknumber(L, arg++); \
	ImVec2 name((float)i_##name##_x, (float)i_##name##_y);

#define OPTIONAL_IM_VEC_2_ARG(name, x, y) \
	lua_Number i_##name##_x = x; \
	lua_Number i_##name##_y = y; \
	if (arg <= max_args - 1) { \
		i_##name##_x = luaL_checknumber(L, arg++); \
		i_##name##_y = luaL_checknumber(L, arg++); \
			} \
	const ImVec2 name((float)i_##name##_x, (float)i_##name##_y);

#define IM_VEC_2_ARRAY_ARG(name)\
	luaL_checktype(L, arg, LUA_TTABLE); \
	int len = lua_objlen(L, arg++) / 2; \
	std::vector<ImVec2> list; \
	for (int i = 0; i < len; i++) \
			{ \
	lua_pushinteger(L, i*2 + 1); \
	lua_gettable(L, arg - 1); \
    float x = luaL_checknumber(L, -1);   \
    lua_pushinteger(L, i*2 + 2); \
    lua_gettable(L, arg - 1); \
    float y = luaL_checknumber(L, -1); \
	list.push_back(ImVec2(x, y)); \
			} \
	const ImVec2 *name = list.data(); \
    
#define IM_VEC_4_ARG(name)\
	const lua_Number i_##name##_x = luaL_checknumber(L, arg++); \
	const lua_Number i_##name##_y = luaL_checknumber(L, arg++); \
	const lua_Number i_##name##_z = luaL_checknumber(L, arg++); \
	const lua_Number i_##name##_w = luaL_checknumber(L, arg++); \
	const ImVec4 name((float)i_##name##_x, (float)i_##name##_y, (float)i_##name##_z, (float)i_##name##_w);

#define OPTIONAL_IM_VEC_4_ARG(name, x, y, z, w) \
	lua_Number i_##name##_x = x; \
	lua_Number i_##name##_y = y; \
	lua_Number i_##name##_z = z; \
	lua_Number i_##name##_w = w; \
	if (arg <= max_args - 1) { \
		i_##name##_x = luaL_checknumber(L, arg++); \
		i_##name##_y = luaL_checknumber(L, arg++); \
		i_##name##_z = luaL_checknumber(L, arg++); \
		i_##name##_w = luaL_checknumber(L, arg++); \
				} \
	const ImVec4 name((float)i_##name##_x, (float)i_##name##_y, (float)i_##name##_z, (float)i_##name##_w);

#define NUMBER_ARG(name)\
	lua_Number name = luaL_checknumber(L, arg++); \
    if (name == (lua_Number)HUGE_VAL) { \
        name = (lua_Number)FLT_MAX; \
    } else if(name == (lua_Number)-HUGE_VAL) { \
        name = (lua_Number)FLT_MIN; \
    }

#define OPTIONAL_NUMBER_ARG(name, otherwise)\
	lua_Number name = otherwise; \
	if (arg <= max_args) { \
		name = luaL_checknumber(L, arg++); \
	} \
    if (name == (lua_Number)HUGE_VAL) { \
        name = (lua_Number)FLT_MAX; \
    } else if(name == (lua_Number)-HUGE_VAL) { \
        name = (lua_Number)FLT_MIN; \
    }

#define FLOAT_POINTER_ARG(name) \
	float i_##name##_value = (float)luaL_checknumber(L, arg++); \
	float* name = &(i_##name##_value);

#define END_FLOAT_POINTER(name) \
	if (name != NULL) { \
		lua_pushnumber(L, i_##name##_value); \
		stackval++; \
			}

#define FLOAT_ARRAY_ARG(name) \
	luaL_checktype(L, arg, LUA_TTABLE); \
	int len = lua_objlen(L, arg++); \
	std::vector<float> list; \
	for (int i = 0; i < len; i++) \
			{ \
	lua_pushinteger(L, i + 1); \
	lua_gettable(L, arg - 1); \
	list.push_back(luaL_checknumber(L, -1)); \
			} \
	const float *name = list.data(); \

#define FLOAT_ARRAY2_ARG(name) \
	float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
	float name[2] = { i_##name##_1, i_##name##_2 };

#define END_FLOAT_ARRAY2(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		stackval += 2; \

#define FLOAT_ARRAY3_ARG(name) \
	float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_3 = (float)luaL_checknumber(L, arg++); \
	float name[3] = { i_##name##_1, i_##name##_2, i_##name##_3 };

#define END_FLOAT_ARRAY3(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		lua_pushnumber(L, name[2]); \
		stackval += 3; \

#define FLOAT_ARRAY4_ARG(name) \
	float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_3 = (float)luaL_checknumber(L, arg++); \
	float i_##name##_4 = (float)luaL_checknumber(L, arg++); \
	float name[4] = { i_##name##_1, i_##name##_2, i_##name##_3, i_##name##_4 };

#define END_FLOAT_ARRAY4(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		lua_pushnumber(L, name[2]); \
		lua_pushnumber(L, name[3]); \
		stackval += 4; \

#define INT_ARRAY2_ARG(name) \
	int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
	int name[2] = { i_##name##_1, i_##name##_2 };

#define END_INT_ARRAY2(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		stackval += 2; \

#define INT_ARRAY3_ARG(name) \
	int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_3 = (int)luaL_checkinteger(L, arg++); \
	int name[3] = { i_##name##_1, i_##name##_2, i_##name##_3 };

#define END_INT_ARRAY3(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		lua_pushnumber(L, name[2]); \
		stackval += 3; \

#define INT_ARRAY4_ARG(name) \
	int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_3 = (int)luaL_checkinteger(L, arg++); \
	int i_##name##_4 = (int)luaL_checkinteger(L, arg++); \
	int name[4] = { i_##name##_1, i_##name##_2, i_##name##_3, i_##name##_4 };

#define END_INT_ARRAY4(name) \
		lua_pushnumber(L, name[0]); \
		lua_pushnumber(L, name[1]); \
		lua_pushnumber(L, name[2]); \
		lua_pushnumber(L, name[3]); \
		stackval += 4; \

#define OPTIONAL_INT_ARG(name, otherwise)\
	int name = otherwise; \
	if (arg <= max_args) { \
		name = (int)luaL_checkinteger(L, arg++); \
			}

#define INT_ARG(name) \
	const int name = (int)luaL_checkinteger(L, arg++);

#define OPTIONAL_ENUM_ARG(name, otherwise)\
	int name = otherwise; \
	if (arg <= max_args) { \
	if (lua_istable(L, arg++)) { \
		int len = lua_objlen(L, -1); \
		for (int i = 0; i < len; i++) { \
			lua_pushinteger(L, i + 1); \
			lua_gettable(L, arg - 1); \
			lua_pushvalue(L, -1); \
			lua_gettable(L, lua_upvalueindex(1)); \
			name = name | (int)lua_tonumber(L, -1); \
			lua_pop(L, 1); \
				} \
		} else { \
		lua_pushvalue(L, arg - 1); \
		lua_gettable(L, lua_upvalueindex(1)); \
		name = (int)lua_tonumber(L, -1); \
		lua_pop(L, 1); \
			} \
			}

#define ENUM_ARG(name) \
	int name = 0; \
	if (lua_istable(L, arg++)) { \
		int len = lua_objlen(L, -1); \
		for (int i = 0; i < len; i++) { \
			lua_pushinteger(L, i + 1); \
			lua_gettable(L, arg - 1); \
			lua_pushvalue(L, -1); \
			lua_gettable(L, lua_upvalueindex(1)); \
			name = name | (int)lua_tonumber(L, -1); \
			lua_pop(L, 1); \
				} \
		} else { \
		lua_pushvalue(L, arg - 1); \
		lua_gettable(L, lua_upvalueindex(1)); \
		name = (int)lua_tonumber(L, -1); \
		lua_pop(L, 1); \
		}

#define OPTIONAL_UINT_ARG(name, otherwise)\
	unsigned int name = otherwise; \
	if (arg <= max_args) { \
		name = (unsigned int)luaL_checkint(L, arg++); \
			}

#define UINT_ARG(name) \
	const unsigned int name = (unsigned int)luaL_checkinteger(L, arg++);

#define INT_POINTER_ARG(name) \
	int i_##name##_value = (int)luaL_checkinteger(L, arg++); \
	int* name = &(i_##name##_value);

#define END_INT_POINTER(name) \
	if (name != NULL) { \
		lua_pushnumber(L, i_##name##_value); \
		stackval++; \
			}

#define INT_CURRENT_ITEM_POINTER_ARG(name) \
	int i_##name##_value = (int)luaL_checkinteger(L, arg++) - 1; \
	int* name = &(i_##name##_value);

#define END_INT_CURRENT_ITEM_POINTER(name) \
	if (name != NULL) { \
		lua_pushnumber(L, i_##name##_value + 1); \
		stackval++; \
				}

#define UINT_POINTER_ARG(name) \
	unsigned int i_##name##_value = (unsigned int)luaL_checkinteger(L, arg++); \
	unsigned int* name = &(i_##name##_value);

#define END_UINT_POINTER(name) \
	if (name != NULL) { \
		lua_pushnumber(L, i_##name##_value); \
		stackval++; \
			}

#define BOOL_POINTER_ARG(name) \
	bool i_##name##_value = (bool)lua_toboolean(L, arg++); \
	bool* name = &(i_##name##_value);

#define OPTIONAL_BOOL_POINTER_ARG(name) \
	bool i_##name##_value; \
	bool* name = NULL; \
	if (arg <= max_args) { \
	if (lua_isboolean(L, arg++)) \
			{ \
			i_##name##_value = (bool)lua_toboolean(L, arg - 1); \
			name = &(i_##name##_value); \
		} \
			}

#define OPTIONAL_BOOL_ARG(name, otherwise) \
	bool name = otherwise; \
	if (arg <= max_args) { \
		name = (bool)lua_toboolean(L, arg++); \
			}

#define DEFAULT_ARG(type, name, value) \
	type name = value; \

#define BOOL_ARG(name) \
	bool name = (bool)lua_toboolean(L, arg++);

#define CALL_FUNCTION(name, retType,...) \
	retType ret = ImGui::name(__VA_ARGS__);

#define CALL_FUNCTION_NO_RET(name, ...) \
	ImGui::name(__VA_ARGS__);
    
#define DRAW_LIST_CALL_FUNCTION_NO_RET(name, ...) \
    draw_list->name(__VA_ARGS__);

#define PUSH_NUMBER(name) \
	if (!g_returnValueLast) { \
		lua_pushnumber(L, name); \
		stackval++; \
			}

#define PUSH_STRING(name) \
	if (!g_returnValueLast) { \
		lua_pushstring(L, name); \
		stackval++; \
			}

#define PUSH_BOOL(name) \
	if (!g_returnValueLast) { \
		lua_pushboolean(L, (int) name); \
		stackval++; \
			}

#define PUSH_LAST_NUMBER(name) \
	if (g_returnValueLast) { \
		lua_pushnumber(L, name); \
		stackval++; \
			}

#define PUSH_LAST_STRING(name) \
	if (g_returnValueLast) { \
		lua_pushstring(L, name); \
		stackval++; \
			}

#define PUSH_LAST_BOOL(name) \
	if (g_returnValueLast) { \
		lua_pushboolean(L, (int) name); \
		stackval++; \
			}

#define END_BOOL_POINTER(name) \
	if (name != NULL) { \
		lua_pushboolean(L, (int)i_##name##_value); \
		stackval++; \
			}

#define END_IMGUI_FUNC \
	return stackval; \
}

#ifdef ENABLE_IM_LUA_END_STACK
#define IF_RET_ADD_END_STACK(type) \
	if (ret) { \
		AddToStack(type); \
			}

#define ADD_END_STACK(type) \
	AddToStack(type);

#define POP_END_STACK(type) \
	PopEndStack(type);

#define END_STACK_START \
static void ImEndStack(int type) { \
	switch(type) {

#define END_STACK_OPTION(type, function) \
		case type: \
			ImGui::function(); \
			break;

#define END_STACK_END \
		} \
}
#else
#define END_STACK_START
#define END_STACK_OPTION(type, function)
#define END_STACK_END
#define IF_RET_ADD_END_STACK(type)
#define ADD_END_STACK(type)
#define POP_END_STACK(type)
#endif

#include "imgui_iterator.h"
#include "imgui_iterator_custom.h"
#include "imgui_drawlist_iterator.h"

/*
** Hand made overrides
*/

static int w_Value(lua_State *L)
{
	if (lua_isboolean(L, 2))
	{
		return impl_Value(L);
	}
	return impl_Value_4(L);
}

static int w_CollapsingHeader(lua_State *L)
{
	if (lua_isboolean(L, 2))
	{
		return impl_CollapsingHeader_2(L);
	}
	return impl_CollapsingHeader(L);
}

static int w_Combo(lua_State *L)
{
	if (lua_isstring(L, 3))
	{
		return impl_Combo_2(L);
	}
	return impl_Combo(L);
}

static int w_RadioButton(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_RadioButton_2(L);
	}
	return impl_RadioButton(L);
}

static int w_PushID(lua_State *L)
{
	if (lua_gettop(L) > 1)
	{
		return impl_PushID_2(L);
	}
	return impl_PushID(L);
}

static int w_GetID(lua_State *L)
{
	if (lua_gettop(L) > 1)
	{
		return impl_GetID_2(L);
	}
	return impl_GetID(L);
}

static int w_PushStyleVar(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_PushStyleVar_2(L);
	}
	return impl_PushStyleVar(L);
}

static int w_PushStyleColor(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_PushStyleColor_2(L);
	}
	return impl_PushStyleColor(L);
}

static int w_SetWindowPos(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowPos_2(L);
	}
	return impl_SetWindowPos(L);
}

static int w_SetWindowSize(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowSize_2(L);
	}
	return impl_SetWindowSize(L);
}

static int w_SetWindowCollapsed(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowCollapsed_2(L);
	}
	return impl_SetWindowCollapsed(L);
}

static int w_SetWindowFocus(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowFocus_2(L);
	}
	return impl_SetWindowFocus(L);
}

static int w_BeginChild(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_BeginChild(L);
	}
	return impl_BeginChild_2(L);
}

static int w_IsRectVisible(lua_State *L)
{
    if (lua_gettop(L) > 2) 
    {
        return impl_IsRectVisible_2(L);
    }
    
    return impl_IsRectVisible(L);
}

static int w_GetColorU32(lua_State *L)
{
    if (lua_gettop(L) > 2)
    {
        return impl_GetColorU32_2(L);
    }
    return impl_GetColorU32(L);
}

/*
** Reg
*/

static const struct luaL_Reg imguilib[] = {
#undef IMGUI_FUNCTION
#define IMGUI_FUNCTION(name) {#name, impl_##name},
	// These defines are just redefining everything to nothing so
	// we can get the function names
#undef IMGUI_FUNCTION_DRAW_LIST
#define IMGUI_FUNCTION_DRAW_LIST(name) {#name, impl_##name},
#undef DEFAULT_ARG
#define DEFAULT_ARG(type, name, value)
#undef TEXTURE_ARG
#define TEXTURE_ARG(name)
#undef OPTIONAL_LABEL_ARG
#define OPTIONAL_LABEL_ARG(name, value)
#undef LABEL_ARG
#define LABEL_ARG(name)
#undef LABEL_POINTER_ARG
#define LABEL_POINTER_ARG(name)
#undef END_LABEL_POINTER
#define END_LABEL_POINTER(name)
#undef LABEL_ARRAY_ARG
#define LABEL_ARRAY_ARG(name)
#undef IM_VEC_2_ARG
#define IM_VEC_2_ARG(name)
#undef OPTIONAL_IM_VEC_2_ARG
#define OPTIONAL_IM_VEC_2_ARG(name, x, y)
#undef IM_VEC_2_ARRAY_ARG
#define IM_VEC_2_ARRAY_ARG(name)
#undef IM_VEC_4_ARG
#define IM_VEC_4_ARG(name)
#undef OPTIONAL_IM_VEC_4_ARG
#define OPTIONAL_IM_VEC_4_ARG(name, x, y, z, w)
#undef NUMBER_ARG
#define NUMBER_ARG(name)
#undef OPTIONAL_NUMBER_ARG
#define OPTIONAL_NUMBER_ARG(name, otherwise)
#undef FLOAT_POINTER_ARG
#define FLOAT_POINTER_ARG(name)
#undef END_FLOAT_POINTER
#define END_FLOAT_POINTER(name)
#undef FLOAT_ARRAY_ARG
#define FLOAT_ARRAY_ARG(name)
#undef FLOAT_ARRAY2_ARG
#define FLOAT_ARRAY2_ARG(name)
#undef END_FLOAT_ARRAY2
#define END_FLOAT_ARRAY2(name)
#undef FLOAT_ARRAY3_ARG
#define FLOAT_ARRAY3_ARG(name)
#undef END_FLOAT_ARRAY3
#define END_FLOAT_ARRAY3(name)
#undef FLOAT_ARRAY4_ARG
#define FLOAT_ARRAY4_ARG(name)
#undef END_FLOAT_ARRAY4
#define END_FLOAT_ARRAY4(name)
#undef INT_ARRAY2_ARG
#define INT_ARRAY2_ARG(name)
#undef END_INT_ARRAY2
#define END_INT_ARRAY2(name)
#undef INT_ARRAY3_ARG
#define INT_ARRAY3_ARG(name)
#undef END_INT_ARRAY3
#define END_INT_ARRAY3(name)
#undef INT_ARRAY4_ARG
#define INT_ARRAY4_ARG(name)
#undef END_INT_ARRAY4
#define END_INT_ARRAY4(name)
#undef OPTIONAL_INT_ARG
#define OPTIONAL_INT_ARG(name, otherwise)
#undef INT_ARG
#define INT_ARG(name)
#undef OPTIONAL_ENUM_ARG
#define OPTIONAL_ENUM_ARG(name, otherwise)
#undef ENUM_ARG
#define ENUM_ARG(name)
#undef OPTIONAL_UINT_ARG
#define OPTIONAL_UINT_ARG(name, otherwise)
#undef UINT_ARG
#define UINT_ARG(name)
#undef INT_POINTER_ARG
#define INT_POINTER_ARG(name)
#undef END_INT_POINTER
#define END_INT_POINTER(name)
#undef INT_CURRENT_ITEM_POINTER_ARG
#define INT_CURRENT_ITEM_POINTER_ARG(name)
#undef END_INT_CURRENT_ITEM_POINTER
#define END_INT_CURRENT_ITEM_POINTER(name)
#undef UINT_POINTER_ARG
#define UINT_POINTER_ARG(name)
#undef END_UINT_POINTER
#define END_UINT_POINTER(name)
#undef BOOL_POINTER_ARG
#define BOOL_POINTER_ARG(name)
#undef OPTIONAL_BOOL_POINTER_ARG
#define OPTIONAL_BOOL_POINTER_ARG(name)
#undef OPTIONAL_BOOL_ARG
#define OPTIONAL_BOOL_ARG(name, otherwise)
#undef BOOL_ARG
#define BOOL_ARG(name)
#undef CALL_FUNCTION
#define CALL_FUNCTION(name, retType, ...)
#undef CALL_FUNCTION_NO_RET
#define CALL_FUNCTION_NO_RET(name, ...)
#undef DRAW_LIST_CALL_FUNCTION_NO_RET
#define DRAW_LIST_CALL_FUNCTION_NO_RET(name, ...)
#undef PUSH_NUMBER
#define PUSH_NUMBER(name)
#undef PUSH_BOOL
#define PUSH_BOOL(name)
#undef PUSH_STRING
#define PUSH_STRING(name)
#undef PUSH_LAST_NUMBER
#define PUSH_LAST_NUMBER(name)
#undef PUSH_LAST_BOOL
#define PUSH_LAST_BOOL(name)
#undef PUSH_LAST_STRING
#define PUSH_LAST_STRING(name)
#undef END_BOOL_POINTER
#define END_BOOL_POINTER(name)
#undef END_IMGUI_FUNC
#define END_IMGUI_FUNC
#undef END_STACK_START
#define END_STACK_START
#undef END_STACK_OPTION
#define END_STACK_OPTION(type, function)
#undef END_STACK_END
#define END_STACK_END
#undef IF_RET_ADD_END_STACK
#define IF_RET_ADD_END_STACK(type)
#undef ADD_END_STACK
#define ADD_END_STACK(type)
#undef POP_END_STACK
#define POP_END_STACK(type)

#include "imgui_iterator.h"
#include "imgui_iterator_custom.h"
#include "imgui_drawlist_iterator.h"

	// Custom
{ "GetStyleColName", w_GetStyleColorName },
{ "GetStyleColCount", w_GetStyleColCount },
{ "AddFontDefault", w_AddFontDefault },
{ "AddFontFromFileTTF", w_AddFontFromFileTTF },

// Overrides
{ "Value", w_Value },
{ "CollapsingHeader", w_CollapsingHeader },
{ "Combo", w_Combo },
{ "RadioButton", w_RadioButton },
{ "PushID", w_PushID },
{ "GetID", w_GetID },
{ "PushStyleVar", w_PushStyleVar },
{ "PushStyleColor", w_PushStyleColor },
{ "SetWindowPos", w_SetWindowPos },
{ "SetWindowSize", w_SetWindowSize },
{ "SetWindowCollapsed", w_SetWindowCollapsed },
{ "SetWindowFocus", w_SetWindowFocus },
{ "BeginChild", w_BeginChild },
{ "IsRectVisible", w_IsRectVisible },
{ "GetColorU32", w_GetColorU32 },

// functions that may need custom overrides
// ListBoxHeader

// Implementation
{ "Init", w_Init},
{ "ShutDown", w_ShutDown },
{ "NewFrame", w_NewFrame },
{ "MouseMoved", w_MouseMoved },
{ "MousePressed", w_MousePressed },
{ "MouseReleased", w_MouseReleased },
{ "WheelMoved", w_WheelMoved },
{ "KeyPressed", w_KeyPressed },
{ "KeyReleased", w_KeyReleased },
{ "TextInput", w_TextInput },
{ "GetWantCaptureKeyboard", w_GetWantCaptureKeyboard },
{ "GetWantCaptureMouse", w_GetWantCaptureMouse },
{ "GetWantTextInput", w_GetWantTextInput },

// Return value ordering
{ "SetReturnValueLast", w_SetReturnValueLast },

{ NULL, NULL }
};

#define MAKE_ENUM(name) \
  lua_pushlstring(L, #name, sizeof(#name)-1); \
  lua_pushnumber(L, name); \
  lua_settable(L, -3);

extern "C" LOVE_IMGUI_EXPORT int luaopen_imgui(lua_State *L)
{
    
	lua_newtable(L);
    #include "imgui_enum.h"

	//luaL_openlib(L, NULL, imguilib, 1);
	//luaL_register(L, nullptr, imguilib);
	// Had to register functions manually
	int tabTop = lua_gettop(L);
	for (const luaL_Reg *l = imguilib; l->name; l++)
	{
		lua_pushstring(L, l->name);
		lua_pushvalue(L, tabTop);
		lua_pushcclosure(L, l->func, 1);
		lua_rawset(L, tabTop);
	}

	// require love
	lua_pushstring(L, "require");
	lua_rawget(L, LUA_GLOBALSINDEX);
	lua_pushstring(L, "love");
	lua_call(L, 1, 1);

	// Check love.graphics presence (love is at -1)
	// FIXME: Do this as early as possible, but I don't want to break stuff
	lua_pushstring(L, "graphics");
	lua_rawget(L, -2);
	if (lua_isnil(L, -1))
		return luaL_error(L, "love-imgui requires love.graphics to function");
	lua_pop(L, 1);

	// initialize dostring cache
	// imgui is at -2, love is at -1
	DoStringCache::init(L, "love-imgui");
	lua_pop(L, 1); // remove "love" table
	
	ImGui::CreateContext();



	return 1;
}
