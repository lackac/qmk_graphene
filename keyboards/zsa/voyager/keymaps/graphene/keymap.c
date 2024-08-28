#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    KC_GRAVE,       KC_B,           LCTL_T(KC_L),   LALT_T(KC_D),   LGUI_T(KC_W),   KC_Z,           /**/ C_MAGIC,        RGUI_T(KC_F),   RALT_T(KC_O),   RCTL_T(KC_U),   KC_J,           KC_SEMICOLON,
    TO(GAMING),     KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           /**/ KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(SHORTCUTS),
    KC_ESC,         LT(4, KC_N),    LT(3, KC_R),    LT(2, KC_T),    LT(1, KC_S),    KC_G,           /**/ KC_Y,           LT(1, KC_H),    LT(2, KC_A),    LT(3, KC_E),    LT(4, KC_I),    KC_ENTER,
    KC_EQUAL,       KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,           /**/ KC_K,           KC_P,           KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_SLASH,
                                                                    HYPR_T(KC_SPC), LSFT_T(KC_TAB),      RSFT_T(QK_REP), LT(1, KC_BSPC)
  ),
  [SHORTCUTS] = LAYOUT_voyager(
    TO(BASE),       RGB_TOG,        RGB_M_P,        RGB_MOD,        RGB_SPD,        RGB_SPI,        /**/ RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        RGB_SAI,        TO(SYM_A),
    KC_BRIU,        RGB_FAV,        KC_ESCAPE,      _______,        _______,        KC_VOLU,        /**/ LGUI(KC_LBRC),  LCS(KC_TAB),    LCTL(KC_TAB),   LGUI(KC_RBRC),  RGB_SAD,        _______,
    KC_BRID,        LGUI(KC_GRAVE), MEH_T(KC_HOME), C_S_T(KC_PGUP), _______,        KC_VOLD,        /**/ KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ENTER,       _______,
    DB_TOGG,        QK_KB,          KC_END,         KC_PGDN,        CW_TOGG,        KC_MUTE,        /**/ _______,        KC_MPRV,        KC_MPLY,        KC_MNXT,        KC_MSTP,        _______,
                                                                    _______,        _______,        /**/ _______,        _______
  ),
  [SYM_A] = LAYOUT_voyager(
    TO(SHORTCUTS),  _______,        _______,        _______,        _______,        _______,        /**/ _______,        _______,        _______,        _______,        _______,        TO(SYM_B),
    _______,        _______,        KC_AT,          KC_HASH,        KC_PLUS,        _______,        /**/ _______,        KC_LABK,        KC_RABK,        KC_CIRCUMFLEX,  _______,        _______,
    _______,        KC_GRAVE,       KC_TILD,        KC_UNDS,        KC_MINUS,       KC_SLASH,       /**/ KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_PIPE,        KC_BACKSLASH,   _______,
    _______,        _______,        _______,        _______,        KC_ASTR,        _______,        /**/ _______,        KC_DLR,         LALT(KC_3),     LSA(KC_2),      _______,        _______,
                                                                    _______,        _______,        /**/ _______,        _______
  ),
  [SYM_B] = LAYOUT_voyager(
    TO(SYM_A),      _______,        _______,        _______,        _______,        _______,        /**/ _______,        _______,        _______,        _______,        _______,        TO(SYS_NUM),
    _______,        _______,        KC_AT,          LALT(KC_LBRC),  LALT(KC_RBRC),  _______,        /**/ _______,        KC_LPRN,        KC_RPRN,        KC_SCLN,        _______,        _______,
    _______,        KC_ASTR,        KC_PERC,        KC_EXLM,        KC_DQUO,        KC_QUOTE,       /**/ _______,        KC_LBRC,        KC_RBRC,        KC_AMPR,        KC_COLN,        _______,
    _______,        _______,        _______,        KC_QUES,        KC_DLR,         _______,        /**/ _______,        KC_LCBR,        KC_RCBR,        _______,        _______,        _______,
                                                                    _______,        _______,        /**/ _______,        _______
  ),
  [SYS_NUM] = LAYOUT_voyager(
    TO(SYM_B),      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          /**/ KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(GAMING),
    _______,        KC_1,           LCTL_T(KC_2),   LALT_T(KC_3),   LGUI_T(KC_4),   KC_5,           /**/ KC_6,           RGUI_T(KC_7),   RALT_T(KC_8),   RCTL_T(KC_9),   KC_MINUS,       KC_CIRC,
    _______,        LCS(KC_SCLN),   LCS(KC_QUOTE),  LCS(KC_LBRC),   LCS(KC_RBRC),   LCS(KC_MINUS),  /**/ KC_SLASH,       KC_4,           KC_5,           KC_6,           KC_ENTER,       KC_LPRN,
    _______,        LCS(KC_Z),      LCS(KC_COMMA),  LCS(KC_DOT),    LCS(KC_C),      LCS(KC_EQUAL),  /**/ KC_DOT,         KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_RPRN,
                                                                    _______,        _______,        /**/ RSFT_T(KC_0),   _______
  ),
  [GAMING] = LAYOUT_voyager(
    TO(SYS_NUM),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           /**/ _______,        _______,        _______,        _______,        _______,        TO(BASE),
    KC_GRAVE,       KC_Y,           KC_Q,           KC_W,           KC_E,           KC_R,           /**/ _______,        _______,        _______,        _______,        _______,        DM_REC1,
    _______,        KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           /**/ _______,        _______,        _______,        _______,        _______,        DM_REC2,
    KC_LSFT,        DM_PLY2,        KC_Z,           KC_X,           KC_C,           KC_V,           /**/ _______,        _______,        _______,        _______,        _______,        DM_RSTP,
                                                                    KC_SPC,         DM_PLY1,        /**/ _______,        _______
  ),
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t delete_key_override_layered = ko_make_basic(MOD_MASK_SHIFT, LT(1, KC_BSPC), KC_DEL);

const key_override_t *key_overrides[] = {
  &delete_key_override,
  &delete_key_override_layered,
};

const uint16_t PROGMEM combo_LB_IM[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM combo_LB_MR[] = { KC_M, KC_X, COMBO_END};
const uint16_t PROGMEM combo_LB_IR[] = { KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM combo_RB_IM[] = { KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_RB_MR[] = { KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_RB_IR[] = { KC_P, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_LB_IM, KC_COLN),
  COMBO(combo_LB_MR, C_MAG_2),
  COMBO(combo_LB_IR, C_MAG_3),
  COMBO(combo_RB_IM, KC_SCLN),
  COMBO(combo_RB_MR, C_MAG_2),
  COMBO(combo_RB_IR, C_MAG_3),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

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
uint8_t rgb_fav_current = RGB_FAV_DEFAULT;

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

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
      RGB rgb = hsv_to_rgb( hsv );
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case SYS_NUM:
      set_layer_color(SYS_NUM);
      break;
    case GAMING:
      set_layer_color(GAMING);
      break;
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
  }
  return false;
}

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  switch (keycode) {
    // Ignore Custom Magic Keys
    case C_MAG_2:
    case C_MAG_3:
      return false;
    case KC_A ... KC_Z:
      // Forget shift on repeat for letters
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
          *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  // get to the original keycode if it was a tapped key
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode &= 0xFF;
  }

  switch (keycode) {
    case KC_U: return KC_E;
    case KC_E: return KC_U;
    case KC_O: return KC_A;
    case KC_A: return KC_O;

    case KC_S: return KC_Z;
    case KC_R: return KC_L;
    case KC_D: return KC_M;
    case KC_C:
    case KC_G:
    case KC_Z: return KC_S;

    case KC_B: return MG_EFORE;
    case KC_I: return MG_ON;
    case KC_J: return MG_UST;
    case KC_L: return MG_ATION;
    case KC_M: return MG_ENT;
    case KC_N: return MG_ING;
    case KC_Q: return MG_UEST;
    case KC_T: return MG_ION;
    case KC_V: return MG_ER;
    case KC_W: return MG_ITH;
    case KC_X: return MG_PERI;

    case KC_DOT:
      if (mods & MOD_MASK_SHIFT) {
        return KC_EQL;
      } else {
        return KC_BSLS;
      }
    case KC_COMM:
      if (mods & MOD_MASK_SHIFT) {
        return KC_EQL;
      } else {
        return MG_SP_BUT;
      }
    case KC_EQL:
    case KC_MINS: return KC_RABK;

    case KC_SPC:
    case KC_TAB:
    case KC_ENT: return MG_THE;
    case KC_QUOTE:
      if (mods & MOD_MASK_SHIFT) {
        return MG_THE;
      } else {
        return KC_TRNS;
      }
    case KC_1 ... KC_8:
    case KC_0: return KC_DOT;
    case KC_9:
      if (mods & MOD_MASK_SHIFT) {
        return MG_THE;
      } else {
        return KC_DOT;
      }
  }

  return KC_TRNS;
}

bool process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods) {
  // get to the original keycode if it was a tapped key
  if ((prev_keycode >= QK_MOD_TAP && prev_keycode <= QK_MOD_TAP_MAX) || (prev_keycode >= QK_LAYER_TAP && prev_keycode <= QK_LAYER_TAP_MAX)) {
    prev_keycode &= 0xFF;
  }

  switch (prev_keycode) {
    case KC_A:
      SEND_STRING("lready");
      return false;
    case KC_B:
      SEND_STRING("ecome");
      return false;
    case KC_C:
      SEND_STRING("ould");
      return false;
    case KC_D:
      SEND_STRING("evelop");
      return false;
    case KC_F:
      SEND_STRING("ollow");
      return false;
    case KC_G:
      SEND_STRING("eneral");
      return false;
    case KC_H:
      SEND_STRING("owever");
      return false;
    case KC_I:
      SEND_STRING("'ll");
      return false;
    case KC_J:
      SEND_STRING("udge");
      return false;
    case KC_K:
      SEND_STRING("now");
      return false;
    case KC_L:
      SEND_STRING("ittle");
      return false;
    case KC_M:
      SEND_STRING("ight");
      return false;
    case KC_N:
      SEND_STRING("eighbor");
      return false;
    case KC_O:
      SEND_STRING("ther");
      return false;
    case KC_P:
      SEND_STRING("rogram");
      return false;
    case KC_Q:
      SEND_STRING("uery");
      return false;
    case KC_R:
      SEND_STRING("ight");
      return false;
    case KC_S:
      SEND_STRING("hould");
      return false;
    case KC_T:
      SEND_STRING("hough");
      return false;
    case KC_U:
      SEND_STRING("pgrade");
      return false;
    case KC_V:
      SEND_STRING("alue");
      return false;
    case KC_W:
      SEND_STRING("here");
      return false;
    case KC_X:
      SEND_STRING("ception");
      return false;
    case KC_DOT:
      SEND_STRING("com");
      return false;
    case KC_COMM:
      SEND_STRING(" however");
      return false;
    default:
      SEND_STRING("'ll");
      return false;
  }
}

bool process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods) {
  // get to the original keycode if it was a tapped key
  if ((prev_keycode >= QK_MOD_TAP && prev_keycode <= QK_MOD_TAP_MAX) || (prev_keycode >= QK_LAYER_TAP && prev_keycode <= QK_LAYER_TAP_MAX)) {
    prev_keycode &= 0xFF;
  }

  switch (prev_keycode) {
    case KC_A:
      SEND_STRING("bout");
      return false;
    case KC_B:
      SEND_STRING("etween");
      return false;
    case KC_C:
      SEND_STRING("rowd");
      return false;
    case KC_D:
      SEND_STRING("efault");
      return false;
    case KC_E:
      SEND_STRING("'re");
      return false;
    case KC_F:
      SEND_STRING("unction");
      return false;
    case KC_G:
      SEND_STRING("overn");
      return false;
    case KC_H:
      SEND_STRING("ttps");
      return false;
    case KC_I:
      SEND_STRING("'m");
      return false;
    case KC_J:
      SEND_STRING("ourney");
      return false;
    case KC_L:
      SEND_STRING("ength");
      return false;
    case KC_K:
      SEND_STRING("eyword");
      return false;
    case KC_M:
      SEND_STRING("anage");
      return false;
    case KC_N:
      SEND_STRING("umber");
      return false;
    case KC_O:
      SEND_STRING("bject");
      return false;
    case KC_P:
      SEND_STRING("roject");
      return false;
    case KC_Q:
      SEND_STRING("uarter");
      return false;
    case KC_R:
      SEND_STRING("eturn");
      return false;
    case KC_S:
      SEND_STRING("ubject");
      return false;
    case KC_T:
      SEND_STRING("hrough");
      return false;
    case KC_U:
      SEND_STRING("pdate");
      return false;
    case KC_V:
      SEND_STRING("ersion");
      return false;
    case KC_W:
      SEND_STRING("orld");
      return false;
    case KC_X:
      SEND_STRING("ample");
      return false;
    case KC_DOT:
      SEND_STRING("org");
      return false;
    case KC_COMM:
      SEND_STRING(" since");
      return false;
    default:
      return false;
  }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  switch (keycode) {
    case RSFT_T(QK_REP):
    case C_MAG_2:
    case C_MAG_3:
      return false;
      break;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  // turn RSFT_T(QK_REP) into QK_REP if it's just tapped
  if (keycode == RSFT_T(QK_REP) && record->tap.count) {
    return process_repeat_key(QK_REP, record);
  }

  if (record->event.pressed) {
    int rep_count = get_repeat_key_count();
    if (rep_count < -1 && keycode != MG_UST) {
      send_char('n');
      return false;
    }

    switch (keycode) {
      case RGB_FAV:
        if (get_mods() & MOD_MASK_CTRL) {
          rgb_fav_current = rgb_matrix_get_mode();
        } else {
          rgb_matrix_mode((get_mods() & MOD_MASK_SHIFT) ? RGB_FAV_DEFAULT : rgb_fav_current);
        }
        return false;

      case C_MAG_2:
        return process_magic_key_2(get_last_keycode(), get_last_mods());
      case C_MAG_3:
        return process_magic_key_3(get_last_keycode(), get_last_mods());

      case MG_ATION:
        SEND_STRING("ation");
        return false;
      case MG_EFORE:
        SEND_STRING("efore");
        return false;
      case MG_ENT:
        SEND_STRING("ent");
        return false;
      case MG_ER:
        SEND_STRING("er");
        return false;
      case MG_ING:
        SEND_STRING("ing");
        return false;
      case MG_ION:
        SEND_STRING("ion");
        return false;
      case MG_ITH:
        SEND_STRING("ith");
        return false;
      case MG_ON:
        SEND_STRING("on");
        return false;
      case MG_PERI:
        SEND_STRING("peri");
        return false;
      case MG_SP_BUT:
        SEND_STRING(" but");
        return false;
      case MG_THE:
        SEND_STRING("the");
        return false;
      case MG_UEST:
        SEND_STRING("uest");
        return false;
      case MG_UST:
        if (rep_count < -1) {
          SEND_STRING("ment");
        } else {
          SEND_STRING("ust");
        }
        return false;
    }

    if (rep_count > 0) {
      // get to the original keycode if it was a tapped key
      if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode &= 0xFF;
      }

      switch (keycode) {
        case KC_BSPC:
        case KC_DQUO:
        case KC_LPRN:
        case KC_SPC:
        case KC_ENT:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("for");
          return false;
        case KC_I:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("ng");
          return false;
        case KC_DOT:
        case KC_QUES:
        case KC_EXLM:
        case KC_COLN:
        case KC_SCLN:
          unregister_weak_mods(MOD_MASK_CSAG);
          send_char(' ');
          add_oneshot_mods(MOD_MASK_SHIFT);
          set_last_keycode(KC_SPC);
          return false;
        case KC_COMM:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING(" and");
          return false;
        case KC_A:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("nd");
          return false;
        case KC_B:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("ecause");
          return false;
        case KC_W:
          unregister_weak_mods(MOD_MASK_CSAG);
          SEND_STRING("ould");
          return false;
        case KC_Y:
          unregister_weak_mods(MOD_MASK_CSAG);
          if (rep_count > 2) {
            SEND_STRING("ll");
            return false;
          }
          if (rep_count > 1) {
            send_char('\'');
            return false;
          }
          SEND_STRING("ou");
          return false;
      }
    }
  }
  return true;
}
