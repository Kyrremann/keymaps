/* Copyright 2020 illness072
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

#define KC_VU KC__VOLUP
#define KC_VD KC__VOLDOWN
#define KC_MU KC__MUTE
#define KC_FNL MO(_LOWER)
#define KC_FNR MO(_RAISE)
#define KC_LST LSFT_T(KC_TAB)
#define KC_RSQ RSFT_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_LST , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_RSQ ,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
              KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                                      KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     KC_LALT,KC_LCMD,KC_SPC ,KC_FNR ,     KC_DEL ,KC_BSPC,KC_ENT , KC_FNL
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_TILD,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_LCTL,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                                     KC_CIRC,KC_AMPR,KC_ASTR,KC_MINS,KC_PLUS,KC_GRV ,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
             XXXXXXX,KC_BSLS,KC_LCBR,KC_LBRC,KC_LPRN,                                     KC_RPRN,KC_RBRC,KC_RCBR,KC_UNDS,KC_EQL ,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     KC_LALT,KC_LCMD,KC_SPC ,KC_LSFT,     KC_DEL ,KC_SPC ,KC_ENT ,KC_BSPC
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                                      KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_LCTL, KC_VD , KC_VU , KC_MU ,RGB_HUI,RGB_VAI,                                     KC_PGUP,KC_HOME, KC_UP ,KC_END ,XXXXXXX,KC_F12 ,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             KC_BRMD,KC_BRMU,RGB_TOG,RGB_MOD,RGB_VAD,                                     KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     KC_LALT,KC_LCMD,KC_SPC ,KC_LSFT,     KC_DEL ,KC_SPC ,KC_ENT ,KC_BSPC
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE

const char *read_logo(void) {
  static char logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  return logo;
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Lower\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("Raise\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif
