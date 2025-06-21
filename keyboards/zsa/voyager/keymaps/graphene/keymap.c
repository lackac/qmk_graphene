#include "voyager.h"
#include "graphene.h"

#define LAYOUT_wrapper(...) LAYOUT_voyager(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_wrapper(
    TO(GAMING),     ________BASE_0_L________, ________BASE_0_R________, TO(SHORTCUTS),
    KC_GRAVE,       ________BASE_1_L________, ________BASE_1_R________, KC_SEMICOLON,
    KC_ESC,         ________BASE_2_L________, ________BASE_2_R________, KC_ENTER,
    KC_EQUAL,       ________BASE_3_L________, ________BASE_3_R________, KC_SLASH,
                                __BASE_4_L__, __BASE_4_R__
  ),
  [SHORTCUTS] = LAYOUT_wrapper(
    TO(BASE),       ________TRNS_5__________, ________TRNS_5__________, TO(SYM_A),
    KC_BRIU,        ___SHORTCUTS_1_L________, ___SHORTCUTS_1_R________, _______,
    KC_BRID,        ___SHORTCUTS_2_L________, ___SHORTCUTS_2_R________, _______,
    DB_TOGG,        ___SHORTCUTS_3_L________, ___SHORTCUTS_3_R________, _______,
                                __TRNS_2____, __TRNS_2____
  ),
  [SYM_A] = LAYOUT_wrapper(
    TO(SHORTCUTS),  ________TRNS_5__________, ________TRNS_5__________, TO(SYM_B),
    _______,        _______SYM_A_1_L________, _______SYM_A_1_R________, _______,
    _______,        _______SYM_A_2_L________, _______SYM_A_2_R________, _______,
    _______,        _______SYM_A_3_L________, _______SYM_A_3_R________, _______,
                                __TRNS_2____, __TRNS_2____
  ),
  [SYM_B] = LAYOUT_wrapper(
    TO(SYM_A),      ________TRNS_5__________, ________TRNS_5__________, TO(SYS_NUM),
    _______,        _______SYM_B_1_L________, _______SYM_B_1_R________, _______,
    _______,        _______SYM_B_2_L________, _______SYM_B_2_R________, _______,
    _______,        _______SYM_B_3_L________, _______SYM_B_3_R________, _______,
                                __TRNS_2____, __TRNS_2____
  ),
  [SYS_NUM] = LAYOUT_wrapper(
    TO(SYM_B),      _____SYS_NUM_0_L________, _____SYS_NUM_0_R________, TO(GAMING),
    _______,        _____SYS_NUM_1_L________, _____SYS_NUM_1_R________, KC_CIRC,
    _______,        _____SYS_NUM_2_L________, _____SYS_NUM_2_R________, KC_LPRN,
    _______,        _____SYS_NUM_3_L________, _____SYS_NUM_3_R________, KC_RPRN,
                                __TRNS_2____, __SYSN_4_R__
  ),
  [GAMING] = LAYOUT_wrapper(
    TO(SYS_NUM),    ______GAMING_0_L________, ________TRNS_5__________, TO(BASE),
    KC_GRAVE,       ______GAMING_1_L________, ________TRNS_5__________, DM_REC1,
    _______,        ______GAMING_2_L________, ________TRNS_5__________, DM_REC2,
    KC_LSFT,        ______GAMING_3_L________, ________TRNS_5__________, DM_RSTP,
                                __GMNG_4_L__, __TRNS_2____
  ),
  [SPECIAL] = LAYOUT_wrapper(
    _______,        ________TRNS_5__________, ________TRNS_5__________, _______,
    _______,        ________TRNS_5__________, ________HUN_OOUU________, _______,
    _______,        ________TRNS_5__________, ________TRNS_5__________, _______,
    _______,        ________TRNS_5__________, ________TRNS_5__________, _______,
                                __TRNS_2____, __TRNS_2____
  ),
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [SYS_NUM] = {
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
                                                                    COL_BLACK,      COL_BLACK,

    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_OPERATOR,   COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_NUMBER,     COL_OPERATOR,   COL_OPERATOR,
    COL_NUMBER,     COL_BLACK,
  },
  [GAMING] = {
    COL_BLACK,      COL_0MP,        COL_1234,       COL_1234,       COL_1234,       COL_1234,
    COL_TABS,       COL_TABS,       COL_BLACK,      COL_WASD,       COL_BLACK,      COL_BLACK,
    COL_ESC,        COL_BLACK,      COL_WASD,       COL_WASD,       COL_WASD,       COL_BLACK,
    COL_SHIFT,      COL_0MP,        COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
                                                                    COL_NUMBER,     COL_0MP,

    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,      COL_BLACK,
    COL_BLACK,      COL_BLACK,
  },
};

#include "graphene.c"
