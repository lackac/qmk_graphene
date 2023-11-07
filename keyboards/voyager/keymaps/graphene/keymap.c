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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_GRAVE,       KC_B,           MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_W),KC_Z,                                           KC_TRANSPARENT, MT(MOD_RGUI, KC_F),MT(MOD_RALT, KC_O),MT(MOD_RCTL, KC_U),KC_J,           KC_SCOLON,
    LT(5,KC_ESCAPE),LT(4,KC_N),     LT(3,KC_R),     LT(2,KC_T),     LT(1,KC_S),     KC_G,                                           KC_Y,           LT(1,KC_H),     LT(2,KC_A),     LT(3,KC_E),     LT(4,KC_I),     KC_ENTER,
    KC_EQUAL,       KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,                                           KC_K,           KC_P,           KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_SLASH,
                                                    TD(DANCE_0),    MT(MOD_LSFT, KC_TAB),                                KC_TRANSPARENT, TD(DANCE_1)
  ),
  [1] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_SLD,        RGB_MOD,        RGB_SPD,        RGB_SPI,                                        RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        RGB_SAD,        RGB_SAI,
    KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_ESCAPE,      LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT,                                 KC_AUDIO_VOL_UP,LGUI(KC_C),     KC_UP,          KC_BSPACE,      LGUI(KC_V),     KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_GRAVE), TD(DANCE_2),    TD(DANCE_3),    LGUI(KC_RBRACKET),LGUI(LCTL(LSFT(KC_4))),                                KC_AUDIO_VOL_DOWN,KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_ENTER,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_PGDOWN,      CAPS_WORD,      KC_TRANSPARENT,                                 KC_AUDIO_MUTE,  KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,          KC_HASH,        KC_DLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_CIRC,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_MINUS,       KC_SLASH,       KC_PLUS,                                        KC_EQUAL,       KC_LBRACKET,    KC_RBRACKET,    KC_PIPE,        KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DLR,         LALT(KC_3),     LALT(LSFT(KC_2)),KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,          TD(DANCE_4),    TD(DANCE_5),    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_SCOLON,      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ASTR,        KC_PERC,        KC_EXLM,        KC_DQUO,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_AMPR,        KC_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUES,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_LBRACKET)),LCTL(LSFT(KC_RBRACKET)),KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_KP_PLUS,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_CIRC,
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_SCOLON)),LCTL(LSFT(KC_QUOTE)),LCTL(LSFT(KC_EQUAL)),KC_TRANSPARENT,                                 KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_LPRN,
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_COMMA)),LCTL(LSFT(KC_DOT)),LCTL(LSFT(KC_MINUS)),KC_TRANSPARENT,                                 KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        TD(DANCE_6),    KC_RPRN,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_7)
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_H,           KC_J,           KC_K,           KC_L,           KC_LBRACKET,    KC_RBRACKET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {79,218,204}, {23,226,208}, {23,226,208}, {23,226,208}, {79,218,204}, {79,218,204}, {79,218,204}, {23,226,208}, {23,226,208}, {23,226,208}, {79,218,204}, {79,218,204}, {23,226,208}, {23,226,208}, {23,226,208}, {23,226,208}, {79,218,204}, {79,218,204}, {0,0,0}, {23,226,208} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
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

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
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


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_SPACE);
    tap_code16(KC_SPACE);
    tap_code16(KC_SPACE);
  }
  if(state->count > 3) {
    tap_code16(KC_SPACE);
  }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
    case SINGLE_TAP: register_code16(KC_SPACE); break;
    case SINGLE_HOLD: register_code16(KC_F19); break;
    case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
  }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
    case SINGLE_TAP: unregister_code16(KC_SPACE); break;
    case SINGLE_HOLD: unregister_code16(KC_F19); break;
    case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
  }
  dance_state[0].step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_BSPACE);
    tap_code16(KC_BSPACE);
    tap_code16(KC_BSPACE);
  }
  if(state->count > 3) {
    tap_code16(KC_BSPACE);
  }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[1].step = dance_step(state);
  switch (dance_state[1].step) {
    case SINGLE_TAP: register_code16(KC_BSPACE); break;
    case SINGLE_HOLD: register_code16(KC_DELETE); break;
    case DOUBLE_TAP: register_code16(KC_BSPACE); register_code16(KC_BSPACE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPACE); register_code16(KC_BSPACE);
  }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[1].step) {
    case SINGLE_TAP: unregister_code16(KC_BSPACE); break;
    case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
    case DOUBLE_TAP: unregister_code16(KC_BSPACE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPACE); break;
  }
  dance_state[1].step = 0;
}

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
    tap_code16(KC_DELETE);
  }
  if(state->count > 3) {
    tap_code16(KC_DELETE);
  }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[2].step = dance_step(state);
  switch (dance_state[2].step) {
    case SINGLE_TAP: register_code16(KC_DELETE); break;
    case SINGLE_HOLD: register_code16(KC_HOME); break;
    case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
  }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[2].step) {
    case SINGLE_TAP: unregister_code16(KC_DELETE); break;
    case SINGLE_HOLD: unregister_code16(KC_HOME); break;
    case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
  }
  dance_state[2].step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LGUI(KC_LBRACKET));
    tap_code16(LGUI(KC_LBRACKET));
    tap_code16(LGUI(KC_LBRACKET));
  }
  if(state->count > 3) {
    tap_code16(LGUI(KC_LBRACKET));
  }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {
    case SINGLE_TAP: register_code16(LGUI(KC_LBRACKET)); break;
    case SINGLE_HOLD: register_code16(KC_END); break;
    case DOUBLE_TAP: register_code16(LGUI(KC_LBRACKET)); register_code16(LGUI(KC_LBRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_LBRACKET)); register_code16(LGUI(KC_LBRACKET));
  }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {
    case SINGLE_TAP: unregister_code16(LGUI(KC_LBRACKET)); break;
    case SINGLE_HOLD: unregister_code16(KC_END); break;
    case DOUBLE_TAP: unregister_code16(LGUI(KC_LBRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_LBRACKET)); break;
  }
  dance_state[3].step = 0;
}

void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_RBRACKET));
    tap_code16(LALT(KC_RBRACKET));
    tap_code16(LALT(KC_RBRACKET));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_RBRACKET));
  }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[4].step = dance_step(state);
  switch (dance_state[4].step) {
    case SINGLE_TAP: register_code16(LALT(KC_RBRACKET)); break;
    case SINGLE_HOLD: register_code16(LALT(LSFT(KC_RBRACKET))); break;
    case DOUBLE_TAP: register_code16(LALT(KC_RBRACKET)); register_code16(LALT(KC_RBRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_RBRACKET)); register_code16(LALT(KC_RBRACKET));
  }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[4].step) {
    case SINGLE_TAP: unregister_code16(LALT(KC_RBRACKET)); break;
    case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_RBRACKET))); break;
    case DOUBLE_TAP: unregister_code16(LALT(KC_RBRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_RBRACKET)); break;
  }
  dance_state[4].step = 0;
}

void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(LALT(KC_LBRACKET));
    tap_code16(LALT(KC_LBRACKET));
    tap_code16(LALT(KC_LBRACKET));
  }
  if(state->count > 3) {
    tap_code16(LALT(KC_LBRACKET));
  }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[5].step = dance_step(state);
  switch (dance_state[5].step) {
    case SINGLE_TAP: register_code16(LALT(KC_LBRACKET)); break;
    case SINGLE_HOLD: register_code16(LALT(LSFT(KC_LBRACKET))); break;
    case DOUBLE_TAP: register_code16(LALT(KC_LBRACKET)); register_code16(LALT(KC_LBRACKET)); break;
    case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_LBRACKET)); register_code16(LALT(KC_LBRACKET));
  }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[5].step) {
    case SINGLE_TAP: unregister_code16(LALT(KC_LBRACKET)); break;
    case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_LBRACKET))); break;
    case DOUBLE_TAP: unregister_code16(LALT(KC_LBRACKET)); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_LBRACKET)); break;
  }
  dance_state[5].step = 0;
}

void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_KP_ENTER);
    tap_code16(KC_KP_ENTER);
    tap_code16(KC_KP_ENTER);
  }
  if(state->count > 3) {
    tap_code16(KC_KP_ENTER);
  }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[6].step = dance_step(state);
  switch (dance_state[6].step) {
    case SINGLE_TAP: register_code16(KC_KP_ENTER); break;
    case SINGLE_HOLD: register_code16(KC_KP_EQUAL); break;
    case DOUBLE_TAP: register_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER);
  }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[6].step) {
    case SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
    case SINGLE_HOLD: unregister_code16(KC_KP_EQUAL); break;
    case DOUBLE_TAP: unregister_code16(KC_KP_ENTER); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
  }
  dance_state[6].step = 0;
}

void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_KP_0);
    tap_code16(KC_KP_0);
    tap_code16(KC_KP_0);
  }
  if(state->count > 3) {
    tap_code16(KC_KP_0);
  }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[7].step = dance_step(state);
  switch (dance_state[7].step) {
    case SINGLE_TAP: register_code16(KC_KP_0); break;
    case SINGLE_HOLD: register_code16(KC_BSPACE); break;
    case DOUBLE_TAP: register_code16(KC_KP_0); register_code16(KC_KP_0); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_0); register_code16(KC_KP_0);
  }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[7].step) {
    case SINGLE_TAP: unregister_code16(KC_KP_0); break;
    case SINGLE_HOLD: unregister_code16(KC_BSPACE); break;
    case DOUBLE_TAP: unregister_code16(KC_KP_0); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_0); break;
  }
  dance_state[7].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
  [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
  [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
  [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
  [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
  [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
};
