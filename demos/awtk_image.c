/**
 * File:   image.c
 * Author: AWTK Develop Team
 * Brief:  image demo
 *
 * Copyright (c) 2018 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-08-16 Li XianJing <xianjimli@hotmail.com> created
 *
 */
#include "awtk.h"
#if 1

static ret_t on_inc(void* ctx, event_t* e) {
  widget_t* win = WIDGET(ctx);
  widget_t* bar1 = widget_child(win, "bar1");
  widget_t* bar2 = widget_child(win, "bar2");

  widget_add_value(bar1, 10);
  widget_add_value(bar2, 10);

  return RET_OK;
}

static ret_t on_dec(void* ctx, event_t* e) {
  widget_t* win = WIDGET(ctx);
  widget_t* bar1 = widget_child(win, "bar1");
  widget_t* bar2 = widget_child(win, "bar2");

  widget_add_value(bar1, -10);
  widget_add_value(bar2, -10);

  return RET_OK;
}

static ret_t on_close(void* ctx, event_t* e) {
  widget_t* win = WIDGET(ctx);
  widget_t* bar1 = widget_child(win, "bar1");
  widget_t* bar2 = widget_child(win, "bar2");

  log_debug("bar1->value=%d\n", (int)(widget_get_value(bar1)));
  log_debug("bar2->value=%d\n", (int)(widget_get_value(bar2)));

  tk_quit();

  return RET_OK;
}

ret_t application_init() {
  widget_t* win = window_open("basic");

  widget_child_on(win, "inc_value", EVT_CLICK, on_inc, win);
  widget_child_on(win, "dec_value", EVT_CLICK, on_dec, win);
  widget_child_on(win, "close", EVT_CLICK, on_close, win);

  return RET_OK;
}

// widget_t* create_image(widget_t* win, const char* image_name, image_draw_type_t draw_type) {
//   widget_t* image = image_create(win, 0, 0, 0, 0);

//   widget_use_style(image, "border");
//   image_set_draw_type(image, draw_type);
//   image_set_image(image, image_name);

//   return image;
// }

// ret_t application_init() {
//   widget_t* image = NULL;
//   widget_t* win = window_create(NULL, 0, 0, 0, 0);

//   image = create_image(win, "earth", IMAGE_DRAW_ICON);
//   image_set_rotation(image, 0.5);
//   image_set_scale(image, 1, 2);

//   image = create_image(win, "earth", IMAGE_DRAW_CENTER);
//   image = create_image(win, "earth", IMAGE_DRAW_SCALE_AUTO);

//   image = create_image(win, "1", IMAGE_DRAW_SCALE);
//   image = create_image(win, "2", IMAGE_DRAW_SCALE_W);
//   image = create_image(win, "3", IMAGE_DRAW_SCALE_H);

//   image = create_image(win, "bricks", IMAGE_DRAW_REPEAT);
//   image = create_image(win, "bricks", IMAGE_DRAW_REPEAT_X);
//   image = create_image(win, "bricks", IMAGE_DRAW_REPEAT_Y);

//   widget_set_children_layout(win, "default(r=3,c=3,m=2,s=2)");
//   widget_layout(win);
//   return RET_OK;
// }

#else

static ret_t on_dialog_btn_click(void* ctx, event_t* evt) {
  widget_t* win = widget_get_window(WIDGET(evt->target));

  window_close(win);

  return RET_OK;
}

static ret_t on_show_dialog(void* ctx, event_t* evt) {
  widget_t* ok = NULL;
  widget_t* cancel = NULL;
  widget_t* label = NULL;

  widget_t* dlg = dialog_create_simple(NULL, 0, 0, 240, 160);

  dialog_set_title(dlg, "Dialog");

  ok = button_create(dialog_get_client(dlg), 20, 80, 80, 30);
  widget_set_text(ok, L"Go");

  cancel = button_create(dialog_get_client(dlg), 140, 80, 80, 30);
  widget_set_text(cancel, L"Cancel");

  label = label_create(dialog_get_client(dlg), 10, 30, 200, 30);
  widget_set_text(label, L"AWTK is cool!");

  widget_on(ok, EVT_CLICK, on_dialog_btn_click, (char*)NULL + 1);
  widget_on(cancel, EVT_CLICK, on_dialog_btn_click, (char*)NULL + 2);

  return RET_OK;
}

ret_t application_init() {
  widget_t* win = window_create(NULL, 0, 0, 0, 0);
  widget_t* show_dialog = button_create(win, 0, 0, 0, 0);
  widget_t* show_dialog_long_press = button_create(win, 0, 0, 0, 0);

  widget_set_text(show_dialog, L"Show Dialog");
  widget_set_self_layout_params(show_dialog, "center", "middle:-30", "50%", "30");
  widget_on(show_dialog, EVT_CLICK, on_show_dialog, NULL);

  button_set_enable_long_press(show_dialog_long_press, TRUE);
  widget_set_text(show_dialog_long_press, L"Show Dialog On LongPress");
  widget_set_self_layout_params(show_dialog_long_press, "center", "middle:30", "80%", "30");
  widget_on(show_dialog_long_press, EVT_LONG_PRESS, on_show_dialog, NULL);

  widget_layout(win);
  return RET_OK;
}
#endif
#include "demo_main.c"
