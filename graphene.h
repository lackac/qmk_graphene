#pragma once

#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

#define LCS(kc) (QK_LCTL | QK_LSFT | (kc))

#define C_MAGIC QK_AREP

enum layers {
  BASE,
  SHORTCUTS,
  SYM_A,
  SYM_B,
  SYS_NUM,
  GAMING,
  SPECIAL,
};

enum custom_keycodes {
  RGB_FAV = SAFE_RANGE,
  C_MAG_2,
  C_MAG_3,
  MG_ATION,
  MG_EFORE,
  MG_ENT,
  MG_ER,
  MG_ING,
  MG_ION,
  MG_ITH,
  MG_ON,
  MG_PERI,
  MG_SP_BUT,
  MG_THE,
  MG_UEST,
  MG_UST,
};

// row definitions for assembling layers in keymaps
#define __TRNS_2____              _______,        _______
#define ________TRNS_5__________  _______,        _______,        _______,        _______,        _______


#define ________BASE_0_L________  KC_1,           KC_2,           KC_3,           KC_4,           KC_5
#define ________BASE_1_L________  LGUI_T(KC_B),   LCTL_T(KC_L),   LALT_T(KC_D),   LGUI_T(KC_W),   KC_Z
#define ________BASE_2_L________  LT(4, KC_N),    LT(3, KC_R),    LT(2, KC_T),    LT(1, KC_S),    LT(6, KC_G)
#define ________BASE_3_L________  KC_Q,           KC_X,           KC_M,           KC_C,           KC_V
#define __BASE_4_L__                                                              HYPR_T(KC_SPC), LSFT_T(KC_TAB)

#define ________BASE_0_R________  KC_6,           KC_7,           KC_8,           KC_9,           KC_0
#define ________BASE_1_R________  C_MAGIC,        RGUI_T(KC_F),   RALT_T(KC_O),   RCTL_T(KC_U),   RGUI_T(KC_J)
#define ________BASE_2_R________  LT(6, KC_Y),    LT(1, KC_H),    LT(2, KC_A),    LT(3, KC_E),    LT(4, KC_I)
#define ________BASE_3_R________  KC_K,           KC_P,           KC_QUOTE,       KC_COMMA,       KC_DOT
#define __BASE_4_R__              RSFT_T(QK_REP), LT(1, KC_BSPC)


#define ___SHORTCUTS_0_L________  RGB_TOG,        RGB_M_P,        RGB_MOD,        RGB_SPD,        RGB_SPI
#define ___SHORTCUTS_1_L________  RGB_FAV,        KC_ESCAPE,      _______,        _______,        KC_VOLU
#define ___SHORTCUTS_2_L________  LGUI(KC_GRAVE), MEH_T(KC_HOME), C_S_T(KC_PGUP), _______,        KC_VOLD
#define ___SHORTCUTS_3_L________  QK_KB,          KC_END,         KC_PGDN,        CW_TOGG,        KC_MUTE

#define ___SHORTCUTS_0_R________  RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        RGB_SAI
#define ___SHORTCUTS_1_R________  LGUI(KC_LBRC),  LCS(KC_TAB),    LCTL(KC_TAB),   LGUI(KC_RBRC),  RGB_SAD
#define ___SHORTCUTS_2_R________  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ENTER
#define ___SHORTCUTS_3_R________  _______,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MSTP


#define _______SYM_A_1_L________  _______,        KC_AT,          KC_HASH,        KC_PLUS,        _______
#define _______SYM_A_2_L________  KC_GRAVE,       KC_TILD,        KC_UNDS,        KC_MINUS,       KC_SLASH
#define _______SYM_A_3_L________  _______,        _______,        _______,        KC_ASTR,        _______

#define _______SYM_A_1_R________  _______,        KC_LABK,        KC_RABK,        KC_CIRCUMFLEX,  _______
#define _______SYM_A_2_R________  KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_PIPE,        KC_BACKSLASH
#define _______SYM_A_3_R________  _______,        KC_DLR,         LALT(KC_3),     LSA(KC_2),      _______


#define _______SYM_B_1_L________  _______,        KC_AT,          LALT(KC_LBRC),  LALT(KC_RBRC),  _______
#define _______SYM_B_2_L________  KC_ASTR,        KC_PERC,        KC_EXLM,        KC_DQUO,        KC_QUOTE
#define _______SYM_B_3_L________  _______,        KC_HASH,        KC_QUES,        KC_DLR,         _______

#define _______SYM_B_1_R________  _______,        KC_LPRN,        KC_RPRN,        KC_SCLN,        _______
#define _______SYM_B_2_R________  _______,        KC_LBRC,        KC_RBRC,        KC_AMPR,        KC_COLN
#define _______SYM_B_3_R________  _______,        KC_LCBR,        KC_RCBR,        _______,        _______


#define _____SYS_NUM_0_L________  KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5
#define _____SYS_NUM_1_L________  KC_1,           LCTL_T(KC_2),   LALT_T(KC_3),   LGUI_T(KC_4),   KC_5
#define _____SYS_NUM_2_L________  LCS(KC_SCLN),   LCS(KC_QUOTE),  LCS(KC_LBRC),   LCS(KC_RBRC),   LCS(KC_MINUS)
#define _____SYS_NUM_3_L________  LCS(KC_Z),      LCS(KC_COMMA),  LCS(KC_DOT),    LCS(KC_C),      LCS(KC_EQUAL)

#define _____SYS_NUM_0_R________  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10
#define _____SYS_NUM_1_R________  KC_6,           RGUI_T(KC_7),   RALT_T(KC_8),   RCTL_T(KC_9),   KC_MINUS
#define _____SYS_NUM_2_R________  KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_ENTER
#define _____SYS_NUM_3_R________  KC_EQUAL,       KC_1,           KC_2,           KC_3,           _______
#define __SYSN_4_R__              RSFT_T(KC_0),   _______


#define ______GAMING_0_L________  KC_1,           KC_2,           KC_3,           KC_4,           KC_5
#define ______GAMING_1_L________  KC_Y,           KC_Q,           KC_W,           KC_E,           KC_R
#define ______GAMING_2_L________  KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F
#define ______GAMING_3_L________  DM_PLY2,        KC_Z,           KC_X,           KC_C,           KC_V
#define __GMNG_4_L__                                                              KC_SPC,         DM_PLY1


#define ________HUN_OOUU________  _______,        RALT(KC_9),     RALT(KC_P),     RALT(KC_Y),     RALT(KC_7)

// color definitions
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#define COL_BLACK {HSV_BLACK}
#define COL_NUMBER {HSV_GOLD}
#define COL_OPERATOR {HSV_AZURE}
#define COL_WASD {HSV_MAGENTA}
#define COL_1234 {HSV_CORAL}
#define COL_0MP {HSV_ORANGE}
#define COL_TABS {HSV_TEAL}
#define COL_ESC {HSV_RED}
#define COL_SHIFT {HSV_CYAN}

#define RGB_FAV_DEFAULT RGB_MATRIX_TYPING_HEATMAP
