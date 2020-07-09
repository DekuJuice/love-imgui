CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

IF(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
	# Protip: run cmake like this: cmake -Bbuild -H. or see the readme
	message(FATAL_ERROR "Prevented in-tree build.")
endif()

PROJECT(love-imgui)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(LuaJIT)
IF(NOT LUAJIT_FOUND)
	FIND_PACKAGE(Lua 5.1 EXACT REQUIRED)
	SET(DESIRED_LUA_INCLUDE_DIR ${LUA_INCLUDE_DIR})
	SET(DESIRED_LUA_LIBRARY ${LUA_LIBRARIES})
ELSE()
	SET(DESIRED_LUA_INCLUDE_DIR ${LUAJIT_INCLUDE_DIR})
	SET(DESIRED_LUA_LIBRARY ${LUAJIT_LIBRARY})
ENDIF()

ADD_LIBRARY(love-imgui
	SHARED
	src/imgui/imconfig.h
	src/imgui/imgui.cpp
	src/imgui/imgui.h
	src/imgui/imgui_draw.cpp
	src/imgui/imgui_demo.cpp
	src/imgui/imgui_widgets.cpp
	src/imgui/imgui_internal.h
	src/imgui/imstb_rectpack.h
	src/imgui/imstb_textedit.h
	src/imgui/imstb_truetype.h
	src/imgui_impl.cpp
	src/wrap_imgui_impl.cpp
	src/imgui_impl.h
	src/wrap_imgui_impl.h
	src/imgui_iterator.h
	src/dostring_cache.cpp
)

TARGET_INCLUDE_DIRECTORIES(love-imgui
	PUBLIC
	${DESIRED_LUA_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(love-imgui
	${DESIRED_LUA_LIBRARY}
)

SET_TARGET_PROPERTIES(love-imgui PROPERTIES PREFIX "" OUTPUT_NAME "imgui")

INSTALL(TARGETS love-imgui DESTINATION lib)
