#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, // USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              // USB Toggle Automatic GCR control
    DBG_TOG,               // DEBUG Toggle On / Off
    DBG_MTRX,              // DEBUG Toggle Matrix Prints
    DBG_KBD,               // DEBUG Toggle Keyboard Prints
    DBG_MOU,               // DEBUG Toggle Mouse Prints
    MD_BOOT,               // Restart into bootloader after hold timeout

    UC_SHRG,               // shrug - ¯\_(ツ)_/¯ - only works with "unicode keyboard" mode
    MAS_TOG,               // toggle LED mode
};

// RGB: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix
// --------------------------------------------------------------------------------------
// RGB_TOG:  Toggle RGB lighting on or off
// RGB_MOD:  Cycle through modes, reverse direction when Shift is held
// RGB_RMOD: Cycle through modes in reverse, forward direction when Shift is held
// RGB_HUI:  Increase hue, decrease hue when Shift is held
// RGB_HUD:  Decrease hue, increase hue when Shift is held
// RGB_SAI:  Increase saturation, decrease saturation when Shift is held
// RGB_SAD:  Decrease saturation, increase saturation when Shift is held
// RGB_VAI:  Increase value (brightness), decrease value when Shift is held
// RGB_VAD:  Decrease value (brightness), increase value when Shift is held
// RGB_SPI:  Increase effect speed (does not support eeprom yet), decrease speed when Shift is held
// RGB_SPD:  Decrease effect speed (does not support eeprom yet), increase speed when Shift is held

#define KC_CTCP MT(MOD_LCTL, KC_CAPS) // MOD-TAP - CTRL / CAPS_LOCK
#define TG_NKRO MAGIC_TOGGLE_NKRO     // Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, KC_RALT, MO(1),   KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT( // TODO: H for HUE, S for Saturation, V for Value; +/=, - for speed
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, \
        MAS_TOG, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, MO(2),   _______, _______,            _______, _______, _______ \
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, UC_SHRG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

// These are just to make it neater to use builtin HSV values in the keymap
#define BLUE {HSV_BLUE}
#define CORAL {HSV_CORAL}
#define CYAN {HSV_CYAN}
#define GOLDEN {HSV_GOLDENROD}
#define GREEN {HSV_GREEN}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}
#define PURPLE {HSV_PURPLE}
#define RED {HSV_RED}
#define TURQ {HSV_TURQUOISE}
#define WHITE {HSV_WHITE}
#define YELLOW {HSV_YELLOW}

#ifdef _______
#undef _______
#define _______ {0, 0, 0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    },
    [1] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            CYAN,    _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   CYAN,    CYAN,    CYAN,    \
        _______, YELLOW,  TURQ,    MAGENT,  PINK,    GREEN,   _______, _______, _______, _______, _______, _______, _______, _______,   CYAN,    CYAN,    CYAN,    \
        _______, YELLOW,  TURQ,    MAGENT,  PINK,    GREEN,   _______, _______, _______, _______, _______, _______, _______, \
        WHITE,   WHITE,   _______, _______, _______, RED,     GOLDEN,  _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, PURPLE,  _______, _______,            _______, _______, _______ \
    },
    [2] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, YELLOW,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    },
};

const uint8_t PROGMEM underglow[][3] = {
    _______,
    TURQ,
    CORAL,
};

// This indicates that we're processing the layer state change.  It is referenced in
// rgb_matrix_indicators_user loop to prevent messing with LEDs while we're forcing
// an rgb_matrix_mode re-initialization.
static uint8_t rgb_state_change_active = 0;

#undef _______
#define _______ KC_TRNS
#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behavior.
  debug_enable   = true;
  debug_keyboard = true;
  debug_matrix   = true;
  debug_mouse    = true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT   (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case UC_SHRG: // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            }
            return false;
        case MAS_TOG:
            if (record->event.pressed) {
                rgb_state_change_active = 1;
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL:
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                        rgb_matrix_set_color_all(0, 0, 0);
                        break;
                    case LED_FLAG_MODIFIER | LED_FLAG_KEYLIGHT:
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                        rgb_matrix_set_color_all(0, 0, 0);
                        break;
                    case LED_FLAG_KEYLIGHT:
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                        break;
                    case LED_FLAG_UNDERGLOW:
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                        break;
                    default:
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                        break;
                }
            }
            return false;
        case RGB_TOG ... RGB_MODE_RGBTEST:
            rgb_state_change_active = 1;
            return true;

        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static layer_state_t last_layer_state;

    if (get_highest_layer(state) == 0 && get_highest_layer(last_layer_state) != 0 && rgb_matrix_config.enable != 0) {
        rgb_state_change_active = 1;

        // This is a hack to force the RGB matrix to re-initialize animations when
        // switching back to the base layer. If this isn't done, modifications made
        // in rgb_matrix_indicators_user persist after the layer is restored.
        // For animations (like rain) that rely on randomized locations for color changes,
        // it looks very odd.
        //
        // As for the loop...  Mode initialization only occurs when the mode has changed or
        // the matrix has been enabled/disabled and these state changes are only recorded when
        // the mode is "flushed". The flush code only runs when the mode is completely rendered
        // which requires us to go through STARTING and RENDERING states. Getting through the
        // RENDERING phase takes multiple iterations where RGB_MATRIX_LED_PROCESS_LIMIT LEDs
        // are changed per iteration.
        rgb_matrix_disable_noeeprom();
        for (int i = 0; i < DRIVER_LED_TOTAL / RGB_MATRIX_LED_PROCESS_LIMIT + 3; i++) {
            rgb_matrix_task();
        }
        rgb_matrix_enable_noeeprom();
        rgb_state_change_active = 0;

        uprintf("rgb_matrix_config - mode: %d, speed: %d, hue: %d, sat: %d, val: %d\n",
                rgb_matrix_config.mode, rgb_matrix_config.speed,
                rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
    }

    last_layer_state = state;
    return state;
}

#ifdef RGB_MATRIX_ENABLE
extern bool g_suspend_state;
#endif

void rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer == 0 || g_suspend_state || !rgb_matrix_config.enable) {
        return;
    }

    // Escape key should show current color and intensity
    if (rgb_state_change_active) {
        RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
       
        // F1-F8 show the binary encoding of the mode
        for (int i = 1; i <= 8; i++) {
            RGB color = rgb_matrix_get_mode() & 1 << (8 - i) ? rgb : (RGB){0, 0, 0};
            rgb_matrix_set_color(i, color.r, color.g, color.b);
        }
        return;
    }

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        // Read from the LED map
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        // Override with UNDERGLOW
        if HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) {
            hsv.h = pgm_read_byte(&underglow[layer][0]);
            hsv.s = pgm_read_byte(&underglow[layer][1]);
            hsv.v = pgm_read_byte(&underglow[layer][2]);
        }
        // Use configured intensity value
        if (hsv.v) {
            hsv.v = rgb_matrix_config.hsv.v;
        }
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

void suspend_power_down_user(void) {
    uprintf("!!MJS: suspend_power_down_user\n");
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    uprintf("!!MJS: suspend_wakeup_init_user\n");
    rgb_matrix_set_suspend_state(false);
}
