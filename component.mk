#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_ADD_INCLUDEDIRS :=  src 3rd/SDL/include 3rd src/ext_widgets

COMPONENT_SRCDIRS := src src/lcd src/blend src/base src/tkc src/ui_loader\
	src/xml src/widgets src/misc src/font_loader src/image_loader src/input_methods\
	src/clip_board src/compressors src/dialog_highlighters src/layouters src/main_loop \
	src/native_window src/platforms/freertos src/streams/buffered src/ubjson src/widget_animators src/svg\
	src/ext_widgets src/ext_widgets/rich_text src/ext_widgets/color_picker \
	src/ext_widgets/combo_box_ex src/ext_widgets/gif_image  src/ext_widgets/image_animation \
	src/ext_widgets/image_value src/ext_widgets/keyboard src/ext_widgets/mledit src/ext_widgets/mutable_image \
	src/ext_widgets/progress_circle src/ext_widgets/scroll_label src/ext_widgets/scroll_view src/ext_widgets/slide_menu \
	src/ext_widgets/slide_view src/ext_widgets/svg_image src/ext_widgets/switch src/ext_widgets/text_selector src/ext_widgets/time_clock\
	src/window_animators src/window_manager 3rd/libunibreak 3rd/SDL 3rd/stb demos src/ext_widgets/guage src/ext_widgets/canvas_widget

# src/ext_widgets/guage src/blend
# COMPONENT_OBJS += src/input_engines/input_engine_null.o demos/demo_main.o

CFLAGS +=  -Wno-char-subscripts -DHAS_AWTK_CONFIG #-DHAS_STDIO