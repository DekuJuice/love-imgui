//enum ImGuiWindowFlags_

//    ImGuiWindowFlags_None                   = 0,
MAKE_ENUM(ImGuiWindowFlags_None)
//    ImGuiWindowFlags_NoTitleBar             = 1 << 0,   // Disable title-bar
MAKE_ENUM(ImGuiWindowFlags_NoTitleBar)
//    ImGuiWindowFlags_NoResize               = 1 << 1,   // Disable user resizing with the lower-right grip
MAKE_ENUM(ImGuiWindowFlags_NoResize)
//    ImGuiWindowFlags_NoMove                 = 1 << 2,   // Disable user moving the window
MAKE_ENUM(ImGuiWindowFlags_NoMove)
//    ImGuiWindowFlags_NoScrollbar            = 1 << 3,   // Disable scrollbars (window can still scroll with mouse or programmatically)
MAKE_ENUM(ImGuiWindowFlags_NoScrollbar)
//    ImGuiWindowFlags_NoScrollWithMouse      = 1 << 4,   // Disable user vertically scrolling with mouse wheel. On child window, mouse wheel will be forwarded to the parent unless NoScrollbar is also set.
MAKE_ENUM(ImGuiWindowFlags_NoScrollWithMouse)
//    ImGuiWindowFlags_NoCollapse             = 1 << 5,   // Disable user collapsing window by double-clicking on it. Also referred to as "window menu button" within a docking node.
MAKE_ENUM(ImGuiWindowFlags_NoCollapse)
//    ImGuiWindowFlags_AlwaysAutoResize       = 1 << 6,   // Resize every window to its content every frame
MAKE_ENUM(ImGuiWindowFlags_AlwaysAutoResize)
//    ImGuiWindowFlags_NoBackground           = 1 << 7,   // Disable drawing background color (WindowBg, etc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f).
MAKE_ENUM(ImGuiWindowFlags_NoBackground)
//    ImGuiWindowFlags_NoSavedSettings        = 1 << 8,   // Never load/save settings in .ini file
MAKE_ENUM(ImGuiWindowFlags_NoSavedSettings)
//    ImGuiWindowFlags_NoMouseInputs          = 1 << 9,   // Disable catching mouse, hovering test with pass through.
MAKE_ENUM(ImGuiWindowFlags_NoMouseInputs)
//    ImGuiWindowFlags_MenuBar                = 1 << 10,  // Has a menu-bar
MAKE_ENUM(ImGuiWindowFlags_MenuBar)
//    ImGuiWindowFlags_HorizontalScrollbar    = 1 << 11,  // Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section.
MAKE_ENUM(ImGuiWindowFlags_HorizontalScrollbar)
//    ImGuiWindowFlags_NoFocusOnAppearing     = 1 << 12,  // Disable taking focus when transitioning from hidden to visible state
MAKE_ENUM(ImGuiWindowFlags_NoFocusOnAppearing)
//    ImGuiWindowFlags_NoBringToFrontOnFocus  = 1 << 13,  // Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus)
MAKE_ENUM(ImGuiWindowFlags_NoBringToFrontOnFocus)
//    ImGuiWindowFlags_AlwaysVerticalScrollbar= 1 << 14,  // Always show vertical scrollbar (even if ContentSize.y < Size.y)
MAKE_ENUM(ImGuiWindowFlags_AlwaysVerticalScrollbar)
//    ImGuiWindowFlags_AlwaysHorizontalScrollbar=1<< 15,  // Always show horizontal scrollbar (even if ContentSize.x < Size.x)
MAKE_ENUM(ImGuiWindowFlags_AlwaysHorizontalScrollbar)
//    ImGuiWindowFlags_AlwaysUseWindowPadding = 1 << 16,  // Ensure child windows without border uses style.WindowPadding (ignored by default for non-bordered child windows, because more convenient)
MAKE_ENUM(ImGuiWindowFlags_AlwaysUseWindowPadding)
//    ImGuiWindowFlags_NoNavInputs            = 1 << 18,  // No gamepad/keyboard navigation within the window
MAKE_ENUM(ImGuiWindowFlags_NoNavInputs)
//    ImGuiWindowFlags_NoNavFocus             = 1 << 19,  // No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
MAKE_ENUM(ImGuiWindowFlags_NoNavFocus)
//    ImGuiWindowFlags_UnsavedDocument        = 1 << 20,  // Append '*' to title without affecting the ID, as a convenience to avoid using the ### operator. When used in a tab/docking context, tab is selected on closure and closure is deferred by one frame to allow code to cancel the closure (with a confirmation popup, etc.) without flicker.
MAKE_ENUM(ImGuiWindowFlags_UnsavedDocument)
//    ImGuiWindowFlags_NoDocking              = 1 << 21,  // Disable docking of this window
MAKE_ENUM(ImGuiWindowFlags_NoDocking)
//    ImGuiWindowFlags_NoNav                  = ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,
MAKE_ENUM(ImGuiWindowFlags_NoNav)
//    ImGuiWindowFlags_NoDecoration           = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse,
MAKE_ENUM(ImGuiWindowFlags_NoDecoration)
//    ImGuiWindowFlags_NoInputs               = ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,
MAKE_ENUM(ImGuiWindowFlags_NoInputs)
//    ImGuiWindowFlags_NavFlattened           = 1 << 23,  // [BETA] Allow gamepad/keyboard navigation to cross over parent border to this child (only use on child that have no scrolling!)
MAKE_ENUM(ImGuiWindowFlags_NavFlattened)
//    ImGuiWindowFlags_ChildWindow            = 1 << 24,  // Don't use! For internal use by BeginChild()
MAKE_ENUM(ImGuiWindowFlags_ChildWindow)
//    ImGuiWindowFlags_Tooltip                = 1 << 25,  // Don't use! For internal use by BeginTooltip()
MAKE_ENUM(ImGuiWindowFlags_Tooltip)
//    ImGuiWindowFlags_Popup                  = 1 << 26,  // Don't use! For internal use by BeginPopup()
MAKE_ENUM(ImGuiWindowFlags_Popup)
//    ImGuiWindowFlags_Modal                  = 1 << 27,  // Don't use! For internal use by BeginPopupModal()
MAKE_ENUM(ImGuiWindowFlags_Modal)
//    ImGuiWindowFlags_ChildMenu              = 1 << 28,  // Don't use! For internal use by BeginMenu()
MAKE_ENUM(ImGuiWindowFlags_ChildMenu)
//    ImGuiWindowFlags_DockNodeHost           = 1 << 29   // Don't use! For internal use by Begin()/NewFrame()
MAKE_ENUM(ImGuiWindowFlags_DockNodeHost)

//enum ImGuiInputTextFlags_

//    ImGuiInputTextFlags_None                = 0,
MAKE_ENUM(ImGuiInputTextFlags_None)
//    ImGuiInputTextFlags_CharsDecimal        = 1 << 0,   // Allow 0123456789.+-*/
MAKE_ENUM(ImGuiInputTextFlags_CharsDecimal)
//    ImGuiInputTextFlags_CharsHexadecimal    = 1 << 1,   // Allow 0123456789ABCDEFabcdef
MAKE_ENUM(ImGuiInputTextFlags_CharsHexadecimal)
//    ImGuiInputTextFlags_CharsUppercase      = 1 << 2,   // Turn a..z into A..Z
MAKE_ENUM(ImGuiInputTextFlags_CharsUppercase)
//    ImGuiInputTextFlags_CharsNoBlank        = 1 << 3,   // Filter out spaces, tabs
MAKE_ENUM(ImGuiInputTextFlags_CharsNoBlank)
//    ImGuiInputTextFlags_AutoSelectAll       = 1 << 4,   // Select entire text when first taking mouse focus
MAKE_ENUM(ImGuiInputTextFlags_AutoSelectAll)
//    ImGuiInputTextFlags_EnterReturnsTrue    = 1 << 5,   // Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
MAKE_ENUM(ImGuiInputTextFlags_EnterReturnsTrue)
//    ImGuiInputTextFlags_CallbackCompletion  = 1 << 6,   // Callback on pressing TAB (for completion handling)
MAKE_ENUM(ImGuiInputTextFlags_CallbackCompletion)
//    ImGuiInputTextFlags_CallbackHistory     = 1 << 7,   // Callback on pressing Up/Down arrows (for history handling)
MAKE_ENUM(ImGuiInputTextFlags_CallbackHistory)
//    ImGuiInputTextFlags_CallbackAlways      = 1 << 8,   // Callback on each iteration. User code may query cursor position, modify text buffer.
MAKE_ENUM(ImGuiInputTextFlags_CallbackAlways)
//    ImGuiInputTextFlags_CallbackCharFilter  = 1 << 9,   // Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
MAKE_ENUM(ImGuiInputTextFlags_CallbackCharFilter)
//    ImGuiInputTextFlags_AllowTabInput       = 1 << 10,  // Pressing TAB input a '\t' character into the text field
MAKE_ENUM(ImGuiInputTextFlags_AllowTabInput)
//    ImGuiInputTextFlags_CtrlEnterForNewLine = 1 << 11,  // In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter).
MAKE_ENUM(ImGuiInputTextFlags_CtrlEnterForNewLine)
//    ImGuiInputTextFlags_NoHorizontalScroll  = 1 << 12,  // Disable following the cursor horizontally
MAKE_ENUM(ImGuiInputTextFlags_NoHorizontalScroll)
//    ImGuiInputTextFlags_AlwaysInsertMode    = 1 << 13,  // Insert mode
MAKE_ENUM(ImGuiInputTextFlags_AlwaysInsertMode)
//    ImGuiInputTextFlags_ReadOnly            = 1 << 14,  // Read-only mode
MAKE_ENUM(ImGuiInputTextFlags_ReadOnly)
//    ImGuiInputTextFlags_Password            = 1 << 15,  // Password mode, display all characters as '*'
MAKE_ENUM(ImGuiInputTextFlags_Password)
//    ImGuiInputTextFlags_NoUndoRedo          = 1 << 16,  // Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
MAKE_ENUM(ImGuiInputTextFlags_NoUndoRedo)
//    ImGuiInputTextFlags_CharsScientific     = 1 << 17,  // Allow 0123456789.+-*/eE (Scientific notation input)
MAKE_ENUM(ImGuiInputTextFlags_CharsScientific)
//    ImGuiInputTextFlags_CallbackResize      = 1 << 18,  // Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
MAKE_ENUM(ImGuiInputTextFlags_CallbackResize)
//    ImGuiInputTextFlags_Multiline           = 1 << 20,  // For internal use by InputTextMultiline()
MAKE_ENUM(ImGuiInputTextFlags_Multiline)
//    ImGuiInputTextFlags_NoMarkEdited        = 1 << 21   // For internal use by functions using InputText() before reformatting data
MAKE_ENUM(ImGuiInputTextFlags_NoMarkEdited)

//enum ImGuiTreeNodeFlags_

//    ImGuiTreeNodeFlags_None                 = 0,
MAKE_ENUM(ImGuiTreeNodeFlags_None)
//    ImGuiTreeNodeFlags_Selected             = 1 << 0,   // Draw as selected
MAKE_ENUM(ImGuiTreeNodeFlags_Selected)
//    ImGuiTreeNodeFlags_Framed               = 1 << 1,   // Full colored frame (e.g. for CollapsingHeader)
MAKE_ENUM(ImGuiTreeNodeFlags_Framed)
//    ImGuiTreeNodeFlags_AllowItemOverlap     = 1 << 2,   // Hit testing to allow subsequent widgets to overlap this one
MAKE_ENUM(ImGuiTreeNodeFlags_AllowItemOverlap)
//    ImGuiTreeNodeFlags_NoTreePushOnOpen     = 1 << 3,   // Don't do a TreePush() when open (e.g. for CollapsingHeader) = no extra indent nor pushing on ID stack
MAKE_ENUM(ImGuiTreeNodeFlags_NoTreePushOnOpen)
//    ImGuiTreeNodeFlags_NoAutoOpenOnLog      = 1 << 4,   // Don't automatically and temporarily open node when Logging is active (by default logging will automatically open tree nodes)
MAKE_ENUM(ImGuiTreeNodeFlags_NoAutoOpenOnLog)
//    ImGuiTreeNodeFlags_DefaultOpen          = 1 << 5,   // Default node to be open
MAKE_ENUM(ImGuiTreeNodeFlags_DefaultOpen)
//    ImGuiTreeNodeFlags_OpenOnDoubleClick    = 1 << 6,   // Need double-click to open node
MAKE_ENUM(ImGuiTreeNodeFlags_OpenOnDoubleClick)
//    ImGuiTreeNodeFlags_OpenOnArrow          = 1 << 7,   // Only open when clicking on the arrow part. If ImGuiTreeNodeFlags_OpenOnDoubleClick is also set, single-click arrow or double-click all box to open.
MAKE_ENUM(ImGuiTreeNodeFlags_OpenOnArrow)
//    ImGuiTreeNodeFlags_Leaf                 = 1 << 8,   // No collapsing, no arrow (use as a convenience for leaf nodes).
MAKE_ENUM(ImGuiTreeNodeFlags_Leaf)
//    ImGuiTreeNodeFlags_Bullet               = 1 << 9,   // Display a bullet instead of arrow
MAKE_ENUM(ImGuiTreeNodeFlags_Bullet)
//    ImGuiTreeNodeFlags_FramePadding         = 1 << 10,  // Use FramePadding (even for an unframed text node) to vertically align text baseline to regular widget height. Equivalent to calling AlignTextToFramePadding().
MAKE_ENUM(ImGuiTreeNodeFlags_FramePadding)
//    ImGuiTreeNodeFlags_SpanAvailWidth       = 1 << 11,  // Extend hit box to the right-most edge, even if not framed. This is not the default in order to allow adding other items on the same line. In the future we may refactor the hit system to be front-to-back, allowing natural overlaps and then this can become the default.
MAKE_ENUM(ImGuiTreeNodeFlags_SpanAvailWidth)
//    ImGuiTreeNodeFlags_SpanFullWidth        = 1 << 12,  // Extend hit box to the left-most and right-most edges (bypass the indented area).
MAKE_ENUM(ImGuiTreeNodeFlags_SpanFullWidth)
//    ImGuiTreeNodeFlags_NavLeftJumpsBackHere = 1 << 13,  // (WIP) Nav: left direction may move to this TreeNode() from any of its child (items submitted between TreeNode and TreePop)
MAKE_ENUM(ImGuiTreeNodeFlags_NavLeftJumpsBackHere)
//    ImGuiTreeNodeFlags_CollapsingHeader     = ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_NoAutoOpenOnLog
MAKE_ENUM(ImGuiTreeNodeFlags_CollapsingHeader)

//enum ImGuiPopupFlags_

//    ImGuiPopupFlags_None                    = 0,
MAKE_ENUM(ImGuiPopupFlags_None)
//    ImGuiPopupFlags_MouseButtonLeft         = 0,        // For BeginPopupContext*(): open on Left Mouse release. Guaranted to always be == 0 (same as ImGuiMouseButton_Left)
MAKE_ENUM(ImGuiPopupFlags_MouseButtonLeft)
//    ImGuiPopupFlags_MouseButtonRight        = 1,        // For BeginPopupContext*(): open on Right Mouse release. Guaranted to always be == 1 (same as ImGuiMouseButton_Right)
MAKE_ENUM(ImGuiPopupFlags_MouseButtonRight)
//    ImGuiPopupFlags_MouseButtonMiddle       = 2,        // For BeginPopupContext*(): open on Middle Mouse release. Guaranted to always be == 2 (same as ImGuiMouseButton_Middle)
MAKE_ENUM(ImGuiPopupFlags_MouseButtonMiddle)
//    ImGuiPopupFlags_NoOpenOverExistingPopup = 1 << 5,   // For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack
MAKE_ENUM(ImGuiPopupFlags_NoOpenOverExistingPopup)
//    ImGuiPopupFlags_NoOpenOverItems         = 1 << 6,   // For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space
MAKE_ENUM(ImGuiPopupFlags_NoOpenOverItems)
//    ImGuiPopupFlags_AnyPopupId              = 1 << 7,   // For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup.
MAKE_ENUM(ImGuiPopupFlags_AnyPopupId)
//    ImGuiPopupFlags_AnyPopupLevel           = 1 << 8,   // For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level)
MAKE_ENUM(ImGuiPopupFlags_AnyPopupLevel)
//    ImGuiPopupFlags_AnyPopup                = ImGuiPopupFlags_AnyPopupId | ImGuiPopupFlags_AnyPopupLevel
MAKE_ENUM(ImGuiPopupFlags_AnyPopup)

//enum ImGuiSelectableFlags_

//    ImGuiSelectableFlags_None               = 0,
MAKE_ENUM(ImGuiSelectableFlags_None)
//    ImGuiSelectableFlags_DontClosePopups    = 1 << 0,   // Clicking this don't close parent popup window
MAKE_ENUM(ImGuiSelectableFlags_DontClosePopups)
//    ImGuiSelectableFlags_SpanAllColumns     = 1 << 1,   // Selectable frame can span all columns (text will still fit in current column)
MAKE_ENUM(ImGuiSelectableFlags_SpanAllColumns)
//    ImGuiSelectableFlags_AllowDoubleClick   = 1 << 2,   // Generate press events on double clicks too
MAKE_ENUM(ImGuiSelectableFlags_AllowDoubleClick)
//    ImGuiSelectableFlags_Disabled           = 1 << 3,   // Cannot be selected, display grayed out text
MAKE_ENUM(ImGuiSelectableFlags_Disabled)
//    ImGuiSelectableFlags_AllowItemOverlap   = 1 << 4    // (WIP) Hit testing to allow subsequent widgets to overlap this one
MAKE_ENUM(ImGuiSelectableFlags_AllowItemOverlap)

//enum ImGuiComboFlags_

//    ImGuiComboFlags_None                    = 0,
MAKE_ENUM(ImGuiComboFlags_None)
//    ImGuiComboFlags_PopupAlignLeft          = 1 << 0,   // Align the popup toward the left by default
MAKE_ENUM(ImGuiComboFlags_PopupAlignLeft)
//    ImGuiComboFlags_HeightSmall             = 1 << 1,   // Max ~4 items visible. Tip: If you want your combo popup to be a specific size you can use SetNextWindowSizeConstraints() prior to calling BeginCombo()
MAKE_ENUM(ImGuiComboFlags_HeightSmall)
//    ImGuiComboFlags_HeightRegular           = 1 << 2,   // Max ~8 items visible (default)
MAKE_ENUM(ImGuiComboFlags_HeightRegular)
//    ImGuiComboFlags_HeightLarge             = 1 << 3,   // Max ~20 items visible
MAKE_ENUM(ImGuiComboFlags_HeightLarge)
//    ImGuiComboFlags_HeightLargest           = 1 << 4,   // As many fitting items as possible
MAKE_ENUM(ImGuiComboFlags_HeightLargest)
//    ImGuiComboFlags_NoArrowButton           = 1 << 5,   // Display on the preview box without the square arrow button
MAKE_ENUM(ImGuiComboFlags_NoArrowButton)
//    ImGuiComboFlags_NoPreview               = 1 << 6,   // Display only a square arrow button
MAKE_ENUM(ImGuiComboFlags_NoPreview)

//enum ImGuiTabBarFlags_

//    ImGuiTabBarFlags_None                           = 0,
MAKE_ENUM(ImGuiTabBarFlags_None)
//    ImGuiTabBarFlags_Reorderable                    = 1 << 0,   // Allow manually dragging tabs to re-order them + New tabs are appended at the end of list
MAKE_ENUM(ImGuiTabBarFlags_Reorderable)
//    ImGuiTabBarFlags_AutoSelectNewTabs              = 1 << 1,   // Automatically select new tabs when they appear
MAKE_ENUM(ImGuiTabBarFlags_AutoSelectNewTabs)
//    ImGuiTabBarFlags_TabListPopupButton             = 1 << 2,   // Disable buttons to open the tab list popup
MAKE_ENUM(ImGuiTabBarFlags_TabListPopupButton)
//    ImGuiTabBarFlags_NoCloseWithMiddleMouseButton   = 1 << 3,   // Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
MAKE_ENUM(ImGuiTabBarFlags_NoCloseWithMiddleMouseButton)
//    ImGuiTabBarFlags_NoTabListScrollingButtons      = 1 << 4,   // Disable scrolling buttons (apply when fitting policy is ImGuiTabBarFlags_FittingPolicyScroll)
MAKE_ENUM(ImGuiTabBarFlags_NoTabListScrollingButtons)
//    ImGuiTabBarFlags_NoTooltip                      = 1 << 5,   // Disable tooltips when hovering a tab
MAKE_ENUM(ImGuiTabBarFlags_NoTooltip)
//    ImGuiTabBarFlags_FittingPolicyResizeDown        = 1 << 6,   // Resize tabs when they don't fit
MAKE_ENUM(ImGuiTabBarFlags_FittingPolicyResizeDown)
//    ImGuiTabBarFlags_FittingPolicyScroll            = 1 << 7,   // Add scroll buttons when tabs don't fit
MAKE_ENUM(ImGuiTabBarFlags_FittingPolicyScroll)

//enum ImGuiTabItemFlags_

//    ImGuiTabItemFlags_None                          = 0,
MAKE_ENUM(ImGuiTabItemFlags_None)
//    ImGuiTabItemFlags_UnsavedDocument               = 1 << 0,   // Append '*' to title without affecting the ID, as a convenience to avoid using the ### operator. Also: tab is selected on closure and closure is deferred by one frame to allow code to undo it without flicker.
MAKE_ENUM(ImGuiTabItemFlags_UnsavedDocument)
//    ImGuiTabItemFlags_SetSelected                   = 1 << 1,   // Trigger flag to programmatically make the tab selected when calling BeginTabItem()
MAKE_ENUM(ImGuiTabItemFlags_SetSelected)
//    ImGuiTabItemFlags_NoCloseWithMiddleMouseButton  = 1 << 2,   // Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
MAKE_ENUM(ImGuiTabItemFlags_NoCloseWithMiddleMouseButton)
//    ImGuiTabItemFlags_NoPushId                      = 1 << 3,   // Don't call PushID(tab->ID)/PopID() on BeginTabItem()/EndTabItem()
MAKE_ENUM(ImGuiTabItemFlags_NoPushId)
//    ImGuiTabItemFlags_NoTooltip                     = 1 << 4    // Disable tooltip for the given tab
MAKE_ENUM(ImGuiTabItemFlags_NoTooltip)

//enum ImGuiTableFlags_

//    ImGuiTableFlags_None                            = 0,
MAKE_ENUM(ImGuiTableFlags_None)
//    ImGuiTableFlags_Resizable                       = 1 << 0,   // Allow resizing columns.
MAKE_ENUM(ImGuiTableFlags_Resizable)
//    ImGuiTableFlags_Reorderable                     = 1 << 1,   // Allow reordering columns (need calling TableSetupColumn() + TableAutoHeaders() or TableHeaders() to display headers)
MAKE_ENUM(ImGuiTableFlags_Reorderable)
//    ImGuiTableFlags_Hideable                        = 1 << 2,   // Allow hiding columns (with right-click on header) (FIXME-TABLE: allow without headers).
MAKE_ENUM(ImGuiTableFlags_Hideable)
//    ImGuiTableFlags_Sortable                        = 1 << 3,   // Allow sorting on one column (sort_specs_count will always be == 1). Call TableGetSortSpecs() to obtain sort specs.
MAKE_ENUM(ImGuiTableFlags_Sortable)
//    ImGuiTableFlags_MultiSortable                   = 1 << 4,   // Allow sorting on multiple columns by holding Shift (sort_specs_count may be > 1). Call TableGetSortSpecs() to obtain sort specs.
MAKE_ENUM(ImGuiTableFlags_MultiSortable)
//    ImGuiTableFlags_NoSavedSettings                 = 1 << 5,   // Disable persisting columns order, width and sort settings in the .ini file.
MAKE_ENUM(ImGuiTableFlags_NoSavedSettings)
//    ImGuiTableFlags_RowBg                           = 1 << 6,   // Use ImGuiCol_TableRowBg and ImGuiCol_TableRowBgAlt colors behind each rows.
MAKE_ENUM(ImGuiTableFlags_RowBg)
//    ImGuiTableFlags_BordersHInner                   = 1 << 7,   // Draw horizontal borders between rows.
MAKE_ENUM(ImGuiTableFlags_BordersHInner)
//    ImGuiTableFlags_BordersHOuter                   = 1 << 8,   // Draw horizontal borders at the top and bottom.
MAKE_ENUM(ImGuiTableFlags_BordersHOuter)
//    ImGuiTableFlags_BordersVInner                   = 1 << 9,   // Draw vertical borders between columns.
MAKE_ENUM(ImGuiTableFlags_BordersVInner)
//    ImGuiTableFlags_BordersVOuter                   = 1 << 10,  // Draw vertical borders on the left and right sides.
MAKE_ENUM(ImGuiTableFlags_BordersVOuter)
//    ImGuiTableFlags_BordersH                        = ImGuiTableFlags_BordersHInner | ImGuiTableFlags_BordersHOuter, // Draw horizontal borders.
MAKE_ENUM(ImGuiTableFlags_BordersH)
//    ImGuiTableFlags_BordersV                        = ImGuiTableFlags_BordersVInner | ImGuiTableFlags_BordersVOuter, // Draw vertical borders.
MAKE_ENUM(ImGuiTableFlags_BordersV)
//    ImGuiTableFlags_BordersInner                    = ImGuiTableFlags_BordersVInner | ImGuiTableFlags_BordersHInner, // Draw inner borders.
MAKE_ENUM(ImGuiTableFlags_BordersInner)
//    ImGuiTableFlags_BordersOuter                    = ImGuiTableFlags_BordersVOuter | ImGuiTableFlags_BordersHOuter, // Draw outer borders.
MAKE_ENUM(ImGuiTableFlags_BordersOuter)
//    ImGuiTableFlags_Borders                         = ImGuiTableFlags_BordersInner | ImGuiTableFlags_BordersOuter,   // Draw all borders.
MAKE_ENUM(ImGuiTableFlags_Borders)
//    ImGuiTableFlags_BordersVFullHeight              = 1 << 11,  // Borders covers all rows even when Headers are being used. Allow resizing from any rows.
MAKE_ENUM(ImGuiTableFlags_BordersVFullHeight)
//    ImGuiTableFlags_NoClipX                         = 1 << 12,  // Disable pushing clipping rectangle for every individual columns (reduce draw command count, items will be able to overflow)
MAKE_ENUM(ImGuiTableFlags_NoClipX)
//    ImGuiTableFlags_SizingPolicyFixedX              = 1 << 13,  // Default if ScrollX is on. Columns will default to use _WidthFixed or _WidthAlwaysAutoResize policy. Read description above for more details.
MAKE_ENUM(ImGuiTableFlags_SizingPolicyFixedX)
//    ImGuiTableFlags_SizingPolicyStretchX            = 1 << 14,  // Default if ScrollX is off. Columns will default to use _WidthStretch policy. Read description above for more details.
MAKE_ENUM(ImGuiTableFlags_SizingPolicyStretchX)
//    ImGuiTableFlags_NoHeadersWidth                  = 1 << 15,  // Disable header width contribution to automatic width calculation.
MAKE_ENUM(ImGuiTableFlags_NoHeadersWidth)
//    ImGuiTableFlags_NoHostExtendY                   = 1 << 16,  // (FIXME-TABLE: Reword as SizingPolicy?) Disable extending past the limit set by outer_size.y, only meaningful when neither of ScrollX|ScrollY are set (data below the limit will be clipped and not visible)
MAKE_ENUM(ImGuiTableFlags_NoHostExtendY)
//    ImGuiTableFlags_NoKeepColumnsVisible            = 1 << 17,  // (FIXME-TABLE) Disable code that keeps column always minimally visible when table width gets too small and horizontal scrolling is off.
MAKE_ENUM(ImGuiTableFlags_NoKeepColumnsVisible)
//    ImGuiTableFlags_ScrollX                         = 1 << 18,  // Enable horizontal scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size. Because this create a child window, ScrollY is currently generally recommended when using ScrollX.
MAKE_ENUM(ImGuiTableFlags_ScrollX)
//    ImGuiTableFlags_ScrollY                         = 1 << 19,  // Enable vertical scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size.
MAKE_ENUM(ImGuiTableFlags_ScrollY)
//    ImGuiTableFlags_Scroll                          = ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY,
MAKE_ENUM(ImGuiTableFlags_Scroll)
//    ImGuiTableFlags_ScrollFreezeTopRow              = 1 << 20,  // We can lock 1 to 3 rows (starting from the top). Use with ScrollY enabled.
MAKE_ENUM(ImGuiTableFlags_ScrollFreezeTopRow)
//    ImGuiTableFlags_ScrollFreeze2Rows               = 2 << 20,
MAKE_ENUM(ImGuiTableFlags_ScrollFreeze2Rows)
//    ImGuiTableFlags_ScrollFreeze3Rows               = 3 << 20,
MAKE_ENUM(ImGuiTableFlags_ScrollFreeze3Rows)
//    ImGuiTableFlags_ScrollFreezeLeftColumn          = 1 << 22,  // We can lock 1 to 3 columns (starting from the left). Use with ScrollX enabled.
MAKE_ENUM(ImGuiTableFlags_ScrollFreezeLeftColumn)
//    ImGuiTableFlags_ScrollFreeze2Columns            = 2 << 22,
MAKE_ENUM(ImGuiTableFlags_ScrollFreeze2Columns)
//    ImGuiTableFlags_ScrollFreeze3Columns            = 3 << 22,
MAKE_ENUM(ImGuiTableFlags_ScrollFreeze3Columns)

//enum ImGuiTableColumnFlags_

//    ImGuiTableColumnFlags_None                      = 0,
MAKE_ENUM(ImGuiTableColumnFlags_None)
//    ImGuiTableColumnFlags_DefaultHide               = 1 << 0,   // Default as a hidden column.
MAKE_ENUM(ImGuiTableColumnFlags_DefaultHide)
//    ImGuiTableColumnFlags_DefaultSort               = 1 << 1,   // Default as a sorting column.
MAKE_ENUM(ImGuiTableColumnFlags_DefaultSort)
//    ImGuiTableColumnFlags_WidthFixed                = 1 << 2,   // Column will keep a fixed size, preferable with horizontal scrolling enabled (default if table sizing policy is SizingPolicyFixedX and table is resizable).
MAKE_ENUM(ImGuiTableColumnFlags_WidthFixed)
//    ImGuiTableColumnFlags_WidthStretch              = 1 << 3,   // Column will stretch, preferable with horizontal scrolling disabled (default if table sizing policy is SizingPolicyStretchX).
MAKE_ENUM(ImGuiTableColumnFlags_WidthStretch)
//    ImGuiTableColumnFlags_WidthAlwaysAutoResize     = 1 << 4,   // Column will keep resizing based on submitted contents (with a one frame delay) == Fixed with auto resize (default if table sizing policy is SizingPolicyFixedX and table is not resizable).
MAKE_ENUM(ImGuiTableColumnFlags_WidthAlwaysAutoResize)
//    ImGuiTableColumnFlags_NoResize                  = 1 << 5,   // Disable manual resizing.
MAKE_ENUM(ImGuiTableColumnFlags_NoResize)
//    ImGuiTableColumnFlags_NoClipX                   = 1 << 6,   // Disable clipping for this column (all NoClipX columns will render in a same draw command).
MAKE_ENUM(ImGuiTableColumnFlags_NoClipX)
//    ImGuiTableColumnFlags_NoSort                    = 1 << 7,   // Disable ability to sort on this field (even if ImGuiTableFlags_Sortable is set on the table).
MAKE_ENUM(ImGuiTableColumnFlags_NoSort)
//    ImGuiTableColumnFlags_NoSortAscending           = 1 << 8,   // Disable ability to sort in the ascending direction.
MAKE_ENUM(ImGuiTableColumnFlags_NoSortAscending)
//    ImGuiTableColumnFlags_NoSortDescending          = 1 << 9,   // Disable ability to sort in the descending direction.
MAKE_ENUM(ImGuiTableColumnFlags_NoSortDescending)
//    ImGuiTableColumnFlags_NoHide                    = 1 << 10,  // Disable hiding this column.
MAKE_ENUM(ImGuiTableColumnFlags_NoHide)
//    ImGuiTableColumnFlags_NoHeaderWidth             = 1 << 11,  // Header width don't contribute to automatic column width.
MAKE_ENUM(ImGuiTableColumnFlags_NoHeaderWidth)
//    ImGuiTableColumnFlags_PreferSortAscending       = 1 << 12,  // Make the initial sort direction Ascending when first sorting on this column (default).
MAKE_ENUM(ImGuiTableColumnFlags_PreferSortAscending)
//    ImGuiTableColumnFlags_PreferSortDescending      = 1 << 13,  // Make the initial sort direction Descending when first sorting on this column.
MAKE_ENUM(ImGuiTableColumnFlags_PreferSortDescending)
//    ImGuiTableColumnFlags_IndentEnable              = 1 << 14,  // Use current Indent value when entering cell (default for 1st column).
MAKE_ENUM(ImGuiTableColumnFlags_IndentEnable)
//    ImGuiTableColumnFlags_IndentDisable             = 1 << 15,  // Ignore current Indent value when entering cell (default for columns after the 1st one). Indentation changes _within_ the cell will still be honored.
MAKE_ENUM(ImGuiTableColumnFlags_IndentDisable)
//    ImGuiTableColumnFlags_NoReorder                 = 1 << 16,  // Disable reordering this column, this will also prevent other columns from crossing over this column.
MAKE_ENUM(ImGuiTableColumnFlags_NoReorder)

//enum ImGuiTableRowFlags_

//    ImGuiTableRowFlags_None                         = 0,
MAKE_ENUM(ImGuiTableRowFlags_None)
//    ImGuiTableRowFlags_Headers                      = 1 << 0    // Identify header row (set default background color + width of its contents accounted different for auto column width)
MAKE_ENUM(ImGuiTableRowFlags_Headers)

//enum ImGuiFocusedFlags_

//    ImGuiFocusedFlags_None                          = 0,
MAKE_ENUM(ImGuiFocusedFlags_None)
//    ImGuiFocusedFlags_ChildWindows                  = 1 << 0,   // IsWindowFocused(): Return true if any children of the window is focused
MAKE_ENUM(ImGuiFocusedFlags_ChildWindows)
//    ImGuiFocusedFlags_RootWindow                    = 1 << 1,   // IsWindowFocused(): Test from root window (top most parent of the current hierarchy)
MAKE_ENUM(ImGuiFocusedFlags_RootWindow)
//    ImGuiFocusedFlags_AnyWindow                     = 1 << 2,   // IsWindowFocused(): Return true if any window is focused. Important: If you are trying to tell how to dispatch your low-level inputs, do NOT use this. Use 'io.WantCaptureMouse' instead! Please read the FAQ!
MAKE_ENUM(ImGuiFocusedFlags_AnyWindow)
//    ImGuiFocusedFlags_RootAndChildWindows           = ImGuiFocusedFlags_RootWindow | ImGuiFocusedFlags_ChildWindows
MAKE_ENUM(ImGuiFocusedFlags_RootAndChildWindows)

//enum ImGuiHoveredFlags_

//    ImGuiHoveredFlags_None                          = 0,        // Return true if directly over the item/window, not obstructed by another window, not obstructed by an active popup or modal blocking inputs under them.
MAKE_ENUM(ImGuiHoveredFlags_None)
//    ImGuiHoveredFlags_ChildWindows                  = 1 << 0,   // IsWindowHovered() only: Return true if any children of the window is hovered
MAKE_ENUM(ImGuiHoveredFlags_ChildWindows)
//    ImGuiHoveredFlags_RootWindow                    = 1 << 1,   // IsWindowHovered() only: Test from root window (top most parent of the current hierarchy)
MAKE_ENUM(ImGuiHoveredFlags_RootWindow)
//    ImGuiHoveredFlags_AnyWindow                     = 1 << 2,   // IsWindowHovered() only: Return true if any window is hovered
MAKE_ENUM(ImGuiHoveredFlags_AnyWindow)
//    ImGuiHoveredFlags_AllowWhenBlockedByPopup       = 1 << 3,   // Return true even if a popup window is normally blocking access to this item/window
MAKE_ENUM(ImGuiHoveredFlags_AllowWhenBlockedByPopup)
//    ImGuiHoveredFlags_AllowWhenBlockedByActiveItem  = 1 << 5,   // Return true even if an active item is blocking access to this item/window. Useful for Drag and Drop patterns.
MAKE_ENUM(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem)
//    ImGuiHoveredFlags_AllowWhenOverlapped           = 1 << 6,   // Return true even if the position is obstructed or overlapped by another window
MAKE_ENUM(ImGuiHoveredFlags_AllowWhenOverlapped)
//    ImGuiHoveredFlags_AllowWhenDisabled             = 1 << 7,   // Return true even if the item is disabled
MAKE_ENUM(ImGuiHoveredFlags_AllowWhenDisabled)
//    ImGuiHoveredFlags_RectOnly                      = ImGuiHoveredFlags_AllowWhenBlockedByPopup | ImGuiHoveredFlags_AllowWhenBlockedByActiveItem | ImGuiHoveredFlags_AllowWhenOverlapped,
MAKE_ENUM(ImGuiHoveredFlags_RectOnly)
//    ImGuiHoveredFlags_RootAndChildWindows           = ImGuiHoveredFlags_RootWindow | ImGuiHoveredFlags_ChildWindows
MAKE_ENUM(ImGuiHoveredFlags_RootAndChildWindows)

//enum ImGuiDockNodeFlags_

//    ImGuiDockNodeFlags_None                         = 0,
MAKE_ENUM(ImGuiDockNodeFlags_None)
//    ImGuiDockNodeFlags_KeepAliveOnly                = 1 << 0,   // Shared       // Don't display the dockspace node but keep it alive. Windows docked into this dockspace node won't be undocked.
MAKE_ENUM(ImGuiDockNodeFlags_KeepAliveOnly)
//    ImGuiDockNodeFlags_NoDockingInCentralNode       = 1 << 2,   // Shared       // Disable docking inside the Central Node, which will be always kept empty.
MAKE_ENUM(ImGuiDockNodeFlags_NoDockingInCentralNode)
//    ImGuiDockNodeFlags_PassthruCentralNode          = 1 << 3,   // Shared       // Enable passthru dockspace: 1) DockSpace() will render a ImGuiCol_WindowBg background covering everything excepted the Central Node when empty. Meaning the host window should probably use SetNextWindowBgAlpha(0.0f) prior to Begin() when using this. 2) When Central Node is empty: let inputs pass-through + won't display a DockingEmptyBg background. See demo for details.
MAKE_ENUM(ImGuiDockNodeFlags_PassthruCentralNode)
//    ImGuiDockNodeFlags_NoSplit                      = 1 << 4,   // Shared/Local // Disable splitting the node into smaller nodes. Useful e.g. when embedding dockspaces into a main root one (the root one may have splitting disabled to reduce confusion). Note: when turned off, existing splits will be preserved.
MAKE_ENUM(ImGuiDockNodeFlags_NoSplit)
//    ImGuiDockNodeFlags_NoResize                     = 1 << 5,   // Shared/Local // Disable resizing node using the splitter/separators. Useful with programatically setup dockspaces.
MAKE_ENUM(ImGuiDockNodeFlags_NoResize)
//    ImGuiDockNodeFlags_AutoHideTabBar               = 1 << 6    // Shared/Local // Tab bar will automatically hide when there is a single window in the dock node.
MAKE_ENUM(ImGuiDockNodeFlags_AutoHideTabBar)

//enum ImGuiDragDropFlags_

//    ImGuiDragDropFlags_None                         = 0,
MAKE_ENUM(ImGuiDragDropFlags_None)
//    ImGuiDragDropFlags_SourceNoPreviewTooltip       = 1 << 0,   // By default, a successful call to BeginDragDropSource opens a tooltip so you can display a preview or description of the source contents. This flag disable this behavior.
MAKE_ENUM(ImGuiDragDropFlags_SourceNoPreviewTooltip)
//    ImGuiDragDropFlags_SourceNoDisableHover         = 1 << 1,   // By default, when dragging we clear data so that IsItemHovered() will return false, to avoid subsequent user code submitting tooltips. This flag disable this behavior so you can still call IsItemHovered() on the source item.
MAKE_ENUM(ImGuiDragDropFlags_SourceNoDisableHover)
//    ImGuiDragDropFlags_SourceNoHoldToOpenOthers     = 1 << 2,   // Disable the behavior that allows to open tree nodes and collapsing header by holding over them while dragging a source item.
MAKE_ENUM(ImGuiDragDropFlags_SourceNoHoldToOpenOthers)
//    ImGuiDragDropFlags_SourceAllowNullID            = 1 << 3,   // Allow items such as Text(), Image() that have no unique identifier to be used as drag source, by manufacturing a temporary identifier based on their window-relative position. This is extremely unusual within the dear imgui ecosystem and so we made it explicit.
MAKE_ENUM(ImGuiDragDropFlags_SourceAllowNullID)
//    ImGuiDragDropFlags_SourceExtern                 = 1 << 4,   // External source (from outside of dear imgui), won't attempt to read current item/window info. Will always return true. Only one Extern source can be active simultaneously.
MAKE_ENUM(ImGuiDragDropFlags_SourceExtern)
//    ImGuiDragDropFlags_SourceAutoExpirePayload      = 1 << 5,   // Automatically expire the payload if the source cease to be submitted (otherwise payloads are persisting while being dragged)
MAKE_ENUM(ImGuiDragDropFlags_SourceAutoExpirePayload)
//    ImGuiDragDropFlags_AcceptBeforeDelivery         = 1 << 10,  // AcceptDragDropPayload() will returns true even before the mouse button is released. You can then call IsDelivery() to test if the payload needs to be delivered.
MAKE_ENUM(ImGuiDragDropFlags_AcceptBeforeDelivery)
//    ImGuiDragDropFlags_AcceptNoDrawDefaultRect      = 1 << 11,  // Do not draw the default highlight rectangle when hovering over target.
MAKE_ENUM(ImGuiDragDropFlags_AcceptNoDrawDefaultRect)
//    ImGuiDragDropFlags_AcceptNoPreviewTooltip       = 1 << 12,  // Request hiding the BeginDragDropSource tooltip from the BeginDragDropTarget site.
MAKE_ENUM(ImGuiDragDropFlags_AcceptNoPreviewTooltip)
//    ImGuiDragDropFlags_AcceptPeekOnly               = ImGuiDragDropFlags_AcceptBeforeDelivery | ImGuiDragDropFlags_AcceptNoDrawDefaultRect  // For peeking ahead and inspecting the payload before delivery.
MAKE_ENUM(ImGuiDragDropFlags_AcceptPeekOnly)

//enum ImGuiDataType_

//    ImGuiDataType_S8,       // signed char / char (with sensible compilers)
MAKE_ENUM(ImGuiDataType_S8)
//    ImGuiDataType_U8,       // unsigned char
MAKE_ENUM(ImGuiDataType_U8)
//    ImGuiDataType_S16,      // short
MAKE_ENUM(ImGuiDataType_S16)
//    ImGuiDataType_U16,      // unsigned short
MAKE_ENUM(ImGuiDataType_U16)
//    ImGuiDataType_S32,      // int
MAKE_ENUM(ImGuiDataType_S32)
//    ImGuiDataType_U32,      // unsigned int
MAKE_ENUM(ImGuiDataType_U32)
//    ImGuiDataType_S64,      // long long / __int64
MAKE_ENUM(ImGuiDataType_S64)
//    ImGuiDataType_U64,      // unsigned long long / unsigned __int64
MAKE_ENUM(ImGuiDataType_U64)
//    ImGuiDataType_Float,    // float
MAKE_ENUM(ImGuiDataType_Float)
//    ImGuiDataType_Double,   // double
MAKE_ENUM(ImGuiDataType_Double)
//    ImGuiDataType_COUNT
MAKE_ENUM(ImGuiDataType_COUNT)

//enum ImGuiDir_

//    ImGuiDir_None    = -1,
MAKE_ENUM(ImGuiDir_None)
//    ImGuiDir_Left    = 0,
MAKE_ENUM(ImGuiDir_Left)
//    ImGuiDir_Right   = 1,
MAKE_ENUM(ImGuiDir_Right)
//    ImGuiDir_Up      = 2,
MAKE_ENUM(ImGuiDir_Up)
//    ImGuiDir_Down    = 3,
MAKE_ENUM(ImGuiDir_Down)
//    ImGuiDir_COUNT
MAKE_ENUM(ImGuiDir_COUNT)

//enum ImGuiSortDirection_

//    ImGuiSortDirection_None         = 0,
MAKE_ENUM(ImGuiSortDirection_None)
//    ImGuiSortDirection_Ascending    = 1,    // Ascending = 0->9, A->Z etc.
MAKE_ENUM(ImGuiSortDirection_Ascending)
//    ImGuiSortDirection_Descending   = 2     // Descending = 9->0, Z->A etc.
MAKE_ENUM(ImGuiSortDirection_Descending)

//enum ImGuiKey_

//    ImGuiKey_Tab,
MAKE_ENUM(ImGuiKey_Tab)
//    ImGuiKey_LeftArrow,
MAKE_ENUM(ImGuiKey_LeftArrow)
//    ImGuiKey_RightArrow,
MAKE_ENUM(ImGuiKey_RightArrow)
//    ImGuiKey_UpArrow,
MAKE_ENUM(ImGuiKey_UpArrow)
//    ImGuiKey_DownArrow,
MAKE_ENUM(ImGuiKey_DownArrow)
//    ImGuiKey_PageUp,
MAKE_ENUM(ImGuiKey_PageUp)
//    ImGuiKey_PageDown,
MAKE_ENUM(ImGuiKey_PageDown)
//    ImGuiKey_Home,
MAKE_ENUM(ImGuiKey_Home)
//    ImGuiKey_End,
MAKE_ENUM(ImGuiKey_End)
//    ImGuiKey_Insert,
MAKE_ENUM(ImGuiKey_Insert)
//    ImGuiKey_Delete,
MAKE_ENUM(ImGuiKey_Delete)
//    ImGuiKey_Backspace,
MAKE_ENUM(ImGuiKey_Backspace)
//    ImGuiKey_Space,
MAKE_ENUM(ImGuiKey_Space)
//    ImGuiKey_Enter,
MAKE_ENUM(ImGuiKey_Enter)
//    ImGuiKey_Escape,
MAKE_ENUM(ImGuiKey_Escape)
//    ImGuiKey_KeyPadEnter,
MAKE_ENUM(ImGuiKey_KeyPadEnter)
//    ImGuiKey_A,                 // for text edit CTRL+A: select all
MAKE_ENUM(ImGuiKey_A)
//    ImGuiKey_C,                 // for text edit CTRL+C: copy
MAKE_ENUM(ImGuiKey_C)
//    ImGuiKey_V,                 // for text edit CTRL+V: paste
MAKE_ENUM(ImGuiKey_V)
//    ImGuiKey_X,                 // for text edit CTRL+X: cut
MAKE_ENUM(ImGuiKey_X)
//    ImGuiKey_Y,                 // for text edit CTRL+Y: redo
MAKE_ENUM(ImGuiKey_Y)
//    ImGuiKey_Z,                 // for text edit CTRL+Z: undo
MAKE_ENUM(ImGuiKey_Z)
//    ImGuiKey_COUNT
MAKE_ENUM(ImGuiKey_COUNT)

//enum ImGuiKeyModFlags_

//    ImGuiKeyModFlags_None       = 0,
MAKE_ENUM(ImGuiKeyModFlags_None)
//    ImGuiKeyModFlags_Ctrl       = 1 << 0,
MAKE_ENUM(ImGuiKeyModFlags_Ctrl)
//    ImGuiKeyModFlags_Shift      = 1 << 1,
MAKE_ENUM(ImGuiKeyModFlags_Shift)
//    ImGuiKeyModFlags_Alt        = 1 << 2,
MAKE_ENUM(ImGuiKeyModFlags_Alt)
//    ImGuiKeyModFlags_Super      = 1 << 3
MAKE_ENUM(ImGuiKeyModFlags_Super)

//enum ImGuiNavInput_

//    ImGuiNavInput_Activate,      // activate / open / toggle / tweak value       // e.g. Cross  (PS4), A (Xbox), A (Switch), Space (Keyboard)
MAKE_ENUM(ImGuiNavInput_Activate)
//    ImGuiNavInput_Cancel,        // cancel / close / exit                        // e.g. Circle (PS4), B (Xbox), B (Switch), Escape (Keyboard)
MAKE_ENUM(ImGuiNavInput_Cancel)
//    ImGuiNavInput_Input,         // text input / on-screen keyboard              // e.g. Triang.(PS4), Y (Xbox), X (Switch), Return (Keyboard)
MAKE_ENUM(ImGuiNavInput_Input)
//    ImGuiNavInput_Menu,          // tap: toggle menu / hold: focus, move, resize // e.g. Square (PS4), X (Xbox), Y (Switch), Alt (Keyboard)
MAKE_ENUM(ImGuiNavInput_Menu)
//    ImGuiNavInput_DpadLeft,      // move / tweak / resize window (w/ PadMenu)    // e.g. D-pad Left/Right/Up/Down (Gamepads), Arrow keys (Keyboard)
MAKE_ENUM(ImGuiNavInput_DpadLeft)
//    ImGuiNavInput_DpadRight,     //
MAKE_ENUM(ImGuiNavInput_DpadRight)
//    ImGuiNavInput_DpadUp,        //
MAKE_ENUM(ImGuiNavInput_DpadUp)
//    ImGuiNavInput_DpadDown,      //
MAKE_ENUM(ImGuiNavInput_DpadDown)
//    ImGuiNavInput_LStickLeft,    // scroll / move window (w/ PadMenu)            // e.g. Left Analog Stick Left/Right/Up/Down
MAKE_ENUM(ImGuiNavInput_LStickLeft)
//    ImGuiNavInput_LStickRight,   //
MAKE_ENUM(ImGuiNavInput_LStickRight)
//    ImGuiNavInput_LStickUp,      //
MAKE_ENUM(ImGuiNavInput_LStickUp)
//    ImGuiNavInput_LStickDown,    //
MAKE_ENUM(ImGuiNavInput_LStickDown)
//    ImGuiNavInput_FocusPrev,     // next window (w/ PadMenu)                     // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or ZL (Switch)
MAKE_ENUM(ImGuiNavInput_FocusPrev)
//    ImGuiNavInput_FocusNext,     // prev window (w/ PadMenu)                     // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or ZL (Switch)
MAKE_ENUM(ImGuiNavInput_FocusNext)
//    ImGuiNavInput_TweakSlow,     // slower tweaks                                // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or ZL (Switch)
MAKE_ENUM(ImGuiNavInput_TweakSlow)
//    ImGuiNavInput_TweakFast,     // faster tweaks                                // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or ZL (Switch)
MAKE_ENUM(ImGuiNavInput_TweakFast)
//    ImGuiNavInput_COUNT,
MAKE_ENUM(ImGuiNavInput_COUNT)

//enum ImGuiConfigFlags_

//    ImGuiConfigFlags_None                   = 0,
MAKE_ENUM(ImGuiConfigFlags_None)
//    ImGuiConfigFlags_NavEnableKeyboard      = 1 << 0,   // Master keyboard navigation enable flag. NewFrame() will automatically fill io.NavInputs[] based on io.KeysDown[].
MAKE_ENUM(ImGuiConfigFlags_NavEnableKeyboard)
//    ImGuiConfigFlags_NavEnableGamepad       = 1 << 1,   // Master gamepad navigation enable flag. This is mostly to instruct your imgui back-end to fill io.NavInputs[]. Back-end also needs to set ImGuiBackendFlags_HasGamepad.
MAKE_ENUM(ImGuiConfigFlags_NavEnableGamepad)
//    ImGuiConfigFlags_NavEnableSetMousePos   = 1 << 2,   // Instruct navigation to move the mouse cursor. May be useful on TV/console systems where moving a virtual mouse is awkward. Will update io.MousePos and set io.WantSetMousePos=true. If enabled you MUST honor io.WantSetMousePos requests in your binding, otherwise ImGui will react as if the mouse is jumping around back and forth.
MAKE_ENUM(ImGuiConfigFlags_NavEnableSetMousePos)
//    ImGuiConfigFlags_NavNoCaptureKeyboard   = 1 << 3,   // Instruct navigation to not set the io.WantCaptureKeyboard flag when io.NavActive is set.
MAKE_ENUM(ImGuiConfigFlags_NavNoCaptureKeyboard)
//    ImGuiConfigFlags_NoMouse                = 1 << 4,   // Instruct imgui to clear mouse position/buttons in NewFrame(). This allows ignoring the mouse information set by the back-end.
MAKE_ENUM(ImGuiConfigFlags_NoMouse)
//    ImGuiConfigFlags_NoMouseCursorChange    = 1 << 5,   // Instruct back-end to not alter mouse cursor shape and visibility. Use if the back-end cursor changes are interfering with yours and you don't want to use SetMouseCursor() to change mouse cursor. You may want to honor requests from imgui by reading GetMouseCursor() yourself instead.
MAKE_ENUM(ImGuiConfigFlags_NoMouseCursorChange)
//    ImGuiConfigFlags_DockingEnable          = 1 << 6,   // Docking enable flags.
MAKE_ENUM(ImGuiConfigFlags_DockingEnable)
//    ImGuiConfigFlags_ViewportsEnable        = 1 << 10,  // Viewport enable flags (require both ImGuiConfigFlags_PlatformHasViewports + ImGuiConfigFlags_RendererHasViewports set by the respective back-ends)
MAKE_ENUM(ImGuiConfigFlags_ViewportsEnable)
//    ImGuiConfigFlags_DpiEnableScaleViewports= 1 << 14,  // [BETA: Don't use] FIXME-DPI: Reposition and resize imgui windows when the DpiScale of a viewport changed (mostly useful for the main viewport hosting other window). Note that resizing the main window itself is up to your application.
MAKE_ENUM(ImGuiConfigFlags_DpiEnableScaleViewports)
//    ImGuiConfigFlags_DpiEnableScaleFonts    = 1 << 15,  // [BETA: Don't use] FIXME-DPI: Request bitmap-scaled fonts to match DpiScale. This is a very low-quality workaround. The correct way to handle DPI is _currently_ to replace the atlas and/or fonts in the Platform_OnChangedViewport callback, but this is all early work in progress.
MAKE_ENUM(ImGuiConfigFlags_DpiEnableScaleFonts)
//    ImGuiConfigFlags_IsSRGB                 = 1 << 20,  // Application is SRGB-aware.
MAKE_ENUM(ImGuiConfigFlags_IsSRGB)
//    ImGuiConfigFlags_IsTouchScreen          = 1 << 21   // Application is using a touch screen instead of a mouse.
MAKE_ENUM(ImGuiConfigFlags_IsTouchScreen)

//enum ImGuiBackendFlags_

//    ImGuiBackendFlags_None                  = 0,
MAKE_ENUM(ImGuiBackendFlags_None)
//    ImGuiBackendFlags_HasGamepad            = 1 << 0,   // Back-end Platform supports gamepad and currently has one connected.
MAKE_ENUM(ImGuiBackendFlags_HasGamepad)
//    ImGuiBackendFlags_HasMouseCursors       = 1 << 1,   // Back-end Platform supports honoring GetMouseCursor() value to change the OS cursor shape.
MAKE_ENUM(ImGuiBackendFlags_HasMouseCursors)
//    ImGuiBackendFlags_HasSetMousePos        = 1 << 2,   // Back-end Platform supports io.WantSetMousePos requests to reposition the OS mouse position (only used if ImGuiConfigFlags_NavEnableSetMousePos is set).
MAKE_ENUM(ImGuiBackendFlags_HasSetMousePos)
//    ImGuiBackendFlags_RendererHasVtxOffset  = 1 << 3,   // Back-end Renderer supports ImDrawCmd::VtxOffset. This enables output of large meshes (64K+ vertices) while still using 16-bit indices.
MAKE_ENUM(ImGuiBackendFlags_RendererHasVtxOffset)
//    ImGuiBackendFlags_PlatformHasViewports  = 1 << 10,  // Back-end Platform supports multiple viewports.
MAKE_ENUM(ImGuiBackendFlags_PlatformHasViewports)
//    ImGuiBackendFlags_HasMouseHoveredViewport=1 << 11,  // Back-end Platform supports setting io.MouseHoveredViewport to the viewport directly under the mouse _IGNORING_ viewports with the ImGuiViewportFlags_NoInputs flag and _REGARDLESS_ of whether another viewport is focused and may be capturing the mouse. This information is _NOT EASY_ to provide correctly with most high-level engines! Don't set this without studying how the examples/ back-end handle it!
MAKE_ENUM(ImGuiBackendFlags_HasMouseHoveredViewport)
//    ImGuiBackendFlags_RendererHasViewports  = 1 << 12   // Back-end Renderer supports multiple viewports.
MAKE_ENUM(ImGuiBackendFlags_RendererHasViewports)

//enum ImGuiCol_

//    ImGuiCol_Text,
MAKE_ENUM(ImGuiCol_Text)
//    ImGuiCol_TextDisabled,
MAKE_ENUM(ImGuiCol_TextDisabled)
//    ImGuiCol_WindowBg,              // Background of normal windows
MAKE_ENUM(ImGuiCol_WindowBg)
//    ImGuiCol_ChildBg,               // Background of child windows
MAKE_ENUM(ImGuiCol_ChildBg)
//    ImGuiCol_PopupBg,               // Background of popups, menus, tooltips windows
MAKE_ENUM(ImGuiCol_PopupBg)
//    ImGuiCol_Border,
MAKE_ENUM(ImGuiCol_Border)
//    ImGuiCol_BorderShadow,
MAKE_ENUM(ImGuiCol_BorderShadow)
//    ImGuiCol_FrameBg,               // Background of checkbox, radio button, plot, slider, text input
MAKE_ENUM(ImGuiCol_FrameBg)
//    ImGuiCol_FrameBgHovered,
MAKE_ENUM(ImGuiCol_FrameBgHovered)
//    ImGuiCol_FrameBgActive,
MAKE_ENUM(ImGuiCol_FrameBgActive)
//    ImGuiCol_TitleBg,
MAKE_ENUM(ImGuiCol_TitleBg)
//    ImGuiCol_TitleBgActive,
MAKE_ENUM(ImGuiCol_TitleBgActive)
//    ImGuiCol_TitleBgCollapsed,
MAKE_ENUM(ImGuiCol_TitleBgCollapsed)
//    ImGuiCol_MenuBarBg,
MAKE_ENUM(ImGuiCol_MenuBarBg)
//    ImGuiCol_ScrollbarBg,
MAKE_ENUM(ImGuiCol_ScrollbarBg)
//    ImGuiCol_ScrollbarGrab,
MAKE_ENUM(ImGuiCol_ScrollbarGrab)
//    ImGuiCol_ScrollbarGrabHovered,
MAKE_ENUM(ImGuiCol_ScrollbarGrabHovered)
//    ImGuiCol_ScrollbarGrabActive,
MAKE_ENUM(ImGuiCol_ScrollbarGrabActive)
//    ImGuiCol_CheckMark,
MAKE_ENUM(ImGuiCol_CheckMark)
//    ImGuiCol_SliderGrab,
MAKE_ENUM(ImGuiCol_SliderGrab)
//    ImGuiCol_SliderGrabActive,
MAKE_ENUM(ImGuiCol_SliderGrabActive)
//    ImGuiCol_Button,
MAKE_ENUM(ImGuiCol_Button)
//    ImGuiCol_ButtonHovered,
MAKE_ENUM(ImGuiCol_ButtonHovered)
//    ImGuiCol_ButtonActive,
MAKE_ENUM(ImGuiCol_ButtonActive)
//    ImGuiCol_Header,                // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
MAKE_ENUM(ImGuiCol_Header)
//    ImGuiCol_HeaderHovered,
MAKE_ENUM(ImGuiCol_HeaderHovered)
//    ImGuiCol_HeaderActive,
MAKE_ENUM(ImGuiCol_HeaderActive)
//    ImGuiCol_Separator,
MAKE_ENUM(ImGuiCol_Separator)
//    ImGuiCol_SeparatorHovered,
MAKE_ENUM(ImGuiCol_SeparatorHovered)
//    ImGuiCol_SeparatorActive,
MAKE_ENUM(ImGuiCol_SeparatorActive)
//    ImGuiCol_ResizeGrip,
MAKE_ENUM(ImGuiCol_ResizeGrip)
//    ImGuiCol_ResizeGripHovered,
MAKE_ENUM(ImGuiCol_ResizeGripHovered)
//    ImGuiCol_ResizeGripActive,
MAKE_ENUM(ImGuiCol_ResizeGripActive)
//    ImGuiCol_Tab,
MAKE_ENUM(ImGuiCol_Tab)
//    ImGuiCol_TabHovered,
MAKE_ENUM(ImGuiCol_TabHovered)
//    ImGuiCol_TabActive,
MAKE_ENUM(ImGuiCol_TabActive)
//    ImGuiCol_TabUnfocused,
MAKE_ENUM(ImGuiCol_TabUnfocused)
//    ImGuiCol_TabUnfocusedActive,
MAKE_ENUM(ImGuiCol_TabUnfocusedActive)
//    ImGuiCol_DockingPreview,        // Preview overlay color when about to docking something
MAKE_ENUM(ImGuiCol_DockingPreview)
//    ImGuiCol_DockingEmptyBg,        // Background color for empty node (e.g. CentralNode with no window docked into it)
MAKE_ENUM(ImGuiCol_DockingEmptyBg)
//    ImGuiCol_PlotLines,
MAKE_ENUM(ImGuiCol_PlotLines)
//    ImGuiCol_PlotLinesHovered,
MAKE_ENUM(ImGuiCol_PlotLinesHovered)
//    ImGuiCol_PlotHistogram,
MAKE_ENUM(ImGuiCol_PlotHistogram)
//    ImGuiCol_PlotHistogramHovered,
MAKE_ENUM(ImGuiCol_PlotHistogramHovered)
//    ImGuiCol_TableHeaderBg,         // Table header background
MAKE_ENUM(ImGuiCol_TableHeaderBg)
//    ImGuiCol_TableBorderStrong,     // Table outer and header borders (prefer using Alpha=1.0 here)
MAKE_ENUM(ImGuiCol_TableBorderStrong)
//    ImGuiCol_TableBorderLight,      // Table inner borders (prefer using Alpha=1.0 here)
MAKE_ENUM(ImGuiCol_TableBorderLight)
//    ImGuiCol_TableRowBg,            // Table row background (even rows)
MAKE_ENUM(ImGuiCol_TableRowBg)
//    ImGuiCol_TableRowBgAlt,         // Table row background (odd rows)
MAKE_ENUM(ImGuiCol_TableRowBgAlt)
//    ImGuiCol_TextSelectedBg,
MAKE_ENUM(ImGuiCol_TextSelectedBg)
//    ImGuiCol_DragDropTarget,
MAKE_ENUM(ImGuiCol_DragDropTarget)
//    ImGuiCol_NavHighlight,          // Gamepad/keyboard: current highlighted item
MAKE_ENUM(ImGuiCol_NavHighlight)
//    ImGuiCol_NavWindowingHighlight, // Highlight window when using CTRL+TAB
MAKE_ENUM(ImGuiCol_NavWindowingHighlight)
//    ImGuiCol_NavWindowingDimBg,     // Darken/colorize entire screen behind the CTRL+TAB window list, when active
MAKE_ENUM(ImGuiCol_NavWindowingDimBg)
//    ImGuiCol_ModalWindowDimBg,      // Darken/colorize entire screen behind a modal window, when one is active
MAKE_ENUM(ImGuiCol_ModalWindowDimBg)
//    ImGuiCol_COUNT
MAKE_ENUM(ImGuiCol_COUNT)

//enum ImGuiStyleVar_

//    ImGuiStyleVar_Alpha,               // float     Alpha
MAKE_ENUM(ImGuiStyleVar_Alpha)
//    ImGuiStyleVar_WindowPadding,       // ImVec2    WindowPadding
MAKE_ENUM(ImGuiStyleVar_WindowPadding)
//    ImGuiStyleVar_WindowRounding,      // float     WindowRounding
MAKE_ENUM(ImGuiStyleVar_WindowRounding)
//    ImGuiStyleVar_WindowBorderSize,    // float     WindowBorderSize
MAKE_ENUM(ImGuiStyleVar_WindowBorderSize)
//    ImGuiStyleVar_WindowMinSize,       // ImVec2    WindowMinSize
MAKE_ENUM(ImGuiStyleVar_WindowMinSize)
//    ImGuiStyleVar_WindowTitleAlign,    // ImVec2    WindowTitleAlign
MAKE_ENUM(ImGuiStyleVar_WindowTitleAlign)
//    ImGuiStyleVar_ChildRounding,       // float     ChildRounding
MAKE_ENUM(ImGuiStyleVar_ChildRounding)
//    ImGuiStyleVar_ChildBorderSize,     // float     ChildBorderSize
MAKE_ENUM(ImGuiStyleVar_ChildBorderSize)
//    ImGuiStyleVar_PopupRounding,       // float     PopupRounding
MAKE_ENUM(ImGuiStyleVar_PopupRounding)
//    ImGuiStyleVar_PopupBorderSize,     // float     PopupBorderSize
MAKE_ENUM(ImGuiStyleVar_PopupBorderSize)
//    ImGuiStyleVar_FramePadding,        // ImVec2    FramePadding
MAKE_ENUM(ImGuiStyleVar_FramePadding)
//    ImGuiStyleVar_FrameRounding,       // float     FrameRounding
MAKE_ENUM(ImGuiStyleVar_FrameRounding)
//    ImGuiStyleVar_FrameBorderSize,     // float     FrameBorderSize
MAKE_ENUM(ImGuiStyleVar_FrameBorderSize)
//    ImGuiStyleVar_ItemSpacing,         // ImVec2    ItemSpacing
MAKE_ENUM(ImGuiStyleVar_ItemSpacing)
//    ImGuiStyleVar_ItemInnerSpacing,    // ImVec2    ItemInnerSpacing
MAKE_ENUM(ImGuiStyleVar_ItemInnerSpacing)
//    ImGuiStyleVar_IndentSpacing,       // float     IndentSpacing
MAKE_ENUM(ImGuiStyleVar_IndentSpacing)
//    ImGuiStyleVar_CellPadding,         // ImVec2    CellPadding
MAKE_ENUM(ImGuiStyleVar_CellPadding)
//    ImGuiStyleVar_ScrollbarSize,       // float     ScrollbarSize
MAKE_ENUM(ImGuiStyleVar_ScrollbarSize)
//    ImGuiStyleVar_ScrollbarRounding,   // float     ScrollbarRounding
MAKE_ENUM(ImGuiStyleVar_ScrollbarRounding)
//    ImGuiStyleVar_GrabMinSize,         // float     GrabMinSize
MAKE_ENUM(ImGuiStyleVar_GrabMinSize)
//    ImGuiStyleVar_GrabRounding,        // float     GrabRounding
MAKE_ENUM(ImGuiStyleVar_GrabRounding)
//    ImGuiStyleVar_TabRounding,         // float     TabRounding
MAKE_ENUM(ImGuiStyleVar_TabRounding)
//    ImGuiStyleVar_ButtonTextAlign,     // ImVec2    ButtonTextAlign
MAKE_ENUM(ImGuiStyleVar_ButtonTextAlign)
//    ImGuiStyleVar_SelectableTextAlign, // ImVec2    SelectableTextAlign
MAKE_ENUM(ImGuiStyleVar_SelectableTextAlign)
//    ImGuiStyleVar_COUNT
MAKE_ENUM(ImGuiStyleVar_COUNT)

//enum ImGuiColorEditFlags_

//    ImGuiColorEditFlags_None            = 0,
MAKE_ENUM(ImGuiColorEditFlags_None)
//    ImGuiColorEditFlags_NoAlpha         = 1 << 1,   //              // ColorEdit, ColorPicker, ColorButton: ignore Alpha component (will only read 3 components from the input pointer).
MAKE_ENUM(ImGuiColorEditFlags_NoAlpha)
//    ImGuiColorEditFlags_NoPicker        = 1 << 2,   //              // ColorEdit: disable picker when clicking on colored square.
MAKE_ENUM(ImGuiColorEditFlags_NoPicker)
//    ImGuiColorEditFlags_NoOptions       = 1 << 3,   //              // ColorEdit: disable toggling options menu when right-clicking on inputs/small preview.
MAKE_ENUM(ImGuiColorEditFlags_NoOptions)
//    ImGuiColorEditFlags_NoSmallPreview  = 1 << 4,   //              // ColorEdit, ColorPicker: disable colored square preview next to the inputs. (e.g. to show only the inputs)
MAKE_ENUM(ImGuiColorEditFlags_NoSmallPreview)
//    ImGuiColorEditFlags_NoInputs        = 1 << 5,   //              // ColorEdit, ColorPicker: disable inputs sliders/text widgets (e.g. to show only the small preview colored square).
MAKE_ENUM(ImGuiColorEditFlags_NoInputs)
//    ImGuiColorEditFlags_NoTooltip       = 1 << 6,   //              // ColorEdit, ColorPicker, ColorButton: disable tooltip when hovering the preview.
MAKE_ENUM(ImGuiColorEditFlags_NoTooltip)
//    ImGuiColorEditFlags_NoLabel         = 1 << 7,   //              // ColorEdit, ColorPicker: disable display of inline text label (the label is still forwarded to the tooltip and picker).
MAKE_ENUM(ImGuiColorEditFlags_NoLabel)
//    ImGuiColorEditFlags_NoSidePreview   = 1 << 8,   //              // ColorPicker: disable bigger color preview on right side of the picker, use small colored square preview instead.
MAKE_ENUM(ImGuiColorEditFlags_NoSidePreview)
//    ImGuiColorEditFlags_NoDragDrop      = 1 << 9,   //              // ColorEdit: disable drag and drop target. ColorButton: disable drag and drop source.
MAKE_ENUM(ImGuiColorEditFlags_NoDragDrop)
//    ImGuiColorEditFlags_NoBorder        = 1 << 10,  //              // ColorButton: disable border (which is enforced by default)
MAKE_ENUM(ImGuiColorEditFlags_NoBorder)
//    ImGuiColorEditFlags_AlphaBar        = 1 << 16,  //              // ColorEdit, ColorPicker: show vertical alpha bar/gradient in picker.
MAKE_ENUM(ImGuiColorEditFlags_AlphaBar)
//    ImGuiColorEditFlags_AlphaPreview    = 1 << 17,  //              // ColorEdit, ColorPicker, ColorButton: display preview as a transparent color over a checkerboard, instead of opaque.
MAKE_ENUM(ImGuiColorEditFlags_AlphaPreview)
//    ImGuiColorEditFlags_AlphaPreviewHalf= 1 << 18,  //              // ColorEdit, ColorPicker, ColorButton: display half opaque / half checkerboard, instead of opaque.
MAKE_ENUM(ImGuiColorEditFlags_AlphaPreviewHalf)
//    ImGuiColorEditFlags_HDR             = 1 << 19,  //              // (WIP) ColorEdit: Currently only disable 0.0f..1.0f limits in RGBA edition (note: you probably want to use ImGuiColorEditFlags_Float flag as well).
MAKE_ENUM(ImGuiColorEditFlags_HDR)
//    ImGuiColorEditFlags_DisplayRGB      = 1 << 20,  // [Display]    // ColorEdit: override _display_ type among RGB/HSV/Hex. ColorPicker: select any combination using one or more of RGB/HSV/Hex.
MAKE_ENUM(ImGuiColorEditFlags_DisplayRGB)
//    ImGuiColorEditFlags_DisplayHSV      = 1 << 21,  // [Display]    // "
MAKE_ENUM(ImGuiColorEditFlags_DisplayHSV)
//    ImGuiColorEditFlags_DisplayHex      = 1 << 22,  // [Display]    // "
MAKE_ENUM(ImGuiColorEditFlags_DisplayHex)
//    ImGuiColorEditFlags_Uint8           = 1 << 23,  // [DataType]   // ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0..255.
MAKE_ENUM(ImGuiColorEditFlags_Uint8)
//    ImGuiColorEditFlags_Float           = 1 << 24,  // [DataType]   // ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0.0f..1.0f floats instead of 0..255 integers. No round-trip of value via integers.
MAKE_ENUM(ImGuiColorEditFlags_Float)
//    ImGuiColorEditFlags_PickerHueBar    = 1 << 25,  // [Picker]     // ColorPicker: bar for Hue, rectangle for Sat/Value.
MAKE_ENUM(ImGuiColorEditFlags_PickerHueBar)
//    ImGuiColorEditFlags_PickerHueWheel  = 1 << 26,  // [Picker]     // ColorPicker: wheel for Hue, triangle for Sat/Value.
MAKE_ENUM(ImGuiColorEditFlags_PickerHueWheel)
//    ImGuiColorEditFlags_InputRGB        = 1 << 27,  // [Input]      // ColorEdit, ColorPicker: input and output data in RGB format.
MAKE_ENUM(ImGuiColorEditFlags_InputRGB)
//    ImGuiColorEditFlags_InputHSV        = 1 << 28,  // [Input]      // ColorEdit, ColorPicker: input and output data in HSV format.
MAKE_ENUM(ImGuiColorEditFlags_InputHSV)

//enum ImGuiMouseButton_

//    ImGuiMouseButton_Left = 0,
MAKE_ENUM(ImGuiMouseButton_Left)
//    ImGuiMouseButton_Right = 1,
MAKE_ENUM(ImGuiMouseButton_Right)
//    ImGuiMouseButton_Middle = 2,
MAKE_ENUM(ImGuiMouseButton_Middle)
//    ImGuiMouseButton_COUNT = 5
MAKE_ENUM(ImGuiMouseButton_COUNT)

//enum ImGuiMouseCursor_

//    ImGuiMouseCursor_None = -1,
MAKE_ENUM(ImGuiMouseCursor_None)
//    ImGuiMouseCursor_Arrow = 0,
MAKE_ENUM(ImGuiMouseCursor_Arrow)
//    ImGuiMouseCursor_TextInput,         // When hovering over InputText, etc.
MAKE_ENUM(ImGuiMouseCursor_TextInput)
//    ImGuiMouseCursor_ResizeAll,         // (Unused by Dear ImGui functions)
MAKE_ENUM(ImGuiMouseCursor_ResizeAll)
//    ImGuiMouseCursor_ResizeNS,          // When hovering over an horizontal border
MAKE_ENUM(ImGuiMouseCursor_ResizeNS)
//    ImGuiMouseCursor_ResizeEW,          // When hovering over a vertical border or a column
MAKE_ENUM(ImGuiMouseCursor_ResizeEW)
//    ImGuiMouseCursor_ResizeNESW,        // When hovering over the bottom-left corner of a window
MAKE_ENUM(ImGuiMouseCursor_ResizeNESW)
//    ImGuiMouseCursor_ResizeNWSE,        // When hovering over the bottom-right corner of a window
MAKE_ENUM(ImGuiMouseCursor_ResizeNWSE)
//    ImGuiMouseCursor_Hand,              // (Unused by Dear ImGui functions. Use for e.g. hyperlinks)
MAKE_ENUM(ImGuiMouseCursor_Hand)
//    ImGuiMouseCursor_NotAllowed,        // When hovering something with disallowed interaction. Usually a crossed circle.
MAKE_ENUM(ImGuiMouseCursor_NotAllowed)
//    ImGuiMouseCursor_COUNT
MAKE_ENUM(ImGuiMouseCursor_COUNT)

//enum ImGuiCond_

//    ImGuiCond_None          = 0,        // No condition (always set the variable), same as _Always
MAKE_ENUM(ImGuiCond_None)
//    ImGuiCond_Always        = 1 << 0,   // No condition (always set the variable)
MAKE_ENUM(ImGuiCond_Always)
//    ImGuiCond_Once          = 1 << 1,   // Set the variable once per runtime session (only the first call will succeed)
MAKE_ENUM(ImGuiCond_Once)
//    ImGuiCond_FirstUseEver  = 1 << 2,   // Set the variable if the object/window has no persistently saved data (no entry in .ini file)
MAKE_ENUM(ImGuiCond_FirstUseEver)
//    ImGuiCond_Appearing     = 1 << 3    // Set the variable if the object/window is appearing after being hidden/inactive (or the first time)
MAKE_ENUM(ImGuiCond_Appearing)

//enum ImDrawCornerFlags_

//    ImDrawCornerFlags_None      = 0,
MAKE_ENUM(ImDrawCornerFlags_None)
//    ImDrawCornerFlags_TopLeft   = 1 << 0, // 0x1
MAKE_ENUM(ImDrawCornerFlags_TopLeft)
//    ImDrawCornerFlags_TopRight  = 1 << 1, // 0x2
MAKE_ENUM(ImDrawCornerFlags_TopRight)
//    ImDrawCornerFlags_BotLeft   = 1 << 2, // 0x4
MAKE_ENUM(ImDrawCornerFlags_BotLeft)
//    ImDrawCornerFlags_BotRight  = 1 << 3, // 0x8
MAKE_ENUM(ImDrawCornerFlags_BotRight)
//    ImDrawCornerFlags_Top       = ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_TopRight,   // 0x3
MAKE_ENUM(ImDrawCornerFlags_Top)
//    ImDrawCornerFlags_Bot       = ImDrawCornerFlags_BotLeft | ImDrawCornerFlags_BotRight,   // 0xC
MAKE_ENUM(ImDrawCornerFlags_Bot)
//    ImDrawCornerFlags_Left      = ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_BotLeft,    // 0x5
MAKE_ENUM(ImDrawCornerFlags_Left)
//    ImDrawCornerFlags_Right     = ImDrawCornerFlags_TopRight | ImDrawCornerFlags_BotRight,  // 0xA
MAKE_ENUM(ImDrawCornerFlags_Right)
//    ImDrawCornerFlags_All       = 0xF     // In your function calls you may use ~0 (= all bits sets) instead of ImDrawCornerFlags_All, as a convenience
MAKE_ENUM(ImDrawCornerFlags_All)

//enum ImDrawListFlags_

//    ImDrawListFlags_None                    = 0,
MAKE_ENUM(ImDrawListFlags_None)
//    ImDrawListFlags_AntiAliasedLines        = 1 << 0,  // Enable anti-aliased lines/borders (*2 the number of triangles for 1.0f wide line or lines thin enough to be drawn using textures, otherwise *3 the number of triangles)
MAKE_ENUM(ImDrawListFlags_AntiAliasedLines)
//    ImDrawListFlags_AntiAliasedLinesUseTex  = 1 << 1,  // Enable anti-aliased lines/borders using textures when possible. Require back-end to render with bilinear filtering.
MAKE_ENUM(ImDrawListFlags_AntiAliasedLinesUseTex)
//    ImDrawListFlags_AntiAliasedFill         = 1 << 2,  // Enable anti-aliased edge around filled shapes (rounded rectangles, circles).
MAKE_ENUM(ImDrawListFlags_AntiAliasedFill)
//    ImDrawListFlags_AllowVtxOffset          = 1 << 3   // Can emit 'VtxOffset > 0' to allow large meshes. Set when 'ImGuiBackendFlags_RendererHasVtxOffset' is enabled.
MAKE_ENUM(ImDrawListFlags_AllowVtxOffset)

//enum ImGuiViewportFlags_

//    ImGuiViewportFlags_None                     = 0,
MAKE_ENUM(ImGuiViewportFlags_None)
//    ImGuiViewportFlags_NoDecoration             = 1 << 0,   // Platform Window: Disable platform decorations: title bar, borders, etc. (generally set all windows, but if ImGuiConfigFlags_ViewportsDecoration is set we only set this on popups/tooltips)
MAKE_ENUM(ImGuiViewportFlags_NoDecoration)
//    ImGuiViewportFlags_NoTaskBarIcon            = 1 << 1,   // Platform Window: Disable platform task bar icon (generally set on popups/tooltips, or all windows if ImGuiConfigFlags_ViewportsNoTaskBarIcon is set)
MAKE_ENUM(ImGuiViewportFlags_NoTaskBarIcon)
//    ImGuiViewportFlags_NoFocusOnAppearing       = 1 << 2,   // Platform Window: Don't take focus when created.
MAKE_ENUM(ImGuiViewportFlags_NoFocusOnAppearing)
//    ImGuiViewportFlags_NoFocusOnClick           = 1 << 3,   // Platform Window: Don't take focus when clicked on.
MAKE_ENUM(ImGuiViewportFlags_NoFocusOnClick)
//    ImGuiViewportFlags_NoInputs                 = 1 << 4,   // Platform Window: Make mouse pass through so we can drag this window while peaking behind it.
MAKE_ENUM(ImGuiViewportFlags_NoInputs)
//    ImGuiViewportFlags_NoRendererClear          = 1 << 5,   // Platform Window: Renderer doesn't need to clear the framebuffer ahead (because we will fill it entirely).
MAKE_ENUM(ImGuiViewportFlags_NoRendererClear)
//    ImGuiViewportFlags_TopMost                  = 1 << 6,   // Platform Window: Display on top (for tooltips only).
MAKE_ENUM(ImGuiViewportFlags_TopMost)
//    ImGuiViewportFlags_Minimized                = 1 << 7,   // Platform Window: Window is minimized, can skip render. When minimized we tend to avoid using the viewport pos/size for clipping window or testing if they are contained in the viewport.
MAKE_ENUM(ImGuiViewportFlags_Minimized)
//    ImGuiViewportFlags_NoAutoMerge              = 1 << 8,   // Platform Window: Avoid merging this window into another host window. This can only be set via ImGuiWindowClass viewport flags override (because we need to now ahead if we are going to create a viewport in the first place!).
MAKE_ENUM(ImGuiViewportFlags_NoAutoMerge)
//    ImGuiViewportFlags_CanHostOtherWindows      = 1 << 9    // Main viewport: can host multiple imgui windows (secondary viewports are associated to a single window).
MAKE_ENUM(ImGuiViewportFlags_CanHostOtherWindows)

