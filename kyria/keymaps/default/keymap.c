/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define L(kc) (LSFT(kc))
#define R(kc) (RALT(kc))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_INS,  KC_DEL,  KC_PGDN, KC_PGUP, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                                 KC_NO,   KC_ESC, KC_LALT, KC_LGUI,  KC_SPC,  KC_ENT, MO(_LOWER),KC_BSPC,MO(_RAISE), KC_RALT
    ),
    [_LOWER] = LAYOUT(
      KC_NUBS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
      KC_TRNS, L(KC_1), L(KC_2), L(KC_3), L(KC_4), L(KC_5),                                     L(KC_6), L(KC_7), L(KC_8), L(KC_9), L(KC_0), L(KC_MINS),
      KC_TRNS, KC_GRV,  KC_LCBR, L(KC_EQL),L(KC_RBRC),L(KC_BSLS),R(KC_ASTR),R(KC_8),R(KC_9),R(KC_LPRN),KC_BSLS, KC_RBRC, KC_EQL,  KC_RCBR, KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_RAISE] = LAYOUT(
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_UP,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DOWN, KC_RGHT,
      KC_TRNS, R(KC_GRV),KC_TRNS,KC_TRNS, KC_MUTE, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_ADJUST] = LAYOUT(
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
      KC_TRNS, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS,
      KC_TRNS, KC_TRNS, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_minimon_logo(void) {
  static const char PROGMEM minimon_logo [] = {
					       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 128, 128, 128, 128, 0, 0, 0, 0, 64, 128, 224, 240, 240, 248, 248, 248, 248, 248, 240, 240, 224, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 8, 2, 0, 224, 252, 254, 254, 254, 252, 0, 0, 8, 0, 192, 240, 252, 252, 252, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 4, 248, 252, 252, 252, 248, 240, 192, 1, 0, 0, 0, 255, 255, 255, 255, 255, 252, 240, 193, 0, 7, 31, 63, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 252, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 124, 0, 2, 0, 0, 24, 0, 0, 128, 240, 255, 255, 255, 255, 255, 255, 255, 0, 0, 224, 252, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 15, 255, 255, 255, 255, 255, 255, 254, 248, 192, 0, 255, 255, 255, 255, 127, 63, 127, 255, 255, 249, 226, 192, 36, 0, 240, 249, 249, 249, 251, 251, 253, 253, 253, 252, 248, 248, 248, 252, 252, 252, 252, 252, 252, 252, 252, 253, 255, 231, 15, 15, 255, 255, 255, 255, 255, 251, 241, 0, 0, 240, 8, 0, 0, 224, 252, 255, 255, 255, 31, 7, 255, 255, 255, 255, 248, 255, 255, 255, 31, 255, 255, 255, 255, 255, 252, 254, 255, 255, 63, 31, 15, 15, 15, 31, 255, 255, 255, 254, 252, 0, 0, 0, 8, 128, 196, 194, 192, 192, 128, 192, 224, 240, 240, 240, 248, 248, 240, 240, 192, 0, 0, 0, 0, 15, 0, 0, 0, 0, 255, 255, 255, 255, 248, 1, 7, 31, 127, 255, 255, 255, 255, 255, 225, 0, 0, 3, 15, 63, 127, 255, 0, 0, 15, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 113, 97, 0, 0, 56, 240, 127, 127, 127, 127, 127, 127, 31, 0, 0, 1, 255, 255, 255, 255, 255, 127, 0, 0, 0, 0, 0, 126, 255, 255, 127, 127, 1, 0, 0, 63, 255, 255, 255, 255, 127, 7, 0, 0, 3, 255, 255, 255, 255, 31, 63, 127, 127, 248, 248, 248, 254, 252, 126, 127, 63, 31, 15, 3, 0, 0, 0, 0, 3, 255, 255, 255, 255, 255, 255, 135, 3, 1, 0, 31, 255, 255, 255, 255, 254, 224, 0, 0, 0, 48, 64, 0, 0, 3, 31, 63, 63, 63, 12, 0, 16, 16, 1, 3, 7, 7, 7, 3, 1, 0, 0, 0, 0, 0, 0, 4, 0, 8, 1, 1, 3, 3, 11, 3, 3, 0, 2, 0, 4, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 2, 0, 1, 1, 3, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 3, 4, 0, 0, 1, 7, 7, 3, 2, 4, 8, 16, 0, 32, 32, 0, 0, 32, 0, 0, 16, 8, 4, 4, 0, 8, 0, 16, 3, 63, 63, 63, 63, 31, 8, 0, 1, 0, 2, 0, 7, 7, 7, 7, 3, 0
  };
  oled_write_raw_P(minimon_logo, sizeof(minimon_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyriamann\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
      render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
      render_minimon_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
