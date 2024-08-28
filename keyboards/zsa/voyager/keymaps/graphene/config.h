/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"vr7YO/LK3eA"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 8

#define DYNAMIC_MACRO_DELAY 100

#define RGB_MATRIX_STARTUP_SPD 60

