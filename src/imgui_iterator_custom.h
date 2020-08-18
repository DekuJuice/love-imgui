// Custom iterator macros for otherwise unsupported functions, such as those with varargs

//    IMGUI_API void          Text(const char* fmt, ...); // simple formatted text
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(Text)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(Text, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          TextColored(const ImVec4& col, const char* fmt, ...); // shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor();
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextColored)
IM_VEC_4_ARG(col)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextColored, col, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          TextDisabled(const char* fmt, ...); // shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor();
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextDisabled)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextDisabled, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          TextWrapped(const char* fmt, ...); // shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(TextWrapped)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(TextWrapped, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          LabelText(const char* label, const char* fmt, ...); // display text+label aligned the same way as value+label widgets
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(LabelText)
LABEL_ARG(label)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(LabelText, label, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          BulletText(const char* fmt, ...); // shortcut for Bullet()+Text()
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(BulletText)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(BulletText, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          SetTooltip(const char* fmt, ...);                     // set text tooltip under mouse-cursor, typically use with ImGui::IsItemHovered(). overidde any previous call to SetTooltip().
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(SetTooltip)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(SetTooltip, fmt)
END_IMGUI_FUNC

//    IMGUI_API void          LogText(const char* fmt, ...);                        // pass text data straight to log (without being displayed)
// Variadic functions aren't suppported but here it is anyway
IMGUI_FUNCTION(LogText)
LABEL_ARG(fmt)
CALL_FUNCTION_NO_RET(LogText, fmt)
END_IMGUI_FUNC

// LABEL_POINTER_ARG implicitely creates a buf_size arg
//    IMGUI_API bool          InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_FUNCTION(InputText)
LABEL_ARG(label)
LABEL_POINTER_ARG(buf)
OPTIONAL_ENUM_ARG(flags, 0)
DEFAULT_ARG(ImGuiInputTextCallback, callback, NULL)
DEFAULT_ARG(void*, user_data, NULL)
CALL_FUNCTION(InputText, bool, label, buf, buf_size, flags)
PUSH_BOOL(ret)
END_LABEL_POINTER(buf)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2 0  0, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_FUNCTION(InputTextMultiline)
LABEL_ARG(label)
LABEL_POINTER_ARG(buf)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_ENUM_ARG(flags, 0)
DEFAULT_ARG(ImGuiInputTextCallback, callback, NULL)
DEFAULT_ARG(void*, user_data, NULL)
CALL_FUNCTION(InputTextMultiline, bool, label, buf, buf_size, size, flags)
PUSH_BOOL(ret)
END_LABEL_POINTER(buf)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
IMGUI_FUNCTION(InputTextWithHint)
LABEL_ARG(label)
LABEL_ARG(hint)
LABEL_POINTER_ARG(buf)
OPTIONAL_ENUM_ARG(flags, 0)
DEFAULT_ARG(ImGuiInputTextCallback, callback, NULL)
DEFAULT_ARG(void*, user_data, NULL)
CALL_FUNCTION(InputTextWithHint, bool, label, hint, buf, buf_size, flags)
PUSH_BOOL(ret)
END_LABEL_POINTER(buf)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC
