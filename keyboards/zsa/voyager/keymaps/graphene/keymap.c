#include QMK_KEYBOARD_H
#include "version.h"

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
#define LGCS(kc) (QK_LGUI | QK_LCTL | QK_LSFT | (kc))

#define C_MAGIC QK_AREP

enum layers {
  BASE,
  SHORTCUTS,
  SYM_A,
  SYM_B,
  SYS_NUM,
  HJKL,
};

enum custom_keycodes {
  C_MAG_2 = SAFE_RANGE,
  C_MAG_3,
  MG_ENT,
  MG_MENT,
  MG_ER,
  MG_ES,
  MG_UST,
  MG_ON,
  MG_ION,
  MG_OA,
  MG_SP_BUT,
  MG_THE,
  MG_EFORE,
  MG_HICH,
  MG_MLATIV,
  MG_QUOT_S,
};

enum tap_dance_codes {
  TD_SPC_F19,
  TD_BSP_DEL,
  TD_DEL_HOME,
  TD_CLBR_END,
  TD_DBL_QUOTES,
  TD_SNG_QUOTES,
  TD_NUM_ENT_EQ,
  TD_NUM_0_BSP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    _______,            KC_1,               KC_2,               KC_3,               KC_4,               KC_5,               /**/ KC_6,               KC_7,               KC_8,               KC_9,               KC_0,               _______,
    KC_GRAVE,           KC_B,               MT(MOD_LCTL, KC_L), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_W), KC_Z,               /**/ C_MAGIC,            MT(MOD_RGUI, KC_F), MT(MOD_RALT, KC_O), MT(MOD_RCTL, KC_U), KC_J,               KC_SEMICOLON,
    LT(5, KC_ESCAPE),   LT(4, KC_N),        LT(3, KC_R),        LT(2, KC_T),        LT(1, KC_S),        KC_G,               /**/ KC_Y,               LT(1, KC_H),        LT(2, KC_A),        LT(3, KC_E),        LT(4, KC_I),        KC_ENTER,
    KC_EQUAL,           KC_Q,               KC_X,               KC_M,               KC_C,               KC_V,               /**/ KC_K,               KC_P,               KC_QUOTE,           KC_COMMA,           KC_DOT,             KC_SLASH,
                                                                                    TD(TD_SPC_F19),     MT(MOD_LSFT, KC_TAB),    QK_REP,             TD(TD_BSP_DEL)
  ),
  [SHORTCUTS] = LAYOUT_voyager(
    RGB_TOG,            TOGGLE_LAYER_COLOR, RGB_M_P,            RGB_MOD,            RGB_SPD,            RGB_SPI,            /**/ RGB_HUD,            RGB_HUI,            RGB_VAD,            RGB_VAI,            RGB_SAD,            RGB_SAI,
    KC_BRID,            KC_BRIU,            KC_ESCAPE,          LCS(KC_TAB),        LCTL(KC_TAB),       _______,            /**/ KC_VOLU,            LGUI(KC_C),         KC_UP,              KC_BACKSPACE,       LGUI(KC_V),         _______,
    _______,            LGUI(KC_GRAVE),     TD(TD_DEL_HOME),    TD(TD_CLBR_END),    LGUI(KC_RBRC),      LGCS(KC_4),         /**/ KC_VOLD,            KC_LEFT,            KC_DOWN,            KC_RIGHT,           KC_ENTER,           _______,
    _______,            _______,            KC_PGUP,            KC_PGDN,            CW_TOGG,            _______,            /**/ KC_MUTE,            KC_MPRV,            KC_MPLY,            KC_MNXT,            KC_MSTP,            _______,
                                                                                    _______,            _______,            /**/ _______,            _______
  ),
  [SYM_A] = LAYOUT_voyager(
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            _______,            _______,
    _______,            _______,            KC_AT,              KC_HASH,            KC_DLR,             _______,            /**/ _______,            KC_LABK,            KC_RABK,            KC_CIRCUMFLEX,      _______,            _______,
    _______,            KC_GRAVE,           KC_TILD,            KC_MINUS,           KC_SLASH,           KC_PLUS,            /**/ KC_EQUAL,           KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,   KC_PIPE,            KC_BACKSLASH,       _______,
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            KC_DLR,             LALT(KC_3),         LSA(KC_2),          _______,            _______,
                                                                                    _______,            _______,            /**/ _______,            _______
  ),
  [SYM_B] = LAYOUT_voyager(
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            _______,            _______,
    _______,            _______,            KC_AT,              TD(TD_DBL_QUOTES),  TD(TD_SNG_QUOTES),  _______,            /**/ _______,            KC_LPRN,            KC_RPRN,            KC_SCLN,            _______,            _______,
    _______,            KC_ASTR,            KC_PERC,            KC_EXLM,            KC_DQUO,            _______,            /**/ _______,            KC_LCBR,            KC_RCBR,            KC_AMPR,            KC_COLN,            _______,
    _______,            _______,            _______,            KC_QUES,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            _______,            _______,
                                                                                    _______,            _______,            /**/ _______,            _______
  ),
  [SYS_NUM] = LAYOUT_voyager(
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            _______,            _______,
    _______,            _______,            LCS(KC_LBRC),       LCS(KC_RBRC),       _______,            _______,            /**/ KC_KP_PLUS,         KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_ASTERISK,     KC_CIRC,
    _______,            _______,            LCS(KC_SEMICOLON),  LCS(KC_QUOTE),      LCS(KC_EQUAL),      _______,            /**/ KC_KP_MINUS,        KC_KP_4,            KC_KP_5,            KC_KP_6,            KC_KP_SLASH,        KC_LPRN,
    _______,            _______,            LCS(KC_COMMA),      LCS(KC_DOT),        LCS(KC_MINUS),      _______,            /**/ KC_KP_DOT,          KC_KP_1,            KC_KP_2,            KC_KP_3,            TD(TD_NUM_ENT_EQ),  KC_RPRN,
                                                                                    _______,            _______,            /**/ _______,            TD(TD_NUM_0_BSP)
  ),
  [HJKL] = LAYOUT_voyager(
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            _______,            _______,
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ _______,            _______,            _______,            _______,            KC_P,               _______,
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ KC_H,               KC_J,               KC_K,               KC_L,               KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,
    _______,            _______,            _______,            _______,            _______,            _______,            /**/ KC_N,               _______,            _______,            _______,            _______,            _______,
                                                                                    _______,            _______,            /**/ _______,            _______
  ),
};

const uint16_t PROGMEM combo_LB_IM[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM combo_LB_MR[] = { KC_M, KC_X, COMBO_END};
const uint16_t PROGMEM combo_LB_RP[] = { KC_X, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_LB_IR[] = { KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM combo_RB_IM[] = { KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_RB_MR[] = { KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_RB_RP[] = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_RB_IR[] = { KC_P, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_LB_IM, KC_COLN),
  COMBO(combo_LB_MR, C_MAG_2),
  COMBO(combo_LB_RP, C_MAG_3),
  COMBO(combo_LB_IR, MG_QUOT_S),
  COMBO(combo_RB_IM, KC_SCLN),
  COMBO(combo_RB_MR, C_MAG_2),
  COMBO(combo_RB_RP, C_MAG_3),
  COMBO(combo_RB_IR, MG_QUOT_S),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define BLACK {0, 0, 0}
#define TREE_SAP {23, 226, 208}
#define FELWOOD_LEAVES {79, 218, 204}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
  [SYS_NUM] = {
    BLACK,              BLACK,              BLACK,              BLACK,              BLACK,              BLACK,
    BLACK,              BLACK,              BLACK,              BLACK,              BLACK,              BLACK,
    BLACK,              BLACK,              BLACK,              BLACK,              BLACK,              BLACK,
    BLACK,              BLACK,              BLACK,              BLACK,              BLACK,              BLACK,
                                                                                    BLACK,              BLACK,

    BLACK,              BLACK,              BLACK,              BLACK,              BLACK,              BLACK,
    FELWOOD_LEAVES,     TREE_SAP,           TREE_SAP,           TREE_SAP,           FELWOOD_LEAVES,     FELWOOD_LEAVES,
    FELWOOD_LEAVES,     TREE_SAP,           TREE_SAP,           TREE_SAP,           FELWOOD_LEAVES,     FELWOOD_LEAVES,
    TREE_SAP,           TREE_SAP,           TREE_SAP,           TREE_SAP,           FELWOOD_LEAVES,     FELWOOD_LEAVES,
    BLACK,              TREE_SAP
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
  switch (keycode) {
    case KC_C:
    case KC_P:
    case KC_D:
    case KC_G:
    case KC_Z: return KC_Y;
    case KC_Y: return KC_P;
    case KC_R: return KC_L;
    case KC_K: return KC_S;
    case KC_L:
    case KC_S: return KC_K;
    case KC_U: return KC_E;
    case KC_E: return KC_U;
    case KC_O: return KC_A;
    case KC_A: return KC_O;
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
    case KC_Q: return MG_MLATIV;
    case KC_H: return MG_OA;
    case KC_I: return MG_ON;
    case KC_N: return MG_ION;
    case KC_V: return MG_ER;
    case KC_X: return MG_ES;
    case KC_M: return MG_ENT;
    case KC_T: return MG_MENT;
    case KC_J: return MG_UST;
    case KC_B: return MG_EFORE;
    case KC_W: return MG_HICH;
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
  switch (prev_keycode) {
    case KC_B:
      SEND_STRING("ecome");
      return false;
    case KC_F:
      SEND_STRING("ollow");
      return false;
    case KC_N:
      SEND_STRING("eighbor");
      return false;
    case KC_H:
      SEND_STRING("owever");
      return false;
    case KC_U:
      SEND_STRING("pgrade");
      return false;
    case KC_O:
      SEND_STRING("ther");
      return false;
    case KC_A:
      SEND_STRING("lready");
      return false;
    case KC_P:
      SEND_STRING("sych");
      return false;
    case KC_I:
      SEND_STRING("'ll");
      return false;
    case KC_K:
      SEND_STRING("now");
      return false;
    case KC_T:
      SEND_STRING("hough");
      return false;
    case KC_L:
      SEND_STRING("ittle");
      return false;
    case KC_M:
    case KC_R:
      SEND_STRING("ight");
      return false;
    case KC_J:
      SEND_STRING("udge");
      return false;
    case KC_C:
      SEND_STRING("ould");
      return false;
    case KC_D:
      SEND_STRING("evelop");
      return false;
    case KC_G:
      SEND_STRING("eneral");
      return false;
    case KC_W:
      SEND_STRING("here");
      return false;
    case KC_S:
      SEND_STRING("hould");
      return false;
    case KC_DOT:
      SEND_STRING("org");
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
  switch (prev_keycode) {
    case KC_B:
      SEND_STRING("etween");
      return false;
    case KC_N:
      SEND_STRING("umber");
      return false;
    case KC_U:
      SEND_STRING("pdate");
      return false;
    case KC_A:
      SEND_STRING("bout");
      return false;
    case KC_W:
      SEND_STRING("orld");
      return false;
    case KC_G:
      SEND_STRING("overn");
      return false;
    case KC_P:
      SEND_STRING("rogram");
      return false;
    case KC_Q:
      SEND_STRING("uestion");
      return false;
    case KC_C:
      SEND_STRING("rowd");
      return false;
    case KC_S:
      SEND_STRING("chool");
      return false;
    case KC_T:
      SEND_STRING("hrough");
      return false;
    case KC_M:
      SEND_STRING("anage");
      return false;
    case KC_O:
      SEND_STRING("xygen");
      return false;
    case KC_I:
      SEND_STRING("'m");
      return false;
    case KC_E:
      SEND_STRING("'re");
      return false;
    case KC_DOT:
      SEND_STRING("com");
      return false;
    case KC_COMM:
      SEND_STRING(" since");
      return false;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    int rep_count = get_repeat_key_count();
    if (rep_count < -1 && keycode != MG_UST) {
      send_char('n');
      return false;
    }
    switch (keycode) {
      case C_MAG_2:
        return process_magic_key_2(get_last_keycode(), get_last_mods());
      case C_MAG_3:
        return process_magic_key_3(get_last_keycode(), get_last_mods());
      case MG_ENT:
        SEND_STRING("ent");
        return false;
      case MG_MENT:
        SEND_STRING("ment");
        return false;
      case MG_ER:
        SEND_STRING("er");
        return false;
      case MG_ES:
        SEND_STRING("es");
        return false;
      case MG_UST:
        if (rep_count < -1) {
          SEND_STRING("ment");
        } else {
          SEND_STRING("ust");
        }
        return false;
      case MG_OA:
        SEND_STRING("oa");
        return false;
      case MG_ON:
        SEND_STRING("on");
        return false;
      case MG_ION:
        SEND_STRING("ion");
        return false;
      case MG_SP_BUT:
        SEND_STRING(" but");
        return false;
      case MG_THE:
        SEND_STRING("the");
        return false;
      case MG_EFORE:
        SEND_STRING("efore");
        return false;
      case MG_HICH:
        SEND_STRING("hich");
        return false;
      case MG_MLATIV:
        SEND_STRING("mlativ");
        return false;
      case MG_QUOT_S:
        SEND_STRING("'s");
        return false;
    }

    if (rep_count > 0) {
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
        case KC_N:
          unregister_weak_mods(MOD_MASK_CSAG);
          send_char('f');
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

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

static tap dance_state[8];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_SPACE);
    tap_code16(KC_SPACE);
    tap_code16(KC_SPACE);
  }
  if(state->count > 3) {
    tap_code16(KC_SPACE);
  }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
    case SINGLE_TAP: register_code16(KC_SPACE); break;
    case SINGLE_HOLD: register_code16(KC_F19); break;
    case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
  }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
    case SINGLE_TAP: unregister_code16(KC_SPACE); break;
    case SINGLE_HOLD: unregister_code16(KC_F19); break;
    case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
  }
  dance_state[0].step = 0;
}

void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_BACKSPACE);
    tap_code16(KC_BACKSPACE);
    tap_code16(KC_BACKSPACE);
  }
  if(state->count > 3) {
    tap_code16(KC_BACKSPACE);
  }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
    case SINGLE_TAP: register_code16(KC_BACKSPACE); break;
    case SINGLE_HOLD: register_code16(KC_DELETE); break;
    case DOUBLE_TAP: register_code16(KC_BACKSPACE); register_code16(KC_BACKSPACE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_BACKSPACE); register_code16(KC_BACKSPACE);
  }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[1].step) {
    case SINGLE_TAP: unregister_code16(KC_BACKSPACE); break;
    case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
    case DOUBLE_TAP: unregister_code16(KC_BACKSPACE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_BACKSPACE); break;
  }
  dance_state[1].step = 0;
}

void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
  }
  if(state->count > 3) {
    tap_code16(KC_DELETE);
  }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
    case SINGLE_TAP: register_code16(KC_DELETE); break;
    case SINGLE_HOLD: register_code16(KC_HOME); break;
    case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
  }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[2].step) {
    case SINGLE_TAP: unregister_code16(KC_DELETE); break;
    case SINGLE_HOLD: unregister_code16(KC_HOME); break;
    case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
  }
  dance_state[2].step = 0;
}

void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_LEFT_BRACKET));
    tap_code16(LGUI(KC_LEFT_BRACKET));
    tap_code16(LGUI(KC_LEFT_BRACKET));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_LEFT_BRACKET));
  }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {
    case SINGLE_TAP: register_code16(LGUI(KC_LEFT_BRACKET)); break;
    case SINGLE_HOLD: register_code16(KC_END); break;
    case DOUBLE_TAP: register_code16(LGUI(KC_LEFT_BRACKET)); register_code16(LGUI(KC_LEFT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_LEFT_BRACKET)); register_code16(LGUI(KC_LEFT_BRACKET));
  }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {
    case SINGLE_TAP: unregister_code16(LGUI(KC_LEFT_BRACKET)); break;
    case SINGLE_HOLD: unregister_code16(KC_END); break;
    case DOUBLE_TAP: unregister_code16(LGUI(KC_LEFT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_LEFT_BRACKET)); break;
  }
  dance_state[3].step = 0;
}

void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_RIGHT_BRACKET));
    tap_code16(LALT(KC_RIGHT_BRACKET));
    tap_code16(LALT(KC_RIGHT_BRACKET));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_RIGHT_BRACKET));
  }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
    case SINGLE_TAP: register_code16(LALT(KC_RIGHT_BRACKET)); break;
    case SINGLE_HOLD: register_code16(LALT(LSFT(KC_RIGHT_BRACKET))); break;
    case DOUBLE_TAP: register_code16(LALT(KC_RIGHT_BRACKET)); register_code16(LALT(KC_RIGHT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_RIGHT_BRACKET)); register_code16(LALT(KC_RIGHT_BRACKET));
  }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
    case SINGLE_TAP: unregister_code16(LALT(KC_RIGHT_BRACKET)); break;
    case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_RIGHT_BRACKET))); break;
    case DOUBLE_TAP: unregister_code16(LALT(KC_RIGHT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_RIGHT_BRACKET)); break;
  }
  dance_state[4].step = 0;
}

void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_LEFT_BRACKET));
    tap_code16(LALT(KC_LEFT_BRACKET));
    tap_code16(LALT(KC_LEFT_BRACKET));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_LEFT_BRACKET));
  }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
    case SINGLE_TAP: register_code16(LALT(KC_LEFT_BRACKET)); break;
    case SINGLE_HOLD: register_code16(LALT(LSFT(KC_LEFT_BRACKET))); break;
    case DOUBLE_TAP: register_code16(LALT(KC_LEFT_BRACKET)); register_code16(LALT(KC_LEFT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_LEFT_BRACKET)); register_code16(LALT(KC_LEFT_BRACKET));
  }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
    case SINGLE_TAP: unregister_code16(LALT(KC_LEFT_BRACKET)); break;
    case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_LEFT_BRACKET))); break;
    case DOUBLE_TAP: unregister_code16(LALT(KC_LEFT_BRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_LEFT_BRACKET)); break;
  }
  dance_state[5].step = 0;
}

void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_KP_ENTER);
    tap_code16(KC_KP_ENTER);
    tap_code16(KC_KP_ENTER);
  }
  if(state->count > 3) {
    tap_code16(KC_KP_ENTER);
  }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
    case SINGLE_TAP: register_code16(KC_KP_ENTER); break;
    case SINGLE_HOLD: register_code16(KC_KP_EQUAL); break;
    case DOUBLE_TAP: register_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER);
  }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
    case SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
    case SINGLE_HOLD: unregister_code16(KC_KP_EQUAL); break;
    case DOUBLE_TAP: unregister_code16(KC_KP_ENTER); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
  }
  dance_state[6].step = 0;
}

void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_KP_0);
    tap_code16(KC_KP_0);
    tap_code16(KC_KP_0);
  }
  if(state->count > 3) {
    tap_code16(KC_KP_0);
  }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
    case SINGLE_TAP: register_code16(KC_KP_0); break;
    case SINGLE_HOLD: register_code16(KC_BACKSPACE); break;
    case DOUBLE_TAP: register_code16(KC_KP_0); register_code16(KC_KP_0); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_0); register_code16(KC_KP_0);
  }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
    case SINGLE_TAP: unregister_code16(KC_KP_0); break;
    case SINGLE_HOLD: unregister_code16(KC_BACKSPACE); break;
    case DOUBLE_TAP: unregister_code16(KC_KP_0); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_0); break;
  }
  dance_state[7].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_SPC_F19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
  [TD_BSP_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
  [TD_DEL_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
  [TD_CLBR_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
  [TD_DBL_QUOTES] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
  [TD_SNG_QUOTES] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
  [TD_NUM_ENT_EQ] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
  [TD_NUM_0_BSP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
};
