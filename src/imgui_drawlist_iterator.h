//struct ImDrawList

//    IMGUI_API void  PushClipRect(ImVec2 clip_rect_min, ImVec2 clip_rect_max, bool intersect_with_current_clip_rect = false);  // Render-level scissoring. This is passed down to your render function but not used for CPU-side coarse clipping. Prefer using higher-level ImGui::PushClipRect() to affect logic (hit-testing and widget culling)
//Not allowed to use this function
//    IMGUI_API void  PushClipRectFullScreen();
IMGUI_FUNCTION_DRAW_LIST(PushClipRectFullScreen)
DRAW_LIST_CALL_FUNCTION_NO_RET(PushClipRectFullScreen)
END_IMGUI_FUNC

//    IMGUI_API void  PopClipRect();
//Not allowed to use this function
//    IMGUI_API void  PushTextureID(ImTextureID texture_id);
IMGUI_FUNCTION_DRAW_LIST(PushTextureID)
TEXTURE_ARG(texture_id)
DRAW_LIST_CALL_FUNCTION_NO_RET(PushTextureID, texture_id)
END_IMGUI_FUNC

//    IMGUI_API void  PopTextureID();
IMGUI_FUNCTION_DRAW_LIST(PopTextureID)
DRAW_LIST_CALL_FUNCTION_NO_RET(PopTextureID)
END_IMGUI_FUNC

//    inline ImVec2   GetClipRectMin() const { const ImVec4& cr = _ClipRectStack.back(); return ImVec2 cr.x  cr.y; }
// Unsupported arg type ) const { const ImVec4& cr = _ClipRectStack.back(
//    inline ImVec2   GetClipRectMax() const { const ImVec4& cr = _ClipRectStack.back(); return ImVec2 cr.z  cr.w; }
// Unsupported arg type ) const { const ImVec4& cr = _ClipRectStack.back(
//    IMGUI_API void  AddLine(const ImVec2& p1, const ImVec2& p2, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION_DRAW_LIST(AddLine)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
UINT_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddLine, p1, p2, col, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddRect(const ImVec2& p_min, const ImVec2& p_max, ImU32 col, float rounding = 0.0f, ImDrawCornerFlags rounding_corners = ImDrawCornerFlags_All, float thickness = 1.0f);   // a: upper-left, b: lower-right (== upper-left + size), rounding_corners_flags: 4 bits corresponding to which corner to round
IMGUI_FUNCTION_DRAW_LIST(AddRect)
IM_VEC_2_ARG(p_min)
IM_VEC_2_ARG(p_max)
UINT_ARG(col)
OPTIONAL_NUMBER_ARG(rounding, 0.0f)
OPTIONAL_ENUM_ARG(rounding_corners, ImDrawCornerFlags_All)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddRect, p_min, p_max, col, rounding, rounding_corners, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddRectFilled(const ImVec2& p_min, const ImVec2& p_max, ImU32 col, float rounding = 0.0f, ImDrawCornerFlags rounding_corners = ImDrawCornerFlags_All);                     // a: upper-left, b: lower-right (== upper-left + size)
IMGUI_FUNCTION_DRAW_LIST(AddRectFilled)
IM_VEC_2_ARG(p_min)
IM_VEC_2_ARG(p_max)
UINT_ARG(col)
OPTIONAL_NUMBER_ARG(rounding, 0.0f)
OPTIONAL_ENUM_ARG(rounding_corners, ImDrawCornerFlags_All)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddRectFilled, p_min, p_max, col, rounding, rounding_corners)
END_IMGUI_FUNC

//    IMGUI_API void  AddRectFilledMultiColor(const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left);
IMGUI_FUNCTION_DRAW_LIST(AddRectFilledMultiColor)
IM_VEC_2_ARG(p_min)
IM_VEC_2_ARG(p_max)
UINT_ARG(col_upr_left)
UINT_ARG(col_upr_right)
UINT_ARG(col_bot_right)
UINT_ARG(col_bot_left)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddRectFilledMultiColor, p_min, p_max, col_upr_left, col_upr_right, col_bot_right, col_bot_left)
END_IMGUI_FUNC

//    IMGUI_API void  AddQuad(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION_DRAW_LIST(AddQuad)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
IM_VEC_2_ARG(p4)
UINT_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddQuad, p1, p2, p3, p4, col, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddQuadFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col);
IMGUI_FUNCTION_DRAW_LIST(AddQuadFilled)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
IM_VEC_2_ARG(p4)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddQuadFilled, p1, p2, p3, p4, col)
END_IMGUI_FUNC

//    IMGUI_API void  AddTriangle(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, ImU32 col, float thickness = 1.0f);
IMGUI_FUNCTION_DRAW_LIST(AddTriangle)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
UINT_ARG(col)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddTriangle, p1, p2, p3, col, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddTriangleFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, ImU32 col);
IMGUI_FUNCTION_DRAW_LIST(AddTriangleFilled)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddTriangleFilled, p1, p2, p3, col)
END_IMGUI_FUNC

//    IMGUI_API void  AddCircle(const ImVec2& center, float radius, ImU32 col, int num_segments = 12, float thickness = 1.0f);
IMGUI_FUNCTION_DRAW_LIST(AddCircle)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
UINT_ARG(col)
OPTIONAL_INT_ARG(num_segments, 12)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddCircle, center, radius, col, num_segments, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddCircleFilled(const ImVec2& center, float radius, ImU32 col, int num_segments = 12);
IMGUI_FUNCTION_DRAW_LIST(AddCircleFilled)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
UINT_ARG(col)
OPTIONAL_INT_ARG(num_segments, 12)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddCircleFilled, center, radius, col, num_segments)
END_IMGUI_FUNC

//    IMGUI_API void  AddNgon(const ImVec2& center, float radius, ImU32 col, int num_segments, float thickness = 1.0f);
IMGUI_FUNCTION_DRAW_LIST(AddNgon)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
UINT_ARG(col)
INT_ARG(num_segments)
OPTIONAL_NUMBER_ARG(thickness, 1.0f)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddNgon, center, radius, col, num_segments, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddNgonFilled(const ImVec2& center, float radius, ImU32 col, int num_segments);
IMGUI_FUNCTION_DRAW_LIST(AddNgonFilled)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
UINT_ARG(col)
INT_ARG(num_segments)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddNgonFilled, center, radius, col, num_segments)
END_IMGUI_FUNC

//    IMGUI_API void  AddText(const ImVec2& pos, ImU32 col, const char* text_begin, const char* text_end = NULL);
IMGUI_FUNCTION_DRAW_LIST(AddText)
IM_VEC_2_ARG(pos)
UINT_ARG(col)
LABEL_ARG(text_begin)
OPTIONAL_LABEL_ARG(text_end, NULL)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddText, pos, col, text_begin, text_end)
END_IMGUI_FUNC

//    IMGUI_API void  AddText(const ImFont* font, float font_size, const ImVec2& pos, ImU32 col, const char* text_begin, const char* text_end = NULL, float wrap_width = 0.0f, const ImVec4* cpu_fine_clip_rect = NULL);
// Unsupported arg type const ImFont* font
// Unsupported arg type  const ImVec4* cpu_fine_clip_rect = NULL
//    IMGUI_API void  AddPolyline(const ImVec2* points, int num_points, ImU32 col, bool closed, float thickness);
IMGUI_FUNCTION_DRAW_LIST(AddPolyline)
IM_VEC_2_ARRAY_ARG(points)
INT_ARG(num_points)
UINT_ARG(col)
BOOL_ARG(closed)
NUMBER_ARG(thickness)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddPolyline, points, num_points, col, closed, thickness)
END_IMGUI_FUNC

//    IMGUI_API void  AddConvexPolyFilled(const ImVec2* points, int num_points, ImU32 col); // Note: Anti-aliased filling requires points to be in clockwise order.
IMGUI_FUNCTION_DRAW_LIST(AddConvexPolyFilled)
IM_VEC_2_ARRAY_ARG(points)
INT_ARG(num_points)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddConvexPolyFilled, points, num_points, col)
END_IMGUI_FUNC

//    IMGUI_API void  AddBezierCurve(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col, float thickness, int num_segments = 0);
IMGUI_FUNCTION_DRAW_LIST(AddBezierCurve)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
IM_VEC_2_ARG(p4)
UINT_ARG(col)
NUMBER_ARG(thickness)
OPTIONAL_INT_ARG(num_segments, 0)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddBezierCurve, p1, p2, p3, p4, col, thickness, num_segments)
END_IMGUI_FUNC

//    IMGUI_API void  AddImage(ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min = ImVec2 0  0, const ImVec2& uv_max = ImVec2 1  1, ImU32 col = IM_COL32_WHITE);
IMGUI_FUNCTION_DRAW_LIST(AddImage)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(p_min)
IM_VEC_2_ARG(p_max)
OPTIONAL_IM_VEC_2_ARG(uv_min, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv_max, 1, 1)
OPTIONAL_UINT_ARG(col, IM_COL32_WHITE)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddImage, user_texture_id, p_min, p_max, uv_min, uv_max, col)
END_IMGUI_FUNC

//    IMGUI_API void  AddImageQuad(ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1 = ImVec2 0  0, const ImVec2& uv2 = ImVec2 1  0, const ImVec2& uv3 = ImVec2 1  1, const ImVec2& uv4 = ImVec2 0  1, ImU32 col = IM_COL32_WHITE);
IMGUI_FUNCTION_DRAW_LIST(AddImageQuad)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(p1)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
IM_VEC_2_ARG(p4)
OPTIONAL_IM_VEC_2_ARG(uv1, 0, 0)
OPTIONAL_IM_VEC_2_ARG(uv2, 1, 0)
OPTIONAL_IM_VEC_2_ARG(uv3, 1, 1)
OPTIONAL_IM_VEC_2_ARG(uv4, 0, 1)
OPTIONAL_UINT_ARG(col, IM_COL32_WHITE)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddImageQuad, user_texture_id, p1, p2, p3, p4, uv1, uv2, uv3, uv4, col)
END_IMGUI_FUNC

//    IMGUI_API void  AddImageRounded(ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, ImU32 col, float rounding, ImDrawCornerFlags rounding_corners = ImDrawCornerFlags_All);
IMGUI_FUNCTION_DRAW_LIST(AddImageRounded)
TEXTURE_ARG(user_texture_id)
IM_VEC_2_ARG(p_min)
IM_VEC_2_ARG(p_max)
IM_VEC_2_ARG(uv_min)
IM_VEC_2_ARG(uv_max)
UINT_ARG(col)
NUMBER_ARG(rounding)
OPTIONAL_ENUM_ARG(rounding_corners, ImDrawCornerFlags_All)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddImageRounded, user_texture_id, p_min, p_max, uv_min, uv_max, col, rounding, rounding_corners)
END_IMGUI_FUNC

//    inline    void  PathLineTo(const ImVec2& pos)                               { _Path.push_back(pos); }
// Unsupported arg type const ImVec2& pos)                               { _Path.push_back(pos
//    inline    void  PathLineToMergeDuplicate(const ImVec2& pos)                 { if (_Path.Size == 0 || memcmp(&_Path.Data[_Path.Size - 1], &pos, 8) != 0) _Path.push_back(pos); }
// Unsupported arg type const ImVec2& pos)                 { if (_Path.Size == 0 || memcmp(&_Path.Data[_Path.Size - 1]
// Unsupported arg type  8) != 0) _Path.push_back(pos
//    inline    void  PathFillConvex(ImU32 col)                                   { AddConvexPolyFilled(_Path.Data, _Path.Size, col); _Path.Size = 0; }  // Note: Anti-aliased filling requires points to be in clockwise order.
// Unsupported arg type ImU32 col)                                   { AddConvexPolyFilled(_Path.Data
//    inline    void  PathStroke(ImU32 col, bool closed, float thickness = 1.0f)  { AddPolyline(_Path.Data, _Path.Size, col, closed, thickness); _Path.Size = 0; }
// Unsupported arg type  float thickness = 1.0f)  { AddPolyline(_Path.Data
//    IMGUI_API void  PathArcTo(const ImVec2& center, float radius, float a_min, float a_max, int num_segments = 10);
IMGUI_FUNCTION_DRAW_LIST(PathArcTo)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
NUMBER_ARG(a_min)
NUMBER_ARG(a_max)
OPTIONAL_INT_ARG(num_segments, 10)
DRAW_LIST_CALL_FUNCTION_NO_RET(PathArcTo, center, radius, a_min, a_max, num_segments)
END_IMGUI_FUNC

//    IMGUI_API void  PathArcToFast(const ImVec2& center, float radius, int a_min_of_12, int a_max_of_12);                                            // Use precomputed angles for a 12 steps circle
IMGUI_FUNCTION_DRAW_LIST(PathArcToFast)
IM_VEC_2_ARG(center)
NUMBER_ARG(radius)
INT_ARG(a_min_of_12)
INT_ARG(a_max_of_12)
DRAW_LIST_CALL_FUNCTION_NO_RET(PathArcToFast, center, radius, a_min_of_12, a_max_of_12)
END_IMGUI_FUNC

//    IMGUI_API void  PathBezierCurveTo(const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int num_segments = 0);
IMGUI_FUNCTION_DRAW_LIST(PathBezierCurveTo)
IM_VEC_2_ARG(p2)
IM_VEC_2_ARG(p3)
IM_VEC_2_ARG(p4)
OPTIONAL_INT_ARG(num_segments, 0)
DRAW_LIST_CALL_FUNCTION_NO_RET(PathBezierCurveTo, p2, p3, p4, num_segments)
END_IMGUI_FUNC

//    IMGUI_API void  PathRect(const ImVec2& rect_min, const ImVec2& rect_max, float rounding = 0.0f, ImDrawCornerFlags rounding_corners = ImDrawCornerFlags_All);
IMGUI_FUNCTION_DRAW_LIST(PathRect)
IM_VEC_2_ARG(rect_min)
IM_VEC_2_ARG(rect_max)
OPTIONAL_NUMBER_ARG(rounding, 0.0f)
OPTIONAL_ENUM_ARG(rounding_corners, ImDrawCornerFlags_All)
DRAW_LIST_CALL_FUNCTION_NO_RET(PathRect, rect_min, rect_max, rounding, rounding_corners)
END_IMGUI_FUNC

//    IMGUI_API void  AddCallback(ImDrawCallback callback, void* callback_data);  // Your rendering function must check for 'UserCallback' in ImDrawCmd and call the function instead of rendering triangles.
// Unsupported arg type ImDrawCallback callback
// Unsupported arg type  void* callback_data
//    IMGUI_API void  AddDrawCmd();                                               // This is useful if you need to forcefully create a new draw call (to allow for dependent rendering / blending). Otherwise primitives are merged into the same draw-call as much as possible
IMGUI_FUNCTION_DRAW_LIST(AddDrawCmd)
DRAW_LIST_CALL_FUNCTION_NO_RET(AddDrawCmd)
END_IMGUI_FUNC

//    inline void     ChannelsSplit(int count)    { _Splitter.Split(this, count); }
// Unsupported arg type int count)    { _Splitter.Split(this
//    inline void     ChannelsMerge()             { _Splitter.Merge(this); }
// Unsupported arg type )             { _Splitter.Merge(this
//    inline void     ChannelsSetCurrent(int n)   { _Splitter.SetCurrentChannel(this, n); }
// Unsupported arg type int n)   { _Splitter.SetCurrentChannel(this
//    IMGUI_API void  PrimReserve(int idx_count, int vtx_count);
IMGUI_FUNCTION_DRAW_LIST(PrimReserve)
INT_ARG(idx_count)
INT_ARG(vtx_count)
DRAW_LIST_CALL_FUNCTION_NO_RET(PrimReserve, idx_count, vtx_count)
END_IMGUI_FUNC

//    IMGUI_API void  PrimUnreserve(int idx_count, int vtx_count);
IMGUI_FUNCTION_DRAW_LIST(PrimUnreserve)
INT_ARG(idx_count)
INT_ARG(vtx_count)
DRAW_LIST_CALL_FUNCTION_NO_RET(PrimUnreserve, idx_count, vtx_count)
END_IMGUI_FUNC

//    IMGUI_API void  PrimRect(const ImVec2& a, const ImVec2& b, ImU32 col);      // Axis aligned rectangle (composed of two triangles)
IMGUI_FUNCTION_DRAW_LIST(PrimRect)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(PrimRect, a, b, col)
END_IMGUI_FUNC

//    IMGUI_API void  PrimRectUV(const ImVec2& a, const ImVec2& b, const ImVec2& uv_a, const ImVec2& uv_b, ImU32 col);
IMGUI_FUNCTION_DRAW_LIST(PrimRectUV)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(uv_a)
IM_VEC_2_ARG(uv_b)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(PrimRectUV, a, b, uv_a, uv_b, col)
END_IMGUI_FUNC

//    IMGUI_API void  PrimQuadUV(const ImVec2& a, const ImVec2& b, const ImVec2& c, const ImVec2& d, const ImVec2& uv_a, const ImVec2& uv_b, const ImVec2& uv_c, const ImVec2& uv_d, ImU32 col);
IMGUI_FUNCTION_DRAW_LIST(PrimQuadUV)
IM_VEC_2_ARG(a)
IM_VEC_2_ARG(b)
IM_VEC_2_ARG(c)
IM_VEC_2_ARG(d)
IM_VEC_2_ARG(uv_a)
IM_VEC_2_ARG(uv_b)
IM_VEC_2_ARG(uv_c)
IM_VEC_2_ARG(uv_d)
UINT_ARG(col)
DRAW_LIST_CALL_FUNCTION_NO_RET(PrimQuadUV, a, b, c, d, uv_a, uv_b, uv_c, uv_d, col)
END_IMGUI_FUNC

//    inline    void  PrimVtx(const ImVec2& pos, const ImVec2& uv, ImU32 col)         { PrimWriteIdx((ImDrawIdx)_VtxCurrentIdx); PrimWriteVtx(pos, uv, col); } // Write vertex with unique index
// Unsupported arg type  ImU32 col)         { PrimWriteIdx((ImDrawIdx)_VtxCurrentIdx
//    IMGUI_API void  _ResetForNewFrame();
//Not allowed to use this function
//    IMGUI_API void  _ClearFreeMemory();
//Not allowed to use this function
//    IMGUI_API void  _PopUnusedDrawCmd();
//Not allowed to use this function
//    IMGUI_API void  _OnChangedClipRect();
//Not allowed to use this function
//    IMGUI_API void  _OnChangedTextureID();
//Not allowed to use this function
//    IMGUI_API void  _OnChangedVtxOffset();
//Not allowed to use this function
