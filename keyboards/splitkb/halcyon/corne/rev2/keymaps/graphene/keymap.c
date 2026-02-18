#include "graphene.h"

#define LAYOUT_wrapper(...) LAYOUT_corne_hlc(__VA_ARGS__)

#define __MUTE_AND_NOs__  KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_wrapper(
    TO(GAMING),     ________BASE_1_L________, ________BASE_1_R________, TO(SHORTCUTS),
    KC_ESC,         ________BASE_2_L________, ________BASE_2_R________, KC_ENTER,
    KC_EQUAL,       ________BASE_3_L________, ________BASE_3_R________, KC_SLASH,
                       MS_BTN1, __BASE_4_L__, __BASE_4_R__, MS_BTN2,
    __MUTE_AND_NOs__,                                                 __MUTE_AND_NOs__
  ),
  [SHORTCUTS] = LAYOUT_wrapper(
    TO(BASE),       ___SHORTCUTS_1_L________, ___SHORTCUTS_1_R________, TO(SYM_A),
    KC_BRIU,        ___SHORTCUTS_2_L________, ___SHORTCUTS_2_R________, _______,
    KC_BRID,        ___SHORTCUTS_3_L________, ___SHORTCUTS_3_R________, _______,
                       DB_TOGG, __TRNS_2____, __TRNS_2____, _______,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
  [SYM_A] = LAYOUT_wrapper(
    TO(SHORTCUTS),  _______SYM_A_1_L________, _______SYM_A_1_R________, TO(SYM_B),
    _______,        _______SYM_A_2_L________, _______SYM_A_2_R________, _______,
    _______,        _______SYM_A_3_L________, _______SYM_A_3_R________, _______,
                       _______, __TRNS_2____, __TRNS_2____, _______,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
  [SYM_B] = LAYOUT_wrapper(
    TO(SYM_A),      _______SYM_B_1_L________, _______SYM_B_1_R________, TO(SYS_NUM),
    _______,        _______SYM_B_2_L________, _______SYM_B_2_R________, _______,
    _______,        _______SYM_B_3_L________, _______SYM_B_3_R________, _______,
                       _______, __TRNS_2____, __TRNS_2____, _______,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
  [SYS_NUM] = LAYOUT_wrapper(
    TO(SYM_B),      _____SYS_NUM_1_L________, _____SYS_NUM_1_R________, TO(GAMING),
    _______,        _____SYS_NUM_2_L________, _____SYS_NUM_2_R________, KC_LPRN,
    _______,        _____SYS_NUM_3_L________, _____SYS_NUM_3_R________, KC_RPRN,
                       _______, __TRNS_2____, __SYSN_4_R__, _______,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
  [GAMING] = LAYOUT_wrapper(
    TO(SYS_NUM),    ______GAMING_1_L________, ______GAMING_1_R________, TO(BASE),
    LGUI_T(KC_ESC), ______GAMING_2_L________, ______GAMING_2_R________, DM_REC1,
    KC_LSFT,        ______GAMING_3_L________, ______GAMING_3_R________, DM_REC2,
              LALT_T(KC_GRAVE), __GMNG_4_L__, __GMNG_4_R__, KC_BSPC,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
  [SPECIAL] = LAYOUT_wrapper(
                    ______RGB_MATRIX_6______, ________HUN_OOUU________, _______,
                    _______UNDERGLOW_6______, ________TRNS_5__________, _______,
                    ___KBRD_CNTL_ETC_6______, ___KBRD_CNTL_ETC_6_R____,
                       _______, __TRNS_2____, __TRNS_2____, _______,
    ________TRNS_5__________,                                 ________TRNS_5__________
  ),
};

#define RGB_LAYOUT(l0A, l0B, l0C, l0D, l0E, l0F, l1A, l1B, l1C, l1D, l1E, l1F, l2A, l2B, l2C, l2D, l2E, l2F, l3D, l3E, l3F, r0A, r0B, r0C, r0D, r0E, r0F, r1A, r1B, r1C, r1D, r1E, r1F, r2A, r2B, r2C, r2D, r2E, r2F, r3A, r3B, r3C) { \
  COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, \
  l3F, l3E, l3D, \
  l2F, l2E, l2D, l2C, l2B, \
  l1F, l1E, l1D, l1C, l1B, \
  l0F, l0E, l0D, l0C, l0B, l0A, l1A, l2A, \
  COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, COL_BLACK, \
  r3A, r3B, r3C, \
  r2A, r2B, r2C, r2D, r2E, \
  r1A, r1B, r1C, r1D, r1E, \
  r0A, r0B, r0C, r0D, r0E, r0F, r1F, r2F \
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [SYS_NUM] = RGB_LAYOUT(
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
                                                    COL_BLACK,      COL_BLACK,      COL_BLACK,

    COL_BLACK,      COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_OPERATOR,   COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_NUMBER,     COL_BLACK,      COL_BLACK
  ),
  [GAMING] = RGB_LAYOUT(
    COL_TABS,       COL_BLACK,      COL_WASD,       COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_ESC,        COL_WASD,       COL_WASD,       COL_WASD,       COL_BLACK,      COL_BLACK,
    COL_SHIFT,      COL_0MP,        COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
                                                    COL_BLACK,      COL_NUMBER,     COL_BLACK,

    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_0MP,        COL_0MP,        COL_BLACK
  ),
};

#include "graphene.c"

static bool scrolling_mode = false;

#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case SHORTCUTS:  // If we're on the SHORTCUTS layer enable scrolling mode
      scrolling_mode = true;
      break;
    default:
      if (scrolling_mode) {  // check if we were scrolling before and set disable if so
        scrolling_mode = false;
      }
      break;
  }
  return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  if (scrolling_mode) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += -(float)mouse_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  return mouse_report;
}
