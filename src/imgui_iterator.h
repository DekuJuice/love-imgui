//namespace ImGui

//    IMGUI_API ImGuiContext* CreateContext(ImFontAtlas* shared_font_atlas = NULL);
// Unsupported return type ImGuiContext*
//    IMGUI_API void          DestroyContext(ImGuiContext* ctx = NULL);   // NULL = destroy current context
IMGUI_FUNCTION(DestroyContext)
DEFAULT_ARG(ImGuiContext*, ctx, NULL)
CALL_FUNCTION_NO_RET(DestroyContext)
END_IMGUI_FUNC

//    IMGUI_API ImGuiContext* GetCurrentContext();
// Unsupported return type ImGuiContext*
//    IMGUI_API void          SetCurrentContext(ImGuiContext* ctx);
// Unsupported arg type ImGuiContext* ctx
//    IMGUI_API ImGuiIO&      GetIO();                                    // access the IO structure (mouse/keyboard/gamepad inputs, time, various configuration options/flags)
// Unsupported return type ImGuiIO&
//    IMGUI_API ImGuiStyle&   GetStyle();                                 // access the Style structure (colors, sizes). Always use PushStyleCol(), PushStyleVar() to modify style mid-frame!
// Unsupported return type ImGuiStyle&
//    IMGUI_API void          NewFrame();                                 // start a new Dear ImGui frame, you can submit any command from this point until Render()/EndFrame().
//Not allowed to use this function
//    IMGUI_API void          EndFrame();                                 // ends the Dear ImGui frame. automatically called by Render(). If you don't need to render data (skipping rendering) you may call EndFrame() without Render()... but you'll have wasted CPU already! If you don't need to render, better to not create any windows and not call NewFrame() at all!
IMGUI_FUNCTION(EndFrame)
CALL_FUNCTION_NO_RET(EndFrame)
POP_END_STACK(0)
END_IMGUI_FUNC

//    IMGUI_API void          Render();                                   // ends the Dear ImGui frame, finalize the draw data. You can get call GetDrawData() to obtain it and run your rendering function (up to v1.60, this used to call io.RenderDrawListsFn(). Nowadays, we allow and prefer calling your render function yourself.)
IMGUI_FUNCTION(Render)
CALL_FUNCTION_NO_RET(Render)
END_IMGUI_FUNC

//    IMGUI_API ImDrawData*   GetDrawData();                              // valid after Render() and until the next call to NewFrame(). this is what you have to render.
// Unsupported return type ImDrawData*
//    IMGUI_API void          ShowDemoWindow(bool* p_open = NULL);        // create Demo window (previously called ShowTestWindow). demonstrate most ImGui features. call this to learn about the library! try to make it always available in your application!
IMGUI_FUNCTION(ShowDemoWindow)
OPTIONAL_BOOL_POINTER_ARG(p_open)
CALL_FUNCTION_NO_RET(ShowDemoWindow, p_open)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC

//    IMGUI_API void          ShowAboutWindow(bool* p_open = NULL);       // create About window. display Dear ImGui version, credits and build/system information.
IMGUI_FUNCTION(ShowAboutWindow)
OPTIONAL_BOOL_POINTER_ARG(p_open)
CALL_FUNCTION_NO_RET(ShowAboutWindow, p_open)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC

//    IMGUI_API void          ShowMetricsWindow(bool* p_open = NULL);     // create Debug/Metrics window. display Dear ImGui internals: draw commands (with individual draw calls and vertices), window list, basic internal state, etc.
IMGUI_FUNCTION(ShowMetricsWindow)
OPTIONAL_BOOL_POINTER_ARG(p_open)
CALL_FUNCTION_NO_RET(ShowMetricsWindow, p_open)
END_BOOL_POINTER(p_open)
END_IMGUI_FUNC

//    IMGUI_API void          ShowStyleEditor(ImGuiStyle* ref = NULL);    // add style editor block (not a window). you can pass in a reference ImGuiStyle structure to compare to, revert to and save to (else it uses the default style)
IMGUI_FUNCTION(ShowStyleEditor)
DEFAULT_ARG(ImGuiStyle*, ref, NULL)
CALL_FUNCTION_NO_RET(ShowStyleEditor)
END_IMGUI_FUNC

//    IMGUI_API bool          ShowStyleSelector(const char* label);       // add style selector block (not a window), essentially a combo listing the default styles.
IMGUI_FUNCTION(ShowStyleSelector)
LABEL_ARG(label)
CALL_FUNCTION(ShowStyleSelector, bool, label)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          ShowFontSelector(const char* label);        // add font selector block (not a window), essentially a combo listing the loaded fonts.
IMGUI_FUNCTION(ShowFontSelector)
LABEL_ARG(label)
CALL_FUNCTION_NO_RET(ShowFontSelector, label)
END_IMGUI_FUNC

//    IMGUI_API void          ShowUserGuide();                            // add basic help/info block (not a window): how to manipulate ImGui as a end-user (mouse/keyboard controls).
IMGUI_FUNCTION(ShowUserGuide)
CALL_FUNCTION_NO_RET(ShowUserGuide)
END_IMGUI_FUNC

//    IMGUI_API const char*   GetVersion();                               // get the compiled version string e.g. "1.23" (essentially the compiled value for IMGUI_VERSION)
IMGUI_FUNCTION(GetVersion)
CALL_FUNCTION(GetVersion, const char*)
PUSH_STRING(ret)
PUSH_LAST_STRING(ret)
END_IMGUI_FUNC

//    IMGUI_API void          StyleColorsDark(ImGuiStyle* dst = NULL);    // new, recommended style (default)
IMGUI_FUNCTION(StyleColorsDark)
DEFAULT_ARG(ImGuiStyle*, dst, NULL)
CALL_FUNCTION_NO_RET(StyleColorsDark)
END_IMGUI_FUNC

//    IMGUI_API void          StyleColorsClassic(ImGuiStyle* dst = NULL); // classic imgui style
IMGUI_FUNCTION(StyleColorsClassic)
DEFAULT_ARG(ImGuiStyle*, dst, NULL)
CALL_FUNCTION_NO_RET(StyleColorsClassic)
END_IMGUI_FUNC

//    IMGUI_API void          StyleColorsLight(ImGuiStyle* dst = NULL);   // best used with borders and a custom, thicker font
IMGUI_FUNCTION(StyleColorsLight)
DEFAULT_ARG(ImGuiStyle*, dst, NULL)
CALL_FUNCTION_NO_RET(StyleColorsLight)
END_IMGUI_FUNC

//    IMGUI_API bool          Begin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0);
IMGUI_FUNCTION(Begin)
LABEL_ARG(name)
OPTIONAL_BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(Begin, bool, name, p_open, flags)
IF_RET_ADD_END_STACK(1)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          End();
IMGUI_FUNCTION(End)
CALL_FUNCTION_NO_RET(End)
POP_END_STACK(1)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginChild(const char* str_id, const ImVec2& size = ImVec2 0  0, bool border = false, ImGuiWindowFlags flags = 0);
IMGUI_FUNCTION(BeginChild)
LABEL_ARG(str_id)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_BOOL_ARG(border, false)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginChild, bool, str_id, size, border, flags)
IF_RET_ADD_END_STACK(2)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginChild(ImGuiID id, const ImVec2& size = ImVec2 0  0, bool border = false, ImGuiWindowFlags flags = 0);
IMGUI_FUNCTION(BeginChild_2)
UINT_ARG(id)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
OPTIONAL_BOOL_ARG(border, false)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginChild, bool, id, size, border, flags)
IF_RET_ADD_END_STACK(2)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndChild();
IMGUI_FUNCTION(EndChild)
CALL_FUNCTION_NO_RET(EndChild)
POP_END_STACK(2)
END_IMGUI_FUNC

//    IMGUI_API bool          IsWindowAppearing();
IMGUI_FUNCTION(IsWindowAppearing)
CALL_FUNCTION(IsWindowAppearing, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsWindowCollapsed();
IMGUI_FUNCTION(IsWindowCollapsed)
CALL_FUNCTION(IsWindowCollapsed, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsWindowFocused(ImGuiFocusedFlags flags=0); // is current window focused? or its root/child, depending on flags. see flags for options.
IMGUI_FUNCTION(IsWindowFocused)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(IsWindowFocused, bool, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsWindowHovered(ImGuiHoveredFlags flags=0); // is current window hovered (and typically: not blocked by a popup/modal)? see flags for options. NB: If you are trying to check whether your mouse should be dispatched to imgui or to your app, you should use the 'io.WantCaptureMouse' boolean for that! Please read the FAQ!
IMGUI_FUNCTION(IsWindowHovered)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(IsWindowHovered, bool, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API ImDrawList*   GetWindowDrawList();                        // get draw list associated to the current window, to append your own drawing primitives
// Unsupported return type ImDrawList*
//    IMGUI_API float         GetWindowDpiScale();                        // get DPI scale currently associated to the current window's viewport.
IMGUI_FUNCTION(GetWindowDpiScale)
CALL_FUNCTION(GetWindowDpiScale, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImGuiViewport*GetWindowViewport();                        // get viewport currently associated to the current window.
// Unsupported return type ImGuiViewport*GetWindowViewpor
//    IMGUI_API ImVec2        GetWindowPos();                             // get current window position in screen space (useful if you want to do your own drawing via the DrawList API)
IMGUI_FUNCTION(GetWindowPos)
CALL_FUNCTION(GetWindowPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetWindowSize();                            // get current window size
IMGUI_FUNCTION(GetWindowSize)
CALL_FUNCTION(GetWindowSize, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API float         GetWindowWidth();                           // get current window width (shortcut for GetWindowSize().x)
IMGUI_FUNCTION(GetWindowWidth)
CALL_FUNCTION(GetWindowWidth, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetWindowHeight();                          // get current window height (shortcut for GetWindowSize().y)
IMGUI_FUNCTION(GetWindowHeight)
CALL_FUNCTION(GetWindowHeight, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowPos(const ImVec2& pos, ImGuiCond cond = 0, const ImVec2& pivot = ImVec2 0  0); // set next window position. call before Begin(). use pivot=(0.5f,0.5f) to center on given point, etc.
IMGUI_FUNCTION(SetNextWindowPos)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
OPTIONAL_IM_VEC_2_ARG(pivot, 0, 0)
CALL_FUNCTION_NO_RET(SetNextWindowPos, pos, cond, pivot)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowSize(const ImVec2& size, ImGuiCond cond = 0);                  // set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin()
IMGUI_FUNCTION(SetNextWindowSize)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowSize, size, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max, ImGuiSizeCallback custom_callback = NULL, void* custom_callback_data = NULL); // set next window size limits. use -1,-1 on either X/Y axis to preserve the current size. Sizes will be rounded down. Use callback to apply non-trivial programmatic constraints.
IMGUI_FUNCTION(SetNextWindowSizeConstraints)
IM_VEC_2_ARG(size_min)
IM_VEC_2_ARG(size_max)
DEFAULT_ARG(ImGuiSizeCallback, custom_callback, NULL)
DEFAULT_ARG(void*, custom_callback_data, NULL)
CALL_FUNCTION_NO_RET(SetNextWindowSizeConstraints, size_min, size_max)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowContentSize(const ImVec2& size);                               // set next window content size (~ scrollable client area, which enforce the range of scrollbars). Not including window decorations (title bar, menu bar, etc.) nor WindowPadding. set an axis to 0.0f to leave it automatic. call before Begin()
IMGUI_FUNCTION(SetNextWindowContentSize)
IM_VEC_2_ARG(size)
CALL_FUNCTION_NO_RET(SetNextWindowContentSize, size)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowCollapsed(bool collapsed, ImGuiCond cond = 0);                 // set next window collapsed state. call before Begin()
IMGUI_FUNCTION(SetNextWindowCollapsed)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowCollapsed, collapsed, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowFocus();                                                       // set next window to be focused / top-most. call before Begin()
IMGUI_FUNCTION(SetNextWindowFocus)
CALL_FUNCTION_NO_RET(SetNextWindowFocus)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowBgAlpha(float alpha);                                          // set next window background color alpha. helper to easily override the Alpha component of ImGuiCol_WindowBg/ChildBg/PopupBg. you may also use ImGuiWindowFlags_NoBackground.
IMGUI_FUNCTION(SetNextWindowBgAlpha)
NUMBER_ARG(alpha)
CALL_FUNCTION_NO_RET(SetNextWindowBgAlpha, alpha)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowViewport(ImGuiID viewport_id);                                 // set next window viewport
IMGUI_FUNCTION(SetNextWindowViewport)
UINT_ARG(viewport_id)
CALL_FUNCTION_NO_RET(SetNextWindowViewport, viewport_id)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowPos(const ImVec2& pos, ImGuiCond cond = 0);                        // (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects.
IMGUI_FUNCTION(SetWindowPos)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowPos, pos, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowSize(const ImVec2& size, ImGuiCond cond = 0);                      // (not recommended) set current window size - call within Begin()/End(). set to ImVec2 0  0 to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects.
IMGUI_FUNCTION(SetWindowSize)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowSize, size, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowCollapsed(bool collapsed, ImGuiCond cond = 0);                     // (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed().
IMGUI_FUNCTION(SetWindowCollapsed)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowCollapsed, collapsed, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowFocus();                                                           // (not recommended) set current window to be focused / top-most. prefer using SetNextWindowFocus().
IMGUI_FUNCTION(SetWindowFocus)
CALL_FUNCTION_NO_RET(SetWindowFocus)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowFontScale(float scale);                                            // set font scale. Adjust IO.FontGlobalScale if you want to scale all windows. This is an old API! For correct scaling, prefer to reload font + rebuild ImFontAtlas + call style.ScaleAllSizes().
IMGUI_FUNCTION(SetWindowFontScale)
NUMBER_ARG(scale)
CALL_FUNCTION_NO_RET(SetWindowFontScale, scale)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowPos(const char* name, const ImVec2& pos, ImGuiCond cond = 0);      // set named window position.
IMGUI_FUNCTION(SetWindowPos_2)
LABEL_ARG(name)
IM_VEC_2_ARG(pos)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowPos, name, pos, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowSize(const char* name, const ImVec2& size, ImGuiCond cond = 0);    // set named window size. set axis to 0.0f to force an auto-fit on this axis.
IMGUI_FUNCTION(SetWindowSize_2)
LABEL_ARG(name)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowSize, name, size, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond = 0);   // set named window collapsed state
IMGUI_FUNCTION(SetWindowCollapsed_2)
LABEL_ARG(name)
BOOL_ARG(collapsed)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetWindowCollapsed, name, collapsed, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetWindowFocus(const char* name);                                           // set named window to be focused / top-most. use NULL to remove focus.
IMGUI_FUNCTION(SetWindowFocus_2)
LABEL_ARG(name)
CALL_FUNCTION_NO_RET(SetWindowFocus, name)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetContentRegionMax();                                          // current content boundaries (typically window boundaries including scrolling, or current column boundaries), in windows coordinates
IMGUI_FUNCTION(GetContentRegionMax)
CALL_FUNCTION(GetContentRegionMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetContentRegionAvail();                                        // == GetContentRegionMax() - GetCursorPos()
IMGUI_FUNCTION(GetContentRegionAvail)
CALL_FUNCTION(GetContentRegionAvail, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetWindowContentRegionMin();                                    // content boundaries min (roughly (0,0)-Scroll), in window coordinates
IMGUI_FUNCTION(GetWindowContentRegionMin)
CALL_FUNCTION(GetWindowContentRegionMin, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetWindowContentRegionMax();                                    // content boundaries max (roughly (0,0)+Size-Scroll) where Size can be override with SetNextWindowContentSize(), in window coordinates
IMGUI_FUNCTION(GetWindowContentRegionMax)
CALL_FUNCTION(GetWindowContentRegionMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API float         GetWindowContentRegionWidth();                                  //
IMGUI_FUNCTION(GetWindowContentRegionWidth)
CALL_FUNCTION(GetWindowContentRegionWidth, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetScrollX();                                                   // get scrolling amount [0..GetScrollMaxX()]
IMGUI_FUNCTION(GetScrollX)
CALL_FUNCTION(GetScrollX, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetScrollY();                                                   // get scrolling amount [0..GetScrollMaxY()]
IMGUI_FUNCTION(GetScrollY)
CALL_FUNCTION(GetScrollY, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetScrollMaxX();                                                // get maximum scrolling amount ~~ ContentSize.X - WindowSize.X
IMGUI_FUNCTION(GetScrollMaxX)
CALL_FUNCTION(GetScrollMaxX, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetScrollMaxY();                                                // get maximum scrolling amount ~~ ContentSize.Y - WindowSize.Y
IMGUI_FUNCTION(GetScrollMaxY)
CALL_FUNCTION(GetScrollMaxY, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollX(float scroll_x);                                     // set scrolling amount [0..GetScrollMaxX()]
IMGUI_FUNCTION(SetScrollX)
NUMBER_ARG(scroll_x)
CALL_FUNCTION_NO_RET(SetScrollX, scroll_x)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollY(float scroll_y);                                     // set scrolling amount [0..GetScrollMaxY()]
IMGUI_FUNCTION(SetScrollY)
NUMBER_ARG(scroll_y)
CALL_FUNCTION_NO_RET(SetScrollY, scroll_y)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollHereX(float center_x_ratio = 0.5f);                    // adjust scrolling amount to make current cursor position visible. center_x_ratio=0.0: left, 0.5: center, 1.0: right. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead.
IMGUI_FUNCTION(SetScrollHereX)
OPTIONAL_NUMBER_ARG(center_x_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollHereX, center_x_ratio)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollHereY(float center_y_ratio = 0.5f);                    // adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead.
IMGUI_FUNCTION(SetScrollHereY)
OPTIONAL_NUMBER_ARG(center_y_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollHereY, center_y_ratio)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollFromPosX(float local_x, float center_x_ratio = 0.5f);  // adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position.
IMGUI_FUNCTION(SetScrollFromPosX)
NUMBER_ARG(local_x)
OPTIONAL_NUMBER_ARG(center_x_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollFromPosX, local_x, center_x_ratio)
END_IMGUI_FUNC

//    IMGUI_API void          SetScrollFromPosY(float local_y, float center_y_ratio = 0.5f);  // adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position.
IMGUI_FUNCTION(SetScrollFromPosY)
NUMBER_ARG(local_y)
OPTIONAL_NUMBER_ARG(center_y_ratio, 0.5f)
CALL_FUNCTION_NO_RET(SetScrollFromPosY, local_y, center_y_ratio)
END_IMGUI_FUNC

//    IMGUI_API void          PushFont(ImFont* font);                                         // use NULL as a shortcut to push default font
// Unsupported arg type ImFont* font
//    IMGUI_API void          PopFont();
IMGUI_FUNCTION(PopFont)
CALL_FUNCTION_NO_RET(PopFont)
END_IMGUI_FUNC

//    IMGUI_API void          PushStyleColor(ImGuiCol idx, ImU32 col);
IMGUI_FUNCTION(PushStyleColor)
ENUM_ARG(idx)
UINT_ARG(col)
CALL_FUNCTION_NO_RET(PushStyleColor, idx, col)
END_IMGUI_FUNC

//    IMGUI_API void          PushStyleColor(ImGuiCol idx, const ImVec4& col);
IMGUI_FUNCTION(PushStyleColor_2)
ENUM_ARG(idx)
IM_VEC_4_ARG(col)
CALL_FUNCTION_NO_RET(PushStyleColor, idx, col)
END_IMGUI_FUNC

//    IMGUI_API void          PopStyleColor(int count = 1);
IMGUI_FUNCTION(PopStyleColor)
OPTIONAL_INT_ARG(count, 1)
CALL_FUNCTION_NO_RET(PopStyleColor, count)
END_IMGUI_FUNC

//    IMGUI_API void          PushStyleVar(ImGuiStyleVar idx, float val);
IMGUI_FUNCTION(PushStyleVar)
ENUM_ARG(idx)
NUMBER_ARG(val)
CALL_FUNCTION_NO_RET(PushStyleVar, idx, val)
ADD_END_STACK(3)
END_IMGUI_FUNC

//    IMGUI_API void          PushStyleVar(ImGuiStyleVar idx, const ImVec2& val);
IMGUI_FUNCTION(PushStyleVar_2)
ENUM_ARG(idx)
IM_VEC_2_ARG(val)
CALL_FUNCTION_NO_RET(PushStyleVar, idx, val)
ADD_END_STACK(3)
END_IMGUI_FUNC

//    IMGUI_API void          PopStyleVar(int count = 1);
IMGUI_FUNCTION(PopStyleVar)
OPTIONAL_INT_ARG(count, 1)
CALL_FUNCTION_NO_RET(PopStyleVar, count)
POP_END_STACK(3)
END_IMGUI_FUNC

//    IMGUI_API const ImVec4& GetStyleColorVec4(ImGuiCol idx);                                // retrieve style color as stored in ImGuiStyle structure. use to feed back into PushStyleColor(), otherwise use GetColorU32() to get style color with style alpha baked in.
// Unsupported return type const
//    IMGUI_API ImFont*       GetFont();                                                      // get current font
// Unsupported return type ImFont*
//    IMGUI_API float         GetFontSize();                                                  // get current font size (= height in pixels) of current font with current scale applied
IMGUI_FUNCTION(GetFontSize)
CALL_FUNCTION(GetFontSize, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetFontTexUvWhitePixel();                                       // get UV coordinate for a while pixel, useful to draw custom shapes via the ImDrawList API
IMGUI_FUNCTION(GetFontTexUvWhitePixel)
CALL_FUNCTION(GetFontTexUvWhitePixel, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImU32         GetColorU32(ImGuiCol idx, float alpha_mul = 1.0f);              // retrieve given style color with style alpha applied and optional extra alpha multiplier
IMGUI_FUNCTION(GetColorU32)
ENUM_ARG(idx)
OPTIONAL_NUMBER_ARG(alpha_mul, 1.0f)
CALL_FUNCTION(GetColorU32, unsigned int, idx, alpha_mul)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImU32         GetColorU32(const ImVec4& col);                                 // retrieve given color with style alpha applied
IMGUI_FUNCTION(GetColorU32_2)
IM_VEC_4_ARG(col)
CALL_FUNCTION(GetColorU32, unsigned int, col)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImU32         GetColorU32(ImU32 col);                                         // retrieve given color with style alpha applied
IMGUI_FUNCTION(GetColorU32_3)
UINT_ARG(col)
CALL_FUNCTION(GetColorU32, unsigned int, col)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          PushItemWidth(float item_width);                                // push width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width,
IMGUI_FUNCTION(PushItemWidth)
NUMBER_ARG(item_width)
CALL_FUNCTION_NO_RET(PushItemWidth, item_width)
END_IMGUI_FUNC

//    IMGUI_API void          PopItemWidth();
IMGUI_FUNCTION(PopItemWidth)
CALL_FUNCTION_NO_RET(PopItemWidth)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextItemWidth(float item_width);                             // set width of the _next_ common large "item+label" widget. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side)
IMGUI_FUNCTION(SetNextItemWidth)
NUMBER_ARG(item_width)
CALL_FUNCTION_NO_RET(SetNextItemWidth, item_width)
END_IMGUI_FUNC

//    IMGUI_API float         CalcItemWidth();                                                // width of item given pushed settings and current cursor position. NOT necessarily the width of last item unlike most 'Item' functions.
IMGUI_FUNCTION(CalcItemWidth)
CALL_FUNCTION(CalcItemWidth, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          PushTextWrapPos(float wrap_local_pos_x = 0.0f);                 // push word-wrapping position for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space
IMGUI_FUNCTION(PushTextWrapPos)
OPTIONAL_NUMBER_ARG(wrap_local_pos_x, 0.0f)
CALL_FUNCTION_NO_RET(PushTextWrapPos, wrap_local_pos_x)
END_IMGUI_FUNC

//    IMGUI_API void          PopTextWrapPos();
IMGUI_FUNCTION(PopTextWrapPos)
CALL_FUNCTION_NO_RET(PopTextWrapPos)
END_IMGUI_FUNC

//    IMGUI_API void          PushAllowKeyboardFocus(bool allow_keyboard_focus);              // allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets
IMGUI_FUNCTION(PushAllowKeyboardFocus)
BOOL_ARG(allow_keyboard_focus)
CALL_FUNCTION_NO_RET(PushAllowKeyboardFocus, allow_keyboard_focus)
END_IMGUI_FUNC

//    IMGUI_API void          PopAllowKeyboardFocus();
IMGUI_FUNCTION(PopAllowKeyboardFocus)
CALL_FUNCTION_NO_RET(PopAllowKeyboardFocus)
END_IMGUI_FUNC

//    IMGUI_API void          PushButtonRepeat(bool repeat);                                  // in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame.
IMGUI_FUNCTION(PushButtonRepeat)
BOOL_ARG(repeat)
CALL_FUNCTION_NO_RET(PushButtonRepeat, repeat)
END_IMGUI_FUNC

//    IMGUI_API void          PopButtonRepeat();
IMGUI_FUNCTION(PopButtonRepeat)
CALL_FUNCTION_NO_RET(PopButtonRepeat)
END_IMGUI_FUNC

//    IMGUI_API void          Separator();                                                    // separator, generally horizontal. inside a menu bar or in horizontal layout mode, this becomes a vertical separator.
IMGUI_FUNCTION(Separator)
CALL_FUNCTION_NO_RET(Separator)
END_IMGUI_FUNC

//    IMGUI_API void          SameLine(float offset_from_start_x=0.0f, float spacing=-1.0f);  // call between widgets or groups to layout them horizontally. X position given in window coordinates.
IMGUI_FUNCTION(SameLine)
OPTIONAL_NUMBER_ARG(offset_from_start_x, 0.0f)
OPTIONAL_NUMBER_ARG(spacing, -1.0f)
CALL_FUNCTION_NO_RET(SameLine, offset_from_start_x, spacing)
END_IMGUI_FUNC

//    IMGUI_API void          NewLine();                                                      // undo a SameLine() or force a new line when in an horizontal-layout context.
IMGUI_FUNCTION(NewLine)
CALL_FUNCTION_NO_RET(NewLine)
END_IMGUI_FUNC

//    IMGUI_API void          Spacing();                                                      // add vertical spacing.
IMGUI_FUNCTION(Spacing)
CALL_FUNCTION_NO_RET(Spacing)
END_IMGUI_FUNC

//    IMGUI_API void          Dummy(const ImVec2& size);                                      // add a dummy item of given size. unlike InvisibleButton(), Dummy() won't take the mouse click or be navigable into.
IMGUI_FUNCTION(Dummy)
IM_VEC_2_ARG(size)
CALL_FUNCTION_NO_RET(Dummy, size)
END_IMGUI_FUNC

//    IMGUI_API void          Indent(float indent_w = 0.0f);                                  // move content position toward the right, by style.IndentSpacing or indent_w if != 0
IMGUI_FUNCTION(Indent)
OPTIONAL_NUMBER_ARG(indent_w, 0.0f)
CALL_FUNCTION_NO_RET(Indent, indent_w)
END_IMGUI_FUNC

//    IMGUI_API void          Unindent(float indent_w = 0.0f);                                // move content position back to the left, by style.IndentSpacing or indent_w if != 0
IMGUI_FUNCTION(Unindent)
OPTIONAL_NUMBER_ARG(indent_w, 0.0f)
CALL_FUNCTION_NO_RET(Unindent, indent_w)
END_IMGUI_FUNC

//    IMGUI_API void          BeginGroup();                                                   // lock horizontal starting position
IMGUI_FUNCTION(BeginGroup)
CALL_FUNCTION_NO_RET(BeginGroup)
ADD_END_STACK(4)
END_IMGUI_FUNC

//    IMGUI_API void          EndGroup();                                                     // unlock horizontal starting position + capture the whole group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.)
IMGUI_FUNCTION(EndGroup)
CALL_FUNCTION_NO_RET(EndGroup)
POP_END_STACK(4)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetCursorPos();                                                 // cursor position in window coordinates (relative to window position)
IMGUI_FUNCTION(GetCursorPos)
CALL_FUNCTION(GetCursorPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API float         GetCursorPosX();                                                //   (some functions are using window-relative coordinates, such as: GetCursorPos, GetCursorStartPos, GetContentRegionMax, GetWindowContentRegion* etc.
IMGUI_FUNCTION(GetCursorPosX)
CALL_FUNCTION(GetCursorPosX, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetCursorPosY();                                                //    other functions such as GetCursorScreenPos or everything in ImDrawList::
IMGUI_FUNCTION(GetCursorPosY)
CALL_FUNCTION(GetCursorPosY, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetCursorPos(const ImVec2& local_pos);                          //    are using the main, absolute coordinate system.
IMGUI_FUNCTION(SetCursorPos)
IM_VEC_2_ARG(local_pos)
CALL_FUNCTION_NO_RET(SetCursorPos, local_pos)
END_IMGUI_FUNC

//    IMGUI_API void          SetCursorPosX(float local_x);                                   //    GetWindowPos() + GetCursorPos() == GetCursorScreenPos() etc.)
IMGUI_FUNCTION(SetCursorPosX)
NUMBER_ARG(local_x)
CALL_FUNCTION_NO_RET(SetCursorPosX, local_x)
END_IMGUI_FUNC

//    IMGUI_API void          SetCursorPosY(float local_y);                                   //
IMGUI_FUNCTION(SetCursorPosY)
NUMBER_ARG(local_y)
CALL_FUNCTION_NO_RET(SetCursorPosY, local_y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetCursorStartPos();                                            // initial cursor position in window coordinates
IMGUI_FUNCTION(GetCursorStartPos)
CALL_FUNCTION(GetCursorStartPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetCursorScreenPos();                                           // cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. Useful to work with ImDrawList API.
IMGUI_FUNCTION(GetCursorScreenPos)
CALL_FUNCTION(GetCursorScreenPos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API void          SetCursorScreenPos(const ImVec2& pos);                          // cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport.
IMGUI_FUNCTION(SetCursorScreenPos)
IM_VEC_2_ARG(pos)
CALL_FUNCTION_NO_RET(SetCursorScreenPos, pos)
END_IMGUI_FUNC

//    IMGUI_API void          AlignTextToFramePadding();                                      // vertically align upcoming text baseline to FramePadding.y so that it will align properly to regularly framed items (call if you have text on a line before a framed item)
IMGUI_FUNCTION(AlignTextToFramePadding)
CALL_FUNCTION_NO_RET(AlignTextToFramePadding)
END_IMGUI_FUNC

//    IMGUI_API float         GetTextLineHeight();                                            // ~ FontSize
IMGUI_FUNCTION(GetTextLineHeight)
CALL_FUNCTION(GetTextLineHeight, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetTextLineHeightWithSpacing();                                 // ~ FontSize + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of text)
IMGUI_FUNCTION(GetTextLineHeightWithSpacing)
CALL_FUNCTION(GetTextLineHeightWithSpacing, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetFrameHeight();                                               // ~ FontSize + style.FramePadding.y * 2
IMGUI_FUNCTION(GetFrameHeight)
CALL_FUNCTION(GetFrameHeight, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetFrameHeightWithSpacing();                                    // ~ FontSize + style.FramePadding.y * 2 + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of framed widgets)
IMGUI_FUNCTION(GetFrameHeightWithSpacing)
CALL_FUNCTION(GetFrameHeightWithSpacing, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          PushID(const char* str_id);                                     // push string into the ID stack (will hash string).
IMGUI_FUNCTION(PushID)
LABEL_ARG(str_id)
CALL_FUNCTION_NO_RET(PushID, str_id)
END_IMGUI_FUNC

//    IMGUI_API void          PushID(const char* str_id_begin, const char* str_id_end);       // push string into the ID stack (will hash string).
IMGUI_FUNCTION(PushID_2)
LABEL_ARG(str_id_begin)
LABEL_ARG(str_id_end)
CALL_FUNCTION_NO_RET(PushID, str_id_begin, str_id_end)
END_IMGUI_FUNC

//    IMGUI_API void          PushID(const void* ptr_id);                                     // push pointer into the ID stack (will hash pointer).
// Unsupported arg type const void* ptr_id
//    IMGUI_API void          PushID(int int_id);                                             // push integer into the ID stack (will hash integer).
IMGUI_FUNCTION(PushID_3)
INT_ARG(int_id)
CALL_FUNCTION_NO_RET(PushID, int_id)
END_IMGUI_FUNC

//    IMGUI_API void          PopID();                                                        // pop from the ID stack.
IMGUI_FUNCTION(PopID)
CALL_FUNCTION_NO_RET(PopID)
END_IMGUI_FUNC

//    IMGUI_API ImGuiID       GetID(const char* str_id);                                      // calculate unique ID (hash of whole ID stack + given parameter). e.g. if you want to query into ImGuiStorage yourself
IMGUI_FUNCTION(GetID)
LABEL_ARG(str_id)
CALL_FUNCTION(GetID, unsigned int, str_id)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImGuiID       GetID(const char* str_id_begin, const char* str_id_end);
IMGUI_FUNCTION(GetID_2)
LABEL_ARG(str_id_begin)
LABEL_ARG(str_id_end)
CALL_FUNCTION(GetID, unsigned int, str_id_begin, str_id_end)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImGuiID       GetID(const void* ptr_id);
// Unsupported arg type const void* ptr_id
//    IMGUI_API void          TextUnformatted(const char* text, const char* text_end = NULL); // raw text without formatting. Roughly equivalent to Text("%s", text) but: A) doesn't require null terminated string if 'text_end' is specified, B) it's faster, no memory copy is done, no buffer size limits, recommended for long chunks of text.
IMGUI_FUNCTION(TextUnformatted)
LABEL_ARG(text)
OPTIONAL_LABEL_ARG(text_end, NULL)
CALL_FUNCTION_NO_RET(TextUnformatted, text, text_end)
END_IMGUI_FUNC

//    IMGUI_API void          Text(const char* fmt, ...)                                      IM_FMTARGS(1); // formatted text
// Unsupported arg type  ...)                                      IM_FMTARGS(1
//    IMGUI_API void          TextV(const char* fmt, va_list args)                            IM_FMTLIST(1);
// Unsupported arg type  va_list args)                            IM_FMTLIST(1
//    IMGUI_API void          TextColored(const ImVec4& col, const char* fmt, ...)            IM_FMTARGS(2); // shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor();
// Unsupported arg type  ...)            IM_FMTARGS(2
//    IMGUI_API void          TextColoredV(const ImVec4& col, const char* fmt, va_list args)  IM_FMTLIST(2);
// Unsupported arg type  va_list args)  IM_FMTLIST(2
//    IMGUI_API void          TextDisabled(const char* fmt, ...)                              IM_FMTARGS(1); // shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor();
// Unsupported arg type  ...)                              IM_FMTARGS(1
//    IMGUI_API void          TextDisabledV(const char* fmt, va_list args)                    IM_FMTLIST(1);
// Unsupported arg type  va_list args)                    IM_FMTLIST(1
//    IMGUI_API void          TextWrapped(const char* fmt, ...)                               IM_FMTARGS(1); // shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
// Unsupported arg type  ...)                               IM_FMTARGS(1
//    IMGUI_API void          TextWrappedV(const char* fmt, va_list args)                     IM_FMTLIST(1);
// Unsupported arg type  va_list args)                     IM_FMTLIST(1
//    IMGUI_API void          LabelText(const char* label, const char* fmt, ...)              IM_FMTARGS(2); // display text+label aligned the same way as value+label widgets
// Unsupported arg type  ...)              IM_FMTARGS(2
//    IMGUI_API void          LabelTextV(const char* label, const char* fmt, va_list args)    IM_FMTLIST(2);
// Unsupported arg type  va_list args)    IM_FMTLIST(2
//    IMGUI_API void          BulletText(const char* fmt, ...)                                IM_FMTARGS(1); // shortcut for Bullet()+Text()
// Unsupported arg type  ...)                                IM_FMTARGS(1
//    IMGUI_API void          BulletTextV(const char* fmt, va_list args)                      IM_FMTLIST(1);
// Unsupported arg type  va_list args)                      IM_FMTLIST(1
//    IMGUI_API bool          Button(const char* label, const ImVec2& size = ImVec2 0  0);   // button
IMGUI_FUNCTION(Button)
LABEL_ARG(label)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Button, bool, label, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SmallButton(const char* label);                                 // button with FramePadding=(0,0) to easily embed within text
IMGUI_FUNCTION(SmallButton)
LABEL_ARG(label)
CALL_FUNCTION(SmallButton, bool, label)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InvisibleButton(const char* str_id, const ImVec2& size);        // button behavior without the visuals, frequently useful to build custom behaviors using the public api (along with IsItemActive, IsItemHovered, etc.)
IMGUI_FUNCTION(InvisibleButton)
LABEL_ARG(str_id)
IM_VEC_2_ARG(size)
CALL_FUNCTION(InvisibleButton, bool, str_id, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ArrowButton(const char* str_id, ImGuiDir dir);                  // square button with an arrow shape
IMGUI_FUNCTION(ArrowButton)
LABEL_ARG(str_id)
ENUM_ARG(dir)
CALL_FUNCTION(ArrowButton, bool, str_id, dir)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2 0  0, const ImVec2& uv1 = ImVec2 1 1, const ImVec4& tint_col = ImVec4 1 1 1 1, const ImVec4& border_col = ImVec4 0 0 0 0);
IMGUI_FUNCTION(Image)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(size)
OPTIONAL_IM_VEC_2_ARG(uv0, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv1, 1, 1)
OPTIONAL_IM_VEC_4_ARG(tint_col, 1, 1, 1, 1)
OPTIONAL_IM_VEC_4_ARG(border_col, 0, 0, 0, 0)
CALL_FUNCTION_NO_RET(Image, user_texture_id, size, uv0, uv1, tint_col, border_col)
END_IMGUI_FUNC

//    IMGUI_API bool          ImageButton(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2 0  0,  const ImVec2& uv1 = ImVec2 1 1, int frame_padding = -1, const ImVec4& bg_col = ImVec4 0 0 0 0, const ImVec4& tint_col = ImVec4 1 1 1 1);    // <0 frame_padding uses default frame padding settings. 0 for no padding
IMGUI_FUNCTION(ImageButton)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(size)
OPTIONAL_IM_VEC_2_ARG(uv0, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv1, 1, 1)
OPTIONAL_INT_ARG(frame_padding, -1)
OPTIONAL_IM_VEC_4_ARG(bg_col, 0, 0, 0, 0)
OPTIONAL_IM_VEC_4_ARG(tint_col, 1, 1, 1, 1)
CALL_FUNCTION(ImageButton, bool, user_texture_id, size, uv0, uv1, frame_padding, bg_col, tint_col)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          Checkbox(const char* label, bool* v);
IMGUI_FUNCTION(Checkbox)
LABEL_ARG(label)
BOOL_POINTER_ARG(v)
CALL_FUNCTION(Checkbox, bool, label, v)
PUSH_BOOL(ret)
END_BOOL_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value);
IMGUI_FUNCTION(CheckboxFlags)
LABEL_ARG(label)
UINT_POINTER_ARG(flags)
UINT_ARG(flags_value)
CALL_FUNCTION(CheckboxFlags, bool, label, flags, flags_value)
PUSH_BOOL(ret)
END_UINT_POINTER(flags)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          RadioButton(const char* label, bool active);                    // use with e.g. if (RadioButton("one", my_value==1)) { my_value = 1; }
IMGUI_FUNCTION(RadioButton)
LABEL_ARG(label)
BOOL_ARG(active)
CALL_FUNCTION(RadioButton, bool, label, active)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          RadioButton(const char* label, int* v, int v_button);           // shortcut to handle the above pattern when value is an integer
IMGUI_FUNCTION(RadioButton_2)
LABEL_ARG(label)
INT_POINTER_ARG(v)
INT_ARG(v_button)
CALL_FUNCTION(RadioButton, bool, label, v, v_button)
PUSH_BOOL(ret)
END_INT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          ProgressBar(float fraction, const ImVec2& size_arg = ImVec2 -1  0, const char* overlay = NULL);
IMGUI_FUNCTION(ProgressBar)
NUMBER_ARG(fraction)
OPTIONAL_IM_VEC_2_ARG(size_arg, -1, 0)
OPTIONAL_LABEL_ARG(overlay, NULL)
CALL_FUNCTION_NO_RET(ProgressBar, fraction, size_arg, overlay)
END_IMGUI_FUNC

//    IMGUI_API void          Bullet();                                                       // draw a small circle and keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses
IMGUI_FUNCTION(Bullet)
CALL_FUNCTION_NO_RET(Bullet)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags = 0);
IMGUI_FUNCTION(BeginCombo)
LABEL_ARG(label)
LABEL_ARG(preview_value)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginCombo, bool, label, preview_value, flags)
IF_RET_ADD_END_STACK(5)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndCombo(); // only call EndCombo() if BeginCombo() returns true!
IMGUI_FUNCTION(EndCombo)
CALL_FUNCTION_NO_RET(EndCombo)
POP_END_STACK(5)
END_IMGUI_FUNC

//    IMGUI_API bool          Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1);
IMGUI_FUNCTION(Combo)
LABEL_ARG(label)
INT_POINTER_ARG(current_item)
LABEL_ARRAY_ARG(items)
INT_ARG(items_count)
OPTIONAL_INT_ARG(popup_max_height_in_items, -1)
CALL_FUNCTION(Combo, bool, label, current_item, items, items_count, popup_max_height_in_items)
PUSH_BOOL(ret)
END_INT_POINTER(current_item)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1);      // Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
IMGUI_FUNCTION(Combo_2)
LABEL_ARG(label)
INT_POINTER_ARG(current_item)
LABEL_ARG(items_separated_by_zeros)
OPTIONAL_INT_ARG(popup_max_height_in_items, -1)
CALL_FUNCTION(Combo, bool, label, current_item, items_separated_by_zeros, popup_max_height_in_items)
PUSH_BOOL(ret)
END_INT_POINTER(current_item)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          Combo(const char* label, int* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1);
// Unsupported arg type  bool(*items_getter)(void* data
// Unsupported arg type  const char** out_text)
// Unsupported arg type  void* data
//    IMGUI_API bool          DragFloat(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", float power = 1.0f);     // If v_min >= v_max we have no bound
IMGUI_FUNCTION(DragFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat, bool, label, v, v_speed, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragFloat2(const char* label, float v[2], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat2, bool, label, v, v_speed, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragFloat3(const char* label, float v[3], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat3, bool, label, v, v_speed, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragFloat4(const char* label, float v[4], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(DragFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloat4, bool, label, v, v_speed, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", const char* format_max = NULL, float power = 1.0f);
IMGUI_FUNCTION(DragFloatRange2)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v_current_min)
FLOAT_POINTER_ARG(v_current_max)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_NUMBER_ARG(v_min, 0.0f)
OPTIONAL_NUMBER_ARG(v_max, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_LABEL_ARG(format_max, NULL)
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(DragFloatRange2, bool, label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v_current_min)
END_FLOAT_POINTER(v_current_max)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragInt(const char* label, int* v, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d");                                       // If v_min >= v_max we have no bound
IMGUI_FUNCTION(DragInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(DragInt, bool, label, v, v_speed, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragInt2(const char* label, int v[2], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d");
IMGUI_FUNCTION(DragInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(DragInt2, bool, label, v, v_speed, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragInt3(const char* label, int v[3], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d");
IMGUI_FUNCTION(DragInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(DragInt3, bool, label, v, v_speed, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragInt4(const char* label, int v[4], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d");
IMGUI_FUNCTION(DragInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(DragInt4, bool, label, v, v_speed, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", const char* format_max = NULL);
IMGUI_FUNCTION(DragIntRange2)
LABEL_ARG(label)
INT_POINTER_ARG(v_current_min)
INT_POINTER_ARG(v_current_max)
OPTIONAL_NUMBER_ARG(v_speed, 1.0f)
OPTIONAL_INT_ARG(v_min, 0)
OPTIONAL_INT_ARG(v_max, 0)
OPTIONAL_LABEL_ARG(format, "%d")
OPTIONAL_LABEL_ARG(format_max, NULL)
CALL_FUNCTION(DragIntRange2, bool, label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max)
PUSH_BOOL(ret)
END_INT_POINTER(v_current_min)
END_INT_POINTER(v_current_max)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DragScalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, float power = 1.0f);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_min = NULL
// Unsupported arg type  const void* p_max = NULL
//    IMGUI_API bool          DragScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, float power = 1.0f);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_min = NULL
// Unsupported arg type  const void* p_max = NULL
//    IMGUI_API bool          SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", float power = 1.0f);     // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display. Use power!=1.0 for power curve sliders
IMGUI_FUNCTION(SliderFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat, bool, label, v, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat2, bool, label, v, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat3, bool, label, v, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(SliderFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(SliderFloat4, bool, label, v, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderAngle(const char* label, float* v_rad, float v_degrees_min = -360.0f, float v_degrees_max = +360.0f, const char* format = "%.0f deg");
IMGUI_FUNCTION(SliderAngle)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v_rad)
OPTIONAL_NUMBER_ARG(v_degrees_min, -360.0f)
OPTIONAL_NUMBER_ARG(v_degrees_max, +360.0f)
OPTIONAL_LABEL_ARG(format, "%.0f deg")
CALL_FUNCTION(SliderAngle, bool, label, v_rad, v_degrees_min, v_degrees_max, format)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v_rad)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderInt(const char* label, int* v, int v_min, int v_max, const char* format = "%d");
IMGUI_FUNCTION(SliderInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(SliderInt, bool, label, v, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format = "%d");
IMGUI_FUNCTION(SliderInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(SliderInt2, bool, label, v, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format = "%d");
IMGUI_FUNCTION(SliderInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(SliderInt3, bool, label, v, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format = "%d");
IMGUI_FUNCTION(SliderInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(SliderInt4, bool, label, v, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_min
// Unsupported arg type  const void* p_max
//    IMGUI_API bool          SliderScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_min
// Unsupported arg type  const void* p_max
//    IMGUI_API bool          VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format = "%.3f", float power = 1.0f);
IMGUI_FUNCTION(VSliderFloat)
LABEL_ARG(label)
IM_VEC_2_ARG(size)
FLOAT_POINTER_ARG(v)
NUMBER_ARG(v_min)
NUMBER_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_NUMBER_ARG(power, 1.0f)
CALL_FUNCTION(VSliderFloat, bool, label, size, v, v_min, v_max, format, power)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format = "%d");
IMGUI_FUNCTION(VSliderInt)
LABEL_ARG(label)
IM_VEC_2_ARG(size)
INT_POINTER_ARG(v)
INT_ARG(v_min)
INT_ARG(v_max)
OPTIONAL_LABEL_ARG(format, "%d")
CALL_FUNCTION(VSliderInt, bool, label, size, v, v_min, v_max, format)
PUSH_BOOL(ret)
END_INT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          VSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_min
// Unsupported arg type  const void* p_max
//    IMGUI_API bool          InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
// Unsupported arg type  size_t buf_size
//    IMGUI_API bool          InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2 0  0, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
// Unsupported arg type  size_t buf_size
//    IMGUI_API bool          InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
// Unsupported arg type  size_t buf_size
//    IMGUI_API bool          InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputFloat)
LABEL_ARG(label)
FLOAT_POINTER_ARG(v)
OPTIONAL_NUMBER_ARG(step, 0.0f)
OPTIONAL_NUMBER_ARG(step_fast, 0.0f)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputFloat, bool, label, v, step, step_fast, format, flags)
PUSH_BOOL(ret)
END_FLOAT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputFloat2(const char* label, float v[2], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputFloat2)
LABEL_ARG(label)
FLOAT_ARRAY2_ARG(v)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputFloat2, bool, label, v, format, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputFloat3(const char* label, float v[3], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputFloat3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(v)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputFloat3, bool, label, v, format, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputFloat4(const char* label, float v[4], const char* format = "%.3f", ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputFloat4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(v)
OPTIONAL_LABEL_ARG(format, "%.3f")
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputFloat4, bool, label, v, format, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputInt)
LABEL_ARG(label)
INT_POINTER_ARG(v)
OPTIONAL_INT_ARG(step, 1)
OPTIONAL_INT_ARG(step_fast, 100)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputInt, bool, label, v, step, step_fast, flags)
PUSH_BOOL(ret)
END_INT_POINTER(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputInt2)
LABEL_ARG(label)
INT_ARRAY2_ARG(v)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputInt2, bool, label, v, flags)
PUSH_BOOL(ret)
END_INT_ARRAY2(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputInt3)
LABEL_ARG(label)
INT_ARRAY3_ARG(v)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputInt3, bool, label, v, flags)
PUSH_BOOL(ret)
END_INT_ARRAY3(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags = 0);
IMGUI_FUNCTION(InputInt4)
LABEL_ARG(label)
INT_ARRAY4_ARG(v)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(InputInt4, bool, label, v, flags)
PUSH_BOOL(ret)
END_INT_ARRAY4(v)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          InputDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0);
// Unsupported arg type  double* v
// Unsupported arg type  double step = 0.0
// Unsupported arg type  double step_fast = 0.0
//    IMGUI_API bool          InputScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_step = NULL
// Unsupported arg type  const void* p_step_fast = NULL
//    IMGUI_API bool          InputScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0);
// Unsupported arg type  void* p_data
// Unsupported arg type  const void* p_step = NULL
// Unsupported arg type  const void* p_step_fast = NULL
//    IMGUI_API bool          ColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags = 0);
IMGUI_FUNCTION(ColorEdit3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(col)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(ColorEdit3, bool, label, col, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(col)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags = 0);
IMGUI_FUNCTION(ColorEdit4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(col)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(ColorEdit4, bool, label, col, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(col)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ColorPicker3(const char* label, float col[3], ImGuiColorEditFlags flags = 0);
IMGUI_FUNCTION(ColorPicker3)
LABEL_ARG(label)
FLOAT_ARRAY3_ARG(col)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(ColorPicker3, bool, label, col, flags)
PUSH_BOOL(ret)
END_FLOAT_ARRAY3(col)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ColorPicker4(const char* label, float col[4], ImGuiColorEditFlags flags = 0, const float* ref_col = NULL);
IMGUI_FUNCTION(ColorPicker4)
LABEL_ARG(label)
FLOAT_ARRAY4_ARG(col)
OPTIONAL_ENUM_ARG(flags, 0)
FLOAT_ARRAY_ARG(ref_col)
CALL_FUNCTION(ColorPicker4, bool, label, col, flags, ref_col)
PUSH_BOOL(ret)
END_FLOAT_ARRAY4(col)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2 0  0); // display a colored square/button, hover for details, return true when pressed.
IMGUI_FUNCTION(ColorButton)
LABEL_ARG(desc_id)
IM_VEC_4_ARG(col)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(ColorButton, bool, desc_id, col, flags, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetColorEditOptions(ImGuiColorEditFlags flags);                     // initialize current options (generally on application startup) if you want to select a default format, picker type, etc. User will be able to change many settings, unless you pass the _NoOptions flag to your calls.
IMGUI_FUNCTION(SetColorEditOptions)
ENUM_ARG(flags)
CALL_FUNCTION_NO_RET(SetColorEditOptions, flags)
END_IMGUI_FUNC

//    IMGUI_API bool          TreeNode(const char* label);
IMGUI_FUNCTION(TreeNode)
LABEL_ARG(label)
CALL_FUNCTION(TreeNode, bool, label)
IF_RET_ADD_END_STACK(6)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          TreeNode(const char* str_id, const char* fmt, ...) IM_FMTARGS(2);   // helper variation to easily decorelate the id from the displayed string. Read the FAQ about why and how to use ID. to align arbitrary text at the same level as a TreeNode() you can use Bullet().
// Unsupported arg type  ...) IM_FMTARGS(2
//    IMGUI_API bool          TreeNode(const void* ptr_id, const char* fmt, ...) IM_FMTARGS(2);   // "
// Unsupported arg type const void* ptr_id
// Unsupported arg type  ...) IM_FMTARGS(2
//    IMGUI_API bool          TreeNodeV(const char* str_id, const char* fmt, va_list args) IM_FMTLIST(2);
// Unsupported arg type  va_list args) IM_FMTLIST(2
//    IMGUI_API bool          TreeNodeV(const void* ptr_id, const char* fmt, va_list args) IM_FMTLIST(2);
// Unsupported arg type const void* ptr_id
// Unsupported arg type  va_list args) IM_FMTLIST(2
//    IMGUI_API bool          TreeNodeEx(const char* label, ImGuiTreeNodeFlags flags = 0);
IMGUI_FUNCTION(TreeNodeEx)
LABEL_ARG(label)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(TreeNodeEx, bool, label, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          TreeNodeEx(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) IM_FMTARGS(3);
// Unsupported arg type  ...) IM_FMTARGS(3
//    IMGUI_API bool          TreeNodeEx(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) IM_FMTARGS(3);
// Unsupported arg type const void* ptr_id
// Unsupported arg type  ...) IM_FMTARGS(3
//    IMGUI_API bool          TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) IM_FMTLIST(3);
// Unsupported arg type  va_list args) IM_FMTLIST(3
//    IMGUI_API bool          TreeNodeExV(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) IM_FMTLIST(3);
// Unsupported arg type const void* ptr_id
// Unsupported arg type  va_list args) IM_FMTLIST(3
//    IMGUI_API void          TreePush(const char* str_id);                                       // ~ Indent()+PushId(). Already called by TreeNode() when returning true, but you can call TreePush/TreePop yourself if desired.
IMGUI_FUNCTION(TreePush)
LABEL_ARG(str_id)
CALL_FUNCTION_NO_RET(TreePush, str_id)
ADD_END_STACK(6)
END_IMGUI_FUNC

//    IMGUI_API void          TreePush(const void* ptr_id = NULL);                                // "
// Unsupported arg type const void* ptr_id = NULL
//    IMGUI_API void          TreePop();                                                          // ~ Unindent()+PopId()
IMGUI_FUNCTION(TreePop)
CALL_FUNCTION_NO_RET(TreePop)
POP_END_STACK(6)
END_IMGUI_FUNC

//    IMGUI_API float         GetTreeNodeToLabelSpacing();                                        // horizontal distance preceding label when using TreeNode*() or Bullet() == (g.FontSize + style.FramePadding.x*2) for a regular unframed TreeNode
IMGUI_FUNCTION(GetTreeNodeToLabelSpacing)
CALL_FUNCTION(GetTreeNodeToLabelSpacing, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          CollapsingHeader(const char* label, ImGuiTreeNodeFlags flags = 0);  // if returning 'true' the header is open. doesn't indent nor push on ID stack. user doesn't have to call TreePop().
IMGUI_FUNCTION(CollapsingHeader)
LABEL_ARG(label)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(CollapsingHeader, bool, label, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          CollapsingHeader(const char* label, bool* p_open, ImGuiTreeNodeFlags flags = 0); // when 'p_open' isn't NULL, display an additional small close button on upper right of the header
IMGUI_FUNCTION(CollapsingHeader_2)
LABEL_ARG(label)
BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(CollapsingHeader, bool, label, p_open, flags)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextItemOpen(bool is_open, ImGuiCond cond = 0);                  // set next TreeNode/CollapsingHeader open state.
IMGUI_FUNCTION(SetNextItemOpen)
BOOL_ARG(is_open)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextItemOpen, is_open, cond)
END_IMGUI_FUNC

//    IMGUI_API bool          Selectable(const char* label, bool selected = false, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2 0  0); // "bool selected" carry the selection state (read-only). Selectable() is clicked is returns true so you can modify your selection state. size.x==0.0: use remaining width, size.x>0.0: specify width. size.y==0.0: use label height, size.y>0.0: specify height
IMGUI_FUNCTION(Selectable)
LABEL_ARG(label)
OPTIONAL_BOOL_ARG(selected, false)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Selectable, bool, label, selected, flags, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          Selectable(const char* label, bool* p_selected, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2 0  0);      // "bool* p_selected" point to the selection state (read-write), as a convenient helper.
IMGUI_FUNCTION(Selectable_2)
LABEL_ARG(label)
BOOL_POINTER_ARG(p_selected)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(Selectable, bool, label, p_selected, flags, size)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_selected)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ListBox(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items = -1);
IMGUI_FUNCTION(ListBox)
LABEL_ARG(label)
INT_POINTER_ARG(current_item)
LABEL_ARRAY_ARG(items)
INT_ARG(items_count)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(ListBox, bool, label, current_item, items, items_count, height_in_items)
PUSH_BOOL(ret)
END_INT_POINTER(current_item)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ListBox(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items = -1);
// Unsupported arg type  bool (*items_getter)(void* data
// Unsupported arg type  const char** out_text)
// Unsupported arg type  void* data
//    IMGUI_API bool          ListBoxHeader(const char* label, const ImVec2& size = ImVec2 0  0); // use if you want to reimplement ListBox() will custom data or interactions. if the function return true, you can output elements then call ListBoxFooter() afterwards.
IMGUI_FUNCTION(ListBoxHeader)
LABEL_ARG(label)
OPTIONAL_IM_VEC_2_ARG(size, 0, 0)
CALL_FUNCTION(ListBoxHeader, bool, label, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          ListBoxHeader(const char* label, int items_count, int height_in_items = -1); // "
IMGUI_FUNCTION(ListBoxHeader_2)
LABEL_ARG(label)
INT_ARG(items_count)
OPTIONAL_INT_ARG(height_in_items, -1)
CALL_FUNCTION(ListBoxHeader, bool, label, items_count, height_in_items)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          ListBoxFooter();                                                    // terminate the scrolling region. only call ListBoxFooter() if ListBoxHeader() returned true!
IMGUI_FUNCTION(ListBoxFooter)
CALL_FUNCTION_NO_RET(ListBoxFooter)
END_IMGUI_FUNC

//    IMGUI_API void          PlotLines(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0  0, int stride = sizeof(float));
IMGUI_FUNCTION(PlotLines)
LABEL_ARG(label)
FLOAT_ARRAY_ARG(values)
INT_ARG(values_count)
OPTIONAL_INT_ARG(values_offset, 0)
OPTIONAL_LABEL_ARG(overlay_text, NULL)
OPTIONAL_NUMBER_ARG(scale_min, FLT_MAX)
OPTIONAL_NUMBER_ARG(scale_max, FLT_MAX)
OPTIONAL_IM_VEC_2_ARG(graph_size, 0, 0)
OPTIONAL_INT_ARG(stride, sizeof(float))
CALL_FUNCTION_NO_RET(PlotLines, label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride)
END_IMGUI_FUNC

//    IMGUI_API void          PlotLines(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0  0);
// Unsupported arg type  float(*values_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API void          PlotHistogram(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0  0, int stride = sizeof(float));
IMGUI_FUNCTION(PlotHistogram)
LABEL_ARG(label)
FLOAT_ARRAY_ARG(values)
INT_ARG(values_count)
OPTIONAL_INT_ARG(values_offset, 0)
OPTIONAL_LABEL_ARG(overlay_text, NULL)
OPTIONAL_NUMBER_ARG(scale_min, FLT_MAX)
OPTIONAL_NUMBER_ARG(scale_max, FLT_MAX)
OPTIONAL_IM_VEC_2_ARG(graph_size, 0, 0)
OPTIONAL_INT_ARG(stride, sizeof(float))
CALL_FUNCTION_NO_RET(PlotHistogram, label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride)
END_IMGUI_FUNC

//    IMGUI_API void          PlotHistogram(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2 0  0);
// Unsupported arg type  float(*values_getter)(void* data
// Unsupported arg type  void* data
//    IMGUI_API void          Value(const char* prefix, bool b);
IMGUI_FUNCTION(Value)
LABEL_ARG(prefix)
BOOL_ARG(b)
CALL_FUNCTION_NO_RET(Value, prefix, b)
END_IMGUI_FUNC

//    IMGUI_API void          Value(const char* prefix, int v);
IMGUI_FUNCTION(Value_2)
LABEL_ARG(prefix)
INT_ARG(v)
CALL_FUNCTION_NO_RET(Value, prefix, v)
END_IMGUI_FUNC

//    IMGUI_API void          Value(const char* prefix, unsigned int v);
IMGUI_FUNCTION(Value_3)
LABEL_ARG(prefix)
UINT_ARG(v)
CALL_FUNCTION_NO_RET(Value, prefix, v)
END_IMGUI_FUNC

//    IMGUI_API void          Value(const char* prefix, float v, const char* float_format = NULL);
IMGUI_FUNCTION(Value_4)
LABEL_ARG(prefix)
NUMBER_ARG(v)
OPTIONAL_LABEL_ARG(float_format, NULL)
CALL_FUNCTION_NO_RET(Value, prefix, v, float_format)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginMenuBar();                                                     // append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set on parent window).
IMGUI_FUNCTION(BeginMenuBar)
CALL_FUNCTION(BeginMenuBar, bool)
IF_RET_ADD_END_STACK(7)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndMenuBar();                                                       // only call EndMenuBar() if BeginMenuBar() returns true!
IMGUI_FUNCTION(EndMenuBar)
CALL_FUNCTION_NO_RET(EndMenuBar)
POP_END_STACK(7)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginMainMenuBar();                                                 // create and append to a full screen menu-bar.
IMGUI_FUNCTION(BeginMainMenuBar)
CALL_FUNCTION(BeginMainMenuBar, bool)
IF_RET_ADD_END_STACK(8)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndMainMenuBar();                                                   // only call EndMainMenuBar() if BeginMainMenuBar() returns true!
IMGUI_FUNCTION(EndMainMenuBar)
CALL_FUNCTION_NO_RET(EndMainMenuBar)
POP_END_STACK(8)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginMenu(const char* label, bool enabled = true);                  // create a sub-menu entry. only call EndMenu() if this returns true!
IMGUI_FUNCTION(BeginMenu)
LABEL_ARG(label)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(BeginMenu, bool, label, enabled)
IF_RET_ADD_END_STACK(9)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndMenu();                                                          // only call EndMenu() if BeginMenu() returns true!
IMGUI_FUNCTION(EndMenu)
CALL_FUNCTION_NO_RET(EndMenu)
POP_END_STACK(9)
END_IMGUI_FUNC

//    IMGUI_API bool          MenuItem(const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true);  // return true when activated. shortcuts are displayed for convenience but not processed by ImGui at the moment
IMGUI_FUNCTION(MenuItem)
LABEL_ARG(label)
OPTIONAL_LABEL_ARG(shortcut, NULL)
OPTIONAL_BOOL_ARG(selected, false)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(MenuItem, bool, label, shortcut, selected, enabled)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled = true);              // return true when activated + toggle (*p_selected) if p_selected != NULL
IMGUI_FUNCTION(MenuItem_2)
LABEL_ARG(label)
LABEL_ARG(shortcut)
BOOL_POINTER_ARG(p_selected)
OPTIONAL_BOOL_ARG(enabled, true)
CALL_FUNCTION(MenuItem, bool, label, shortcut, p_selected, enabled)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_selected)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          BeginTooltip();                                                     // begin/append a tooltip window. to create full-featured tooltip (with any kind of items).
IMGUI_FUNCTION(BeginTooltip)
CALL_FUNCTION_NO_RET(BeginTooltip)
ADD_END_STACK(10)
END_IMGUI_FUNC

//    IMGUI_API void          EndTooltip();
IMGUI_FUNCTION(EndTooltip)
CALL_FUNCTION_NO_RET(EndTooltip)
POP_END_STACK(10)
END_IMGUI_FUNC

//    IMGUI_API void          SetTooltip(const char* fmt, ...) IM_FMTARGS(1);                     // set a text-only tooltip, typically use with ImGui::IsItemHovered(). override any previous call to SetTooltip().
// Unsupported arg type  ...) IM_FMTARGS(1
//    IMGUI_API void          SetTooltipV(const char* fmt, va_list args) IM_FMTLIST(1);
// Unsupported arg type  va_list args) IM_FMTLIST(1
//    IMGUI_API bool          BeginPopup(const char* str_id, ImGuiWindowFlags flags = 0);                         // return true if the popup is open, and you can start outputting to it.
IMGUI_FUNCTION(BeginPopup)
LABEL_ARG(str_id)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginPopup, bool, str_id, flags)
IF_RET_ADD_END_STACK(11)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginPopupModal(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0); // return true if the modal is open, and you can start outputting to it.
IMGUI_FUNCTION(BeginPopupModal)
LABEL_ARG(name)
OPTIONAL_BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginPopupModal, bool, name, p_open, flags)
IF_RET_ADD_END_STACK(11)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndPopup();                                                                         // only call EndPopup() if BeginPopupXXX() returns true!
IMGUI_FUNCTION(EndPopup)
CALL_FUNCTION_NO_RET(EndPopup)
POP_END_STACK(11)
END_IMGUI_FUNC

//    IMGUI_API void          OpenPopup(const char* str_id, ImGuiPopupFlags popup_flags = 0);                     // call to mark popup as open (don't call every frame!).
IMGUI_FUNCTION(OpenPopup)
LABEL_ARG(str_id)
OPTIONAL_ENUM_ARG(popup_flags, 0)
CALL_FUNCTION_NO_RET(OpenPopup, str_id, popup_flags)
END_IMGUI_FUNC

//    IMGUI_API bool          OpenPopupContextItem(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1);   // helper to open popup when clicked on last item. return true when just opened. (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors)
IMGUI_FUNCTION(OpenPopupContextItem)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_ENUM_ARG(popup_flags, 1)
CALL_FUNCTION(OpenPopupContextItem, bool, str_id, popup_flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          CloseCurrentPopup();                                                                // manually close the popup we have begin-ed into.
IMGUI_FUNCTION(CloseCurrentPopup)
CALL_FUNCTION_NO_RET(CloseCurrentPopup)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginPopupContextItem(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1);  // open+begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here. read comments in .cpp!
IMGUI_FUNCTION(BeginPopupContextItem)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_ENUM_ARG(popup_flags, 1)
CALL_FUNCTION(BeginPopupContextItem, bool, str_id, popup_flags)
IF_RET_ADD_END_STACK(11)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginPopupContextWindow(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1);// open+begin popup when clicked on current window.
IMGUI_FUNCTION(BeginPopupContextWindow)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_ENUM_ARG(popup_flags, 1)
CALL_FUNCTION(BeginPopupContextWindow, bool, str_id, popup_flags)
IF_RET_ADD_END_STACK(11)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginPopupContextVoid(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1);  // open+begin popup when clicked in void (where there are no windows).
IMGUI_FUNCTION(BeginPopupContextVoid)
OPTIONAL_LABEL_ARG(str_id, NULL)
OPTIONAL_ENUM_ARG(popup_flags, 1)
CALL_FUNCTION(BeginPopupContextVoid, bool, str_id, popup_flags)
IF_RET_ADD_END_STACK(11)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsPopupOpen(const char* str_id, ImGuiPopupFlags flags = 0);                         // return true if the popup is open.
IMGUI_FUNCTION(IsPopupOpen)
LABEL_ARG(str_id)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(IsPopupOpen, bool, str_id, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          Columns(int count = 1, const char* id = NULL, bool border = true);
IMGUI_FUNCTION(Columns)
OPTIONAL_INT_ARG(count, 1)
OPTIONAL_LABEL_ARG(id, NULL)
OPTIONAL_BOOL_ARG(border, true)
CALL_FUNCTION_NO_RET(Columns, count, id, border)
END_IMGUI_FUNC

//    IMGUI_API void          NextColumn();                                                       // next column, defaults to current row or next row if the current row is finished
IMGUI_FUNCTION(NextColumn)
CALL_FUNCTION_NO_RET(NextColumn)
END_IMGUI_FUNC

//    IMGUI_API int           GetColumnIndex();                                                   // get current column index
IMGUI_FUNCTION(GetColumnIndex)
CALL_FUNCTION(GetColumnIndex, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API float         GetColumnWidth(int column_index = -1);                              // get column width (in pixels). pass -1 to use current column
IMGUI_FUNCTION(GetColumnWidth)
OPTIONAL_INT_ARG(column_index, -1)
CALL_FUNCTION(GetColumnWidth, float, column_index)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetColumnWidth(int column_index, float width);                      // set column width (in pixels). pass -1 to use current column
IMGUI_FUNCTION(SetColumnWidth)
INT_ARG(column_index)
NUMBER_ARG(width)
CALL_FUNCTION_NO_RET(SetColumnWidth, column_index, width)
END_IMGUI_FUNC

//    IMGUI_API float         GetColumnOffset(int column_index = -1);                             // get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetColumnsCount() inclusive. column 0 is typically 0.0f
IMGUI_FUNCTION(GetColumnOffset)
OPTIONAL_INT_ARG(column_index, -1)
CALL_FUNCTION(GetColumnOffset, float, column_index)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetColumnOffset(int column_index, float offset_x);                  // set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column
IMGUI_FUNCTION(SetColumnOffset)
INT_ARG(column_index)
NUMBER_ARG(offset_x)
CALL_FUNCTION_NO_RET(SetColumnOffset, column_index, offset_x)
END_IMGUI_FUNC

//    IMGUI_API int           GetColumnsCount();
IMGUI_FUNCTION(GetColumnsCount)
CALL_FUNCTION(GetColumnsCount, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginTable(const char* str_id, int columns_count, ImGuiTableFlags flags = 0, const ImVec2& outer_size = ImVec2 0  0, float inner_width = 0.0f);
IMGUI_FUNCTION(BeginTable)
LABEL_ARG(str_id)
INT_ARG(columns_count)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_IM_VEC_2_ARG(outer_size, 0, 0)
OPTIONAL_NUMBER_ARG(inner_width, 0.0f)
CALL_FUNCTION(BeginTable, bool, str_id, columns_count, flags, outer_size, inner_width)
IF_RET_ADD_END_STACK(12)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndTable();                                 // only call EndTable() if BeginTable() returns true!
IMGUI_FUNCTION(EndTable)
CALL_FUNCTION_NO_RET(EndTable)
POP_END_STACK(12)
END_IMGUI_FUNC

//    IMGUI_API void          TableNextRow(ImGuiTableRowFlags row_flags = 0, float min_row_height = 0.0f); // append into the first cell of a new row.
IMGUI_FUNCTION(TableNextRow)
OPTIONAL_ENUM_ARG(row_flags, 0)
OPTIONAL_NUMBER_ARG(min_row_height, 0.0f)
CALL_FUNCTION_NO_RET(TableNextRow, row_flags, min_row_height)
END_IMGUI_FUNC

//    IMGUI_API bool          TableNextCell();                            // append into the next column (next column, or next row if currently in last column). Return true if column is visible.
IMGUI_FUNCTION(TableNextCell)
CALL_FUNCTION(TableNextCell, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          TableSetColumnIndex(int column_n);          // append into the specified column. Return true if column is visible.
IMGUI_FUNCTION(TableSetColumnIndex)
INT_ARG(column_n)
CALL_FUNCTION(TableSetColumnIndex, bool, column_n)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API int           TableGetColumnIndex();                      // return current column index.
IMGUI_FUNCTION(TableGetColumnIndex)
CALL_FUNCTION(TableGetColumnIndex, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API const char*   TableGetColumnName(int column_n = -1);      // return NULL if column didn't have a name declared by TableSetupColumn(). Pass -1 to use current column.
IMGUI_FUNCTION(TableGetColumnName)
OPTIONAL_INT_ARG(column_n, -1)
CALL_FUNCTION(TableGetColumnName, const char*, column_n)
PUSH_STRING(ret)
PUSH_LAST_STRING(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          TableGetColumnIsVisible(int column_n = -1); // return true if column is visible. Same value is also returned by TableNextCell() and TableSetColumnIndex(). Pass -1 to use current column.
IMGUI_FUNCTION(TableGetColumnIsVisible)
OPTIONAL_INT_ARG(column_n, -1)
CALL_FUNCTION(TableGetColumnIsVisible, bool, column_n)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          TableGetColumnIsSorted(int column_n = -1);  // return true if column is included in the sort specs. Rarely used, can be useful to tell if a data change should trigger resort. Equivalent to test ImGuiTableSortSpecs's ->ColumnsMask & (1 << column_n). Pass -1 to use current column.
IMGUI_FUNCTION(TableGetColumnIsSorted)
OPTIONAL_INT_ARG(column_n, -1)
CALL_FUNCTION(TableGetColumnIsSorted, bool, column_n)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API int           TableGetHoveredColumn();                    // return hovered column. return -1 when table is not hovered. return columns_count if the unused space at the right of visible columns is hovered.
IMGUI_FUNCTION(TableGetHoveredColumn)
CALL_FUNCTION(TableGetHoveredColumn, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          TableSetupColumn(const char* label, ImGuiTableColumnFlags flags = 0, float init_width_or_weight = -1.0f, ImU32 user_id = 0);
IMGUI_FUNCTION(TableSetupColumn)
LABEL_ARG(label)
OPTIONAL_ENUM_ARG(flags, 0)
OPTIONAL_NUMBER_ARG(init_width_or_weight, -1.0f)
OPTIONAL_UINT_ARG(user_id, 0)
CALL_FUNCTION_NO_RET(TableSetupColumn, label, flags, init_width_or_weight, user_id)
END_IMGUI_FUNC

//    IMGUI_API void          TableAutoHeaders();                         // submit all headers cells based on data provided to TableSetupColumn() + submit context menu
IMGUI_FUNCTION(TableAutoHeaders)
CALL_FUNCTION_NO_RET(TableAutoHeaders)
END_IMGUI_FUNC

//    IMGUI_API void          TableHeader(const char* label);             // submit one header cell manually.
IMGUI_FUNCTION(TableHeader)
LABEL_ARG(label)
CALL_FUNCTION_NO_RET(TableHeader, label)
END_IMGUI_FUNC

//    IMGUI_API const ImGuiTableSortSpecs* TableGetSortSpecs();           // get latest sort specs for the table (NULL if not sorting).
// Unsupported return type const
//    IMGUI_API bool          BeginTabBar(const char* str_id, ImGuiTabBarFlags flags = 0);        // create and append into a TabBar
IMGUI_FUNCTION(BeginTabBar)
LABEL_ARG(str_id)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginTabBar, bool, str_id, flags)
IF_RET_ADD_END_STACK(13)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndTabBar();                                                        // only call EndTabBar() if BeginTabBar() returns true!
IMGUI_FUNCTION(EndTabBar)
CALL_FUNCTION_NO_RET(EndTabBar)
POP_END_STACK(13)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginTabItem(const char* label, bool* p_open = NULL, ImGuiTabItemFlags flags = 0);// create a Tab. Returns true if the Tab is selected.
IMGUI_FUNCTION(BeginTabItem)
LABEL_ARG(label)
OPTIONAL_BOOL_POINTER_ARG(p_open)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginTabItem, bool, label, p_open, flags)
IF_RET_ADD_END_STACK(14)
PUSH_BOOL(ret)
END_BOOL_POINTER(p_open)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndTabItem();                                                       // only call EndTabItem() if BeginTabItem() returns true!
IMGUI_FUNCTION(EndTabItem)
CALL_FUNCTION_NO_RET(EndTabItem)
POP_END_STACK(14)
END_IMGUI_FUNC

//    IMGUI_API void          SetTabItemClosed(const char* tab_or_docked_window_label);           // notify TabBar or Docking system of a closed tab/window ahead (useful to reduce visual flicker on reorderable tab bars). For tab-bar: call after BeginTabBar() and before Tab submissions. Otherwise call with a window name.
IMGUI_FUNCTION(SetTabItemClosed)
LABEL_ARG(tab_or_docked_window_label)
CALL_FUNCTION_NO_RET(SetTabItemClosed, tab_or_docked_window_label)
END_IMGUI_FUNC

//    IMGUI_API void          DockSpace(ImGuiID id, const ImVec2& size = ImVec2 0  0, ImGuiDockNodeFlags flags = 0, const ImGuiWindowClass* window_class = NULL);
// Unsupported arg type  const ImGuiWindowClass* window_class = NULL
//    IMGUI_API ImGuiID       DockSpaceOverViewport(ImGuiViewport* viewport = NULL, ImGuiDockNodeFlags flags = 0, const ImGuiWindowClass* window_class = NULL);
// Unsupported arg type  const ImGuiWindowClass* window_class = NULL
//    IMGUI_API void          SetNextWindowDockID(ImGuiID dock_id, ImGuiCond cond = 0);           // set next window dock id (FIXME-DOCK)
IMGUI_FUNCTION(SetNextWindowDockID)
UINT_ARG(dock_id)
OPTIONAL_ENUM_ARG(cond, 0)
CALL_FUNCTION_NO_RET(SetNextWindowDockID, dock_id, cond)
END_IMGUI_FUNC

//    IMGUI_API void          SetNextWindowClass(const ImGuiWindowClass* window_class);           // set next window class (rare/advanced uses: provide hints to the platform back-end via altered viewport flags and parent/child info)
// Unsupported arg type const ImGuiWindowClass* window_class
//    IMGUI_API ImGuiID       GetWindowDockID();
IMGUI_FUNCTION(GetWindowDockID)
CALL_FUNCTION(GetWindowDockID, unsigned int)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsWindowDocked();                                                   // is current window docked into another window?
IMGUI_FUNCTION(IsWindowDocked)
CALL_FUNCTION(IsWindowDocked, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          LogToTTY(int auto_open_depth = -1);                                 // start logging to tty (stdout)
IMGUI_FUNCTION(LogToTTY)
OPTIONAL_INT_ARG(auto_open_depth, -1)
CALL_FUNCTION_NO_RET(LogToTTY, auto_open_depth)
END_IMGUI_FUNC

//    IMGUI_API void          LogToFile(int auto_open_depth = -1, const char* filename = NULL);   // start logging to file
IMGUI_FUNCTION(LogToFile)
OPTIONAL_INT_ARG(auto_open_depth, -1)
OPTIONAL_LABEL_ARG(filename, NULL)
CALL_FUNCTION_NO_RET(LogToFile, auto_open_depth, filename)
END_IMGUI_FUNC

//    IMGUI_API void          LogToClipboard(int auto_open_depth = -1);                           // start logging to OS clipboard
IMGUI_FUNCTION(LogToClipboard)
OPTIONAL_INT_ARG(auto_open_depth, -1)
CALL_FUNCTION_NO_RET(LogToClipboard, auto_open_depth)
END_IMGUI_FUNC

//    IMGUI_API void          LogFinish();                                                        // stop logging (close file, etc.)
IMGUI_FUNCTION(LogFinish)
CALL_FUNCTION_NO_RET(LogFinish)
END_IMGUI_FUNC

//    IMGUI_API void          LogButtons();                                                       // helper to display buttons for logging to tty/file/clipboard
IMGUI_FUNCTION(LogButtons)
CALL_FUNCTION_NO_RET(LogButtons)
END_IMGUI_FUNC

//    IMGUI_API void          LogText(const char* fmt, ...) IM_FMTARGS(1);                        // pass text data straight to log (without being displayed)
// Unsupported arg type  ...) IM_FMTARGS(1
//    IMGUI_API bool          BeginDragDropSource(ImGuiDragDropFlags flags = 0);                                      // call when the current item is active. If this return true, you can call SetDragDropPayload() + EndDragDropSource()
IMGUI_FUNCTION(BeginDragDropSource)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginDragDropSource, bool, flags)
IF_RET_ADD_END_STACK(15)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          SetDragDropPayload(const char* type, const void* data, size_t sz, ImGuiCond cond = 0);  // type is a user defined string of maximum 32 characters. Strings starting with '_' are reserved for dear imgui internal types. Data is copied and held by imgui.
// Unsupported arg type  const void* data
// Unsupported arg type  size_t sz
//    IMGUI_API void          EndDragDropSource();                                                                    // only call EndDragDropSource() if BeginDragDropSource() returns true!
IMGUI_FUNCTION(EndDragDropSource)
CALL_FUNCTION_NO_RET(EndDragDropSource)
POP_END_STACK(15)
END_IMGUI_FUNC

//    IMGUI_API bool                  BeginDragDropTarget();                                                          // call after submitting an item that may receive a payload. If this returns true, you can call AcceptDragDropPayload() + EndDragDropTarget()
IMGUI_FUNCTION(BeginDragDropTarget)
CALL_FUNCTION(BeginDragDropTarget, bool)
IF_RET_ADD_END_STACK(16)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API const ImGuiPayload*   AcceptDragDropPayload(const char* type, ImGuiDragDropFlags flags = 0);          // accept contents of a given type. If ImGuiDragDropFlags_AcceptBeforeDelivery is set you can peek into the payload before the mouse button is released.
// Unsupported return type const
//    IMGUI_API void                  EndDragDropTarget();                                                            // only call EndDragDropTarget() if BeginDragDropTarget() returns true!
IMGUI_FUNCTION(EndDragDropTarget)
CALL_FUNCTION_NO_RET(EndDragDropTarget)
POP_END_STACK(16)
END_IMGUI_FUNC

//    IMGUI_API const ImGuiPayload*   GetDragDropPayload();                                                           // peek directly into the current payload from anywhere. may return NULL. use ImGuiPayload::IsDataType() to test for the payload type.
// Unsupported return type const
//    IMGUI_API void          PushClipRect(const ImVec2& clip_rect_min, const ImVec2& clip_rect_max, bool intersect_with_current_clip_rect);
IMGUI_FUNCTION(PushClipRect)
IM_VEC_2_ARG(clip_rect_min)
IM_VEC_2_ARG(clip_rect_max)
BOOL_ARG(intersect_with_current_clip_rect)
CALL_FUNCTION_NO_RET(PushClipRect, clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
END_IMGUI_FUNC

//    IMGUI_API void          PopClipRect();
IMGUI_FUNCTION(PopClipRect)
CALL_FUNCTION_NO_RET(PopClipRect)
END_IMGUI_FUNC

//    IMGUI_API void          SetItemDefaultFocus();                                              // make last item the default focused item of a window.
IMGUI_FUNCTION(SetItemDefaultFocus)
CALL_FUNCTION_NO_RET(SetItemDefaultFocus)
END_IMGUI_FUNC

//    IMGUI_API void          SetKeyboardFocusHere(int offset = 0);                               // focus keyboard on the next widget. Use positive 'offset' to access sub components of a multiple component widget. Use -1 to access previous widget.
IMGUI_FUNCTION(SetKeyboardFocusHere)
OPTIONAL_INT_ARG(offset, 0)
CALL_FUNCTION_NO_RET(SetKeyboardFocusHere, offset)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemHovered(ImGuiHoveredFlags flags = 0);                         // is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options.
IMGUI_FUNCTION(IsItemHovered)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(IsItemHovered, bool, flags)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemActive();                                                     // is the last item active? (e.g. button being held, text field being edited. This will continuously return true while holding mouse button on an item. Items that don't interact will always return false)
IMGUI_FUNCTION(IsItemActive)
CALL_FUNCTION(IsItemActive, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemFocused();                                                    // is the last item focused for keyboard/gamepad navigation?
IMGUI_FUNCTION(IsItemFocused)
CALL_FUNCTION(IsItemFocused, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemClicked(ImGuiMouseButton mouse_button = 0);                   // is the last item clicked? (e.g. button/node just clicked on) == IsMouseClicked(mouse_button) && IsItemHovered()
IMGUI_FUNCTION(IsItemClicked)
OPTIONAL_ENUM_ARG(mouse_button, 0)
CALL_FUNCTION(IsItemClicked, bool, mouse_button)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemVisible();                                                    // is the last item visible? (items may be out of sight because of clipping/scrolling)
IMGUI_FUNCTION(IsItemVisible)
CALL_FUNCTION(IsItemVisible, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemEdited();                                                     // did the last item modify its underlying value this frame? or was pressed? This is generally the same as the "bool" return value of many widgets.
IMGUI_FUNCTION(IsItemEdited)
CALL_FUNCTION(IsItemEdited, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemActivated();                                                  // was the last item just made active (item was previously inactive).
IMGUI_FUNCTION(IsItemActivated)
CALL_FUNCTION(IsItemActivated, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemDeactivated();                                                // was the last item just made inactive (item was previously active). Useful for Undo/Redo patterns with widgets that requires continuous editing.
IMGUI_FUNCTION(IsItemDeactivated)
CALL_FUNCTION(IsItemDeactivated, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemDeactivatedAfterEdit();                                       // was the last item just made inactive and made a value change when it was active? (e.g. Slider/Drag moved). Useful for Undo/Redo patterns with widgets that requires continuous editing. Note that you may get false positives (some widgets such as Combo()/ListBox()/Selectable() will return true even when clicking an already selected item).
IMGUI_FUNCTION(IsItemDeactivatedAfterEdit)
CALL_FUNCTION(IsItemDeactivatedAfterEdit, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsItemToggledOpen();                                                // was the last item open state toggled? set by TreeNode().
IMGUI_FUNCTION(IsItemToggledOpen)
CALL_FUNCTION(IsItemToggledOpen, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsAnyItemHovered();                                                 // is any item hovered?
IMGUI_FUNCTION(IsAnyItemHovered)
CALL_FUNCTION(IsAnyItemHovered, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsAnyItemActive();                                                  // is any item active?
IMGUI_FUNCTION(IsAnyItemActive)
CALL_FUNCTION(IsAnyItemActive, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsAnyItemFocused();                                                 // is any item focused?
IMGUI_FUNCTION(IsAnyItemFocused)
CALL_FUNCTION(IsAnyItemFocused, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetItemRectMin();                                                   // get upper-left bounding rectangle of the last item (screen space)
IMGUI_FUNCTION(GetItemRectMin)
CALL_FUNCTION(GetItemRectMin, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetItemRectMax();                                                   // get lower-right bounding rectangle of the last item (screen space)
IMGUI_FUNCTION(GetItemRectMax)
CALL_FUNCTION(GetItemRectMax, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetItemRectSize();                                                  // get size of last item
IMGUI_FUNCTION(GetItemRectSize)
CALL_FUNCTION(GetItemRectSize, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API void          SetItemAllowOverlap();                                              // allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area.
IMGUI_FUNCTION(SetItemAllowOverlap)
CALL_FUNCTION_NO_RET(SetItemAllowOverlap)
END_IMGUI_FUNC

//    IMGUI_API bool          IsRectVisible(const ImVec2& size);                                  // test if rectangle (of given size, starting from cursor position) is visible / not clipped.
IMGUI_FUNCTION(IsRectVisible)
IM_VEC_2_ARG(size)
CALL_FUNCTION(IsRectVisible, bool, size)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsRectVisible(const ImVec2& rect_min, const ImVec2& rect_max);      // test if rectangle (in screen space) is visible / not clipped. to perform coarse clipping on user's side.
IMGUI_FUNCTION(IsRectVisible_2)
IM_VEC_2_ARG(rect_min)
IM_VEC_2_ARG(rect_max)
CALL_FUNCTION(IsRectVisible, bool, rect_min, rect_max)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API double        GetTime();                                                          // get global imgui time. incremented by io.DeltaTime every frame.
IMGUI_FUNCTION(GetTime)
CALL_FUNCTION(GetTime, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API int           GetFrameCount();                                                    // get global imgui frame count. incremented by 1 every frame.
IMGUI_FUNCTION(GetFrameCount)
CALL_FUNCTION(GetFrameCount, float)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API ImDrawList*   GetBackgroundDrawList();                                            // get background draw list for the viewport associated to the current window. this draw list will be the first rendering one. Useful to quickly draw shapes/text behind dear imgui contents.
// Unsupported return type ImDrawList*
//    IMGUI_API ImDrawList*   GetForegroundDrawList();                                            // get foreground draw list for the viewport associated to the current window. this draw list will be the last rendered one. Useful to quickly draw shapes/text over dear imgui contents.
// Unsupported return type ImDrawList*
//    IMGUI_API ImDrawList*   GetBackgroundDrawList(ImGuiViewport* viewport);                     // get background draw list for the given viewport. this draw list will be the first rendering one. Useful to quickly draw shapes/text behind dear imgui contents.
// Unsupported return type ImDrawList*
// Unsupported arg type ImGuiViewport* viewport
//    IMGUI_API ImDrawList*   GetForegroundDrawList(ImGuiViewport* viewport);                     // get foreground draw list for the given viewport. this draw list will be the last rendered one. Useful to quickly draw shapes/text over dear imgui contents.
// Unsupported return type ImDrawList*
// Unsupported arg type ImGuiViewport* viewport
//    IMGUI_API ImDrawListSharedData* GetDrawListSharedData();                                    // you may use this when creating your own ImDrawList instances.
// Unsupported return type ImDrawListSharedData*
//    IMGUI_API const char*   GetStyleColorName(ImGuiCol idx);                                    // get a string corresponding to the enum value (for display, saving, etc.).
IMGUI_FUNCTION(GetStyleColorName)
ENUM_ARG(idx)
CALL_FUNCTION(GetStyleColorName, const char*, idx)
PUSH_STRING(ret)
PUSH_LAST_STRING(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetStateStorage(ImGuiStorage* storage);                             // replace current window storage with our own (if you want to manipulate it yourself, typically clear subsection of it)
// Unsupported arg type ImGuiStorage* storage
//    IMGUI_API ImGuiStorage* GetStateStorage();
// Unsupported return type ImGuiStorage*
//    IMGUI_API void          CalcListClipping(int items_count, float items_height, int* out_items_display_start, int* out_items_display_end);    // calculate coarse clipping for large list of evenly sized items. Prefer using the ImGuiListClipper higher-level helper if you can.
IMGUI_FUNCTION(CalcListClipping)
INT_ARG(items_count)
NUMBER_ARG(items_height)
INT_POINTER_ARG(out_items_display_start)
INT_POINTER_ARG(out_items_display_end)
CALL_FUNCTION_NO_RET(CalcListClipping, items_count, items_height, out_items_display_start, out_items_display_end)
END_INT_POINTER(out_items_display_start)
END_INT_POINTER(out_items_display_end)
END_IMGUI_FUNC

//    IMGUI_API bool          BeginChildFrame(ImGuiID id, const ImVec2& size, ImGuiWindowFlags flags = 0); // helper to create a child window / scrolling region that looks like a normal widget frame
IMGUI_FUNCTION(BeginChildFrame)
UINT_ARG(id)
IM_VEC_2_ARG(size)
OPTIONAL_ENUM_ARG(flags, 0)
CALL_FUNCTION(BeginChildFrame, bool, id, size, flags)
IF_RET_ADD_END_STACK(17)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API void          EndChildFrame();                                                    // always call EndChildFrame() regardless of BeginChildFrame() return values (which indicates a collapsed/clipped window)
IMGUI_FUNCTION(EndChildFrame)
CALL_FUNCTION_NO_RET(EndChildFrame)
POP_END_STACK(17)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        CalcTextSize(const char* text, const char* text_end = NULL, bool hide_text_after_double_hash = false, float wrap_width = -1.0f);
IMGUI_FUNCTION(CalcTextSize)
LABEL_ARG(text)
OPTIONAL_LABEL_ARG(text_end, NULL)
OPTIONAL_BOOL_ARG(hide_text_after_double_hash, false)
OPTIONAL_NUMBER_ARG(wrap_width, -1.0f)
CALL_FUNCTION(CalcTextSize, ImVec2, text, text_end, hide_text_after_double_hash, wrap_width)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec4        ColorConvertU32ToFloat4(ImU32 in);
// Unsupported return type ImVec4
//    IMGUI_API ImU32         ColorConvertFloat4ToU32(const ImVec4& in);
IMGUI_FUNCTION(ColorConvertFloat4ToU32)
IM_VEC_4_ARG(in)
CALL_FUNCTION(ColorConvertFloat4ToU32, unsigned int, in)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          ColorConvertRGBtoHSV(float r, float g, float b, float& out_h, float& out_s, float& out_v);
// Unsupported arg type  float& out_h
// Unsupported arg type  float& out_s
// Unsupported arg type  float& out_v
//    IMGUI_API void          ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b);
// Unsupported arg type  float& out_r
// Unsupported arg type  float& out_g
// Unsupported arg type  float& out_b
//    IMGUI_API int           GetKeyIndex(ImGuiKey imgui_key);                                    // map ImGuiKey_* values into user's key index. == io.KeyMap[key]
IMGUI_FUNCTION(GetKeyIndex)
ENUM_ARG(imgui_key)
CALL_FUNCTION(GetKeyIndex, float, imgui_key)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsKeyDown(int user_key_index);                                      // is key being held. == io.KeysDown[user_key_index].
IMGUI_FUNCTION(IsKeyDown)
INT_ARG(user_key_index)
CALL_FUNCTION(IsKeyDown, bool, user_key_index)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsKeyPressed(int user_key_index, bool repeat = true);               // was key pressed (went from !Down to Down)? if repeat=true, uses io.KeyRepeatDelay / KeyRepeatRate
IMGUI_FUNCTION(IsKeyPressed)
INT_ARG(user_key_index)
OPTIONAL_BOOL_ARG(repeat, true)
CALL_FUNCTION(IsKeyPressed, bool, user_key_index, repeat)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsKeyReleased(int user_key_index);                                  // was key released (went from Down to !Down)?
IMGUI_FUNCTION(IsKeyReleased)
INT_ARG(user_key_index)
CALL_FUNCTION(IsKeyReleased, bool, user_key_index)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API int           GetKeyPressedAmount(int key_index, float repeat_delay, float rate); // uses provided repeat rate/delay. return a count, most often 0 or 1 but might be >1 if RepeatRate is small enough that DeltaTime > RepeatRate
IMGUI_FUNCTION(GetKeyPressedAmount)
INT_ARG(key_index)
NUMBER_ARG(repeat_delay)
NUMBER_ARG(rate)
CALL_FUNCTION(GetKeyPressedAmount, float, key_index, repeat_delay, rate)
PUSH_NUMBER(ret)
PUSH_LAST_NUMBER(ret)
END_IMGUI_FUNC

//    IMGUI_API void          CaptureKeyboardFromApp(bool want_capture_keyboard_value = true);    // attention: misleading name! manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application to handle). e.g. force capture keyboard when your widget is being hovered. This is equivalent to setting "io.WantCaptureKeyboard = want_capture_keyboard_value"; after the next NewFrame() call.
IMGUI_FUNCTION(CaptureKeyboardFromApp)
OPTIONAL_BOOL_ARG(want_capture_keyboard_value, true)
CALL_FUNCTION_NO_RET(CaptureKeyboardFromApp, want_capture_keyboard_value)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseDown(ImGuiMouseButton button);                               // is mouse button held?
IMGUI_FUNCTION(IsMouseDown)
ENUM_ARG(button)
CALL_FUNCTION(IsMouseDown, bool, button)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseClicked(ImGuiMouseButton button, bool repeat = false);       // did mouse button clicked? (went from !Down to Down)
IMGUI_FUNCTION(IsMouseClicked)
ENUM_ARG(button)
OPTIONAL_BOOL_ARG(repeat, false)
CALL_FUNCTION(IsMouseClicked, bool, button, repeat)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseReleased(ImGuiMouseButton button);                           // did mouse button released? (went from Down to !Down)
IMGUI_FUNCTION(IsMouseReleased)
ENUM_ARG(button)
CALL_FUNCTION(IsMouseReleased, bool, button)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseDoubleClicked(ImGuiMouseButton button);                      // did mouse button double-clicked? (note that a double-click will also report IsMouseClicked() == true)
IMGUI_FUNCTION(IsMouseDoubleClicked)
ENUM_ARG(button)
CALL_FUNCTION(IsMouseDoubleClicked, bool, button)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseHoveringRect(const ImVec2& r_min, const ImVec2& r_max, bool clip = true);// is mouse hovering given bounding rect (in screen space). clipped by current clipping settings, but disregarding of other consideration of focus/window ordering/popup-block.
IMGUI_FUNCTION(IsMouseHoveringRect)
IM_VEC_2_ARG(r_min)
IM_VEC_2_ARG(r_max)
OPTIONAL_BOOL_ARG(clip, true)
CALL_FUNCTION(IsMouseHoveringRect, bool, r_min, r_max, clip)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMousePosValid(const ImVec2* mouse_pos = NULL);                    // by convention we use (-FLT_MAX,-FLT_MAX) to denote that there is no mouse available
// Unsupported arg type const ImVec2* mouse_pos = NULL
//    IMGUI_API bool          IsAnyMouseDown();                                                   // is any mouse button held?
IMGUI_FUNCTION(IsAnyMouseDown)
CALL_FUNCTION(IsAnyMouseDown, bool)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetMousePos();                                                      // shortcut to ImGui::GetIO().MousePos provided by user, to be consistent with other calls
IMGUI_FUNCTION(GetMousePos)
CALL_FUNCTION(GetMousePos, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetMousePosOnOpeningCurrentPopup();                                 // retrieve mouse position at the time of opening popup we have BeginPopup() into (helper to avoid user backing that value themselves)
IMGUI_FUNCTION(GetMousePosOnOpeningCurrentPopup)
CALL_FUNCTION(GetMousePosOnOpeningCurrentPopup, ImVec2)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API bool          IsMouseDragging(ImGuiMouseButton button, float lock_threshold = -1.0f);         // is mouse dragging? (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold)
IMGUI_FUNCTION(IsMouseDragging)
ENUM_ARG(button)
OPTIONAL_NUMBER_ARG(lock_threshold, -1.0f)
CALL_FUNCTION(IsMouseDragging, bool, button, lock_threshold)
PUSH_BOOL(ret)
PUSH_LAST_BOOL(ret)
END_IMGUI_FUNC

//    IMGUI_API ImVec2        GetMouseDragDelta(ImGuiMouseButton button = 0, float lock_threshold = -1.0f);   // return the delta from the initial clicking position while the mouse button is pressed or was just released. This is locked and return 0.0f until the mouse moves past a distance threshold at least once (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold)
IMGUI_FUNCTION(GetMouseDragDelta)
OPTIONAL_ENUM_ARG(button, 0)
OPTIONAL_NUMBER_ARG(lock_threshold, -1.0f)
CALL_FUNCTION(GetMouseDragDelta, ImVec2, button, lock_threshold)
PUSH_NUMBER(ret.x)
PUSH_NUMBER(ret.y)
PUSH_LAST_NUMBER(ret.x)
PUSH_LAST_NUMBER(ret.y)
END_IMGUI_FUNC

//    IMGUI_API void          ResetMouseDragDelta(ImGuiMouseButton button = 0);                   //
IMGUI_FUNCTION(ResetMouseDragDelta)
OPTIONAL_ENUM_ARG(button, 0)
CALL_FUNCTION_NO_RET(ResetMouseDragDelta, button)
END_IMGUI_FUNC

//    IMGUI_API ImGuiMouseCursor GetMouseCursor();                                                // get desired cursor type, reset in ImGui::NewFrame(), this is updated during the frame. valid before Render(). If you use software rendering by setting io.MouseDrawCursor ImGui will render those for you
// Unsupported return type ImGuiMouseCursor
//    IMGUI_API void          SetMouseCursor(ImGuiMouseCursor cursor_type);                       // set desired cursor type
IMGUI_FUNCTION(SetMouseCursor)
ENUM_ARG(cursor_type)
CALL_FUNCTION_NO_RET(SetMouseCursor, cursor_type)
END_IMGUI_FUNC

//    IMGUI_API void          CaptureMouseFromApp(bool want_capture_mouse_value = true);          // attention: misleading name! manually override io.WantCaptureMouse flag next frame (said flag is entirely left for your application to handle). This is equivalent to setting "io.WantCaptureMouse = want_capture_mouse_value;" after the next NewFrame() call.
IMGUI_FUNCTION(CaptureMouseFromApp)
OPTIONAL_BOOL_ARG(want_capture_mouse_value, true)
CALL_FUNCTION_NO_RET(CaptureMouseFromApp, want_capture_mouse_value)
END_IMGUI_FUNC

//    IMGUI_API const char*   GetClipboardText();
IMGUI_FUNCTION(GetClipboardText)
CALL_FUNCTION(GetClipboardText, const char*)
PUSH_STRING(ret)
PUSH_LAST_STRING(ret)
END_IMGUI_FUNC

//    IMGUI_API void          SetClipboardText(const char* text);
IMGUI_FUNCTION(SetClipboardText)
LABEL_ARG(text)
CALL_FUNCTION_NO_RET(SetClipboardText, text)
END_IMGUI_FUNC

//    IMGUI_API void          LoadIniSettingsFromDisk(const char* ini_filename);                  // call after CreateContext() and before the first call to NewFrame(). NewFrame() automatically calls LoadIniSettingsFromDisk(io.IniFilename).
IMGUI_FUNCTION(LoadIniSettingsFromDisk)
LABEL_ARG(ini_filename)
CALL_FUNCTION_NO_RET(LoadIniSettingsFromDisk, ini_filename)
END_IMGUI_FUNC

//    IMGUI_API void          LoadIniSettingsFromMemory(const char* ini_data, size_t ini_size=0); // call after CreateContext() and before the first call to NewFrame() to provide .ini data from your own data source.
IMGUI_FUNCTION(LoadIniSettingsFromMemory)
LABEL_ARG(ini_data)
DEFAULT_ARG(size_t, ini_size, 0)
CALL_FUNCTION_NO_RET(LoadIniSettingsFromMemory, ini_data)
END_IMGUI_FUNC

//    IMGUI_API void          SaveIniSettingsToDisk(const char* ini_filename);                    // this is automatically called (if io.IniFilename is not empty) a few seconds after any modification that should be reflected in the .ini file (and also by DestroyContext).
IMGUI_FUNCTION(SaveIniSettingsToDisk)
LABEL_ARG(ini_filename)
CALL_FUNCTION_NO_RET(SaveIniSettingsToDisk, ini_filename)
END_IMGUI_FUNC

//    IMGUI_API const char*   SaveIniSettingsToMemory(size_t* out_ini_size = NULL);               // return a zero-terminated string with the .ini data which you can save by your own mean. call when io.WantSaveIniSettings is set, then save data by your own mean and clear io.WantSaveIniSettings.
IMGUI_FUNCTION(SaveIniSettingsToMemory)
DEFAULT_ARG(size_t*, out_ini_size, NULL)
CALL_FUNCTION(SaveIniSettingsToMemory, const char*)
PUSH_STRING(ret)
PUSH_LAST_STRING(ret)
END_IMGUI_FUNC

//    IMGUI_API bool          DebugCheckVersionAndDataLayout(const char* version_str, size_t sz_io, size_t sz_style, size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx); // This is called by IMGUI_CHECKVERSION() macro.
// Unsupported arg type  size_t sz_io
// Unsupported arg type  size_t sz_style
// Unsupported arg type  size_t sz_vec2
// Unsupported arg type  size_t sz_vec4
// Unsupported arg type  size_t sz_drawvert
// Unsupported arg type  size_t sz_drawidx
//    IMGUI_API void          SetAllocatorFunctions(void* (*alloc_func)(size_t sz, void* user_data), void (*free_func)(void* ptr, void* user_data), void* user_data = NULL);
// Unsupported arg type void* (*alloc_func)(size_t sz
// Unsupported arg type  void* user_data)
// Unsupported arg type  void (*free_func)(void* ptr
// Unsupported arg type  void* user_data)
//    IMGUI_API void*         MemAlloc(size_t size);
// Unsupported return type void*
// Unsupported arg type size_t size
//    IMGUI_API void          MemFree(void* ptr);
// Unsupported arg type void* ptr
//    IMGUI_API ImGuiPlatformIO&  GetPlatformIO();                                                // platform/renderer functions, for back-end to setup + viewports list.
// Unsupported return type ImGuiPlatformIO&
//    IMGUI_API ImGuiViewport*    GetMainViewport();                                              // main viewport. same as GetPlatformIO().MainViewport == GetPlatformIO().Viewports[0].
// Unsupported return type ImGuiViewport*
//    IMGUI_API void              UpdatePlatformWindows();                                        // call in main loop. will call CreateWindow/ResizeWindow/etc. platform functions for each secondary viewport, and DestroyWindow for each inactive viewport.
IMGUI_FUNCTION(UpdatePlatformWindows)
CALL_FUNCTION_NO_RET(UpdatePlatformWindows)
END_IMGUI_FUNC

//    IMGUI_API void              RenderPlatformWindowsDefault(void* platform_render_arg = NULL, void* renderer_render_arg = NULL); // call in main loop. will call RenderWindow/SwapBuffers platform functions for each secondary viewport which doesn't have the ImGuiViewportFlags_Minimized flag set. May be reimplemented by user for custom rendering needs.
IMGUI_FUNCTION(RenderPlatformWindowsDefault)
DEFAULT_ARG(void*, platform_render_arg, NULL)
DEFAULT_ARG(void*, renderer_render_arg, NULL)
CALL_FUNCTION_NO_RET(RenderPlatformWindowsDefault)
END_IMGUI_FUNC

//    IMGUI_API void              DestroyPlatformWindows();                                       // call DestroyWindow platform functions for all viewports. call from back-end Shutdown() if you need to close platform windows before imgui shutdown. otherwise will be called by DestroyContext().
IMGUI_FUNCTION(DestroyPlatformWindows)
CALL_FUNCTION_NO_RET(DestroyPlatformWindows)
END_IMGUI_FUNC

//    IMGUI_API ImGuiViewport*    FindViewportByID(ImGuiID id);                                   // this is a helper for back-ends.
// Unsupported return type ImGuiViewport*
//    IMGUI_API ImGuiViewport*    FindViewportByPlatformHandle(void* platform_handle);            // this is a helper for back-ends. the type platform_handle is decided by the back-end (e.g. HWND, MyWindow*, GLFWwindow* etc.)
// Unsupported return type ImGuiViewport*
// Unsupported arg type void* platform_handle
END_STACK_START
END_STACK_OPTION(0, EndFrame)
END_STACK_OPTION(1, End)
END_STACK_OPTION(2, EndChild)
END_STACK_OPTION(3, PopStyleVar)
END_STACK_OPTION(4, EndGroup)
END_STACK_OPTION(5, EndCombo)
END_STACK_OPTION(6, TreePop)
END_STACK_OPTION(7, EndMenuBar)
END_STACK_OPTION(8, EndMainMenuBar)
END_STACK_OPTION(9, EndMenu)
END_STACK_OPTION(10, EndTooltip)
END_STACK_OPTION(11, EndPopup)
END_STACK_OPTION(12, EndTable)
END_STACK_OPTION(13, EndTabBar)
END_STACK_OPTION(14, EndTabItem)
END_STACK_OPTION(15, EndDragDropSource)
END_STACK_OPTION(16, EndDragDropTarget)
END_STACK_OPTION(17, EndChildFrame)
END_STACK_END
