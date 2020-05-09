#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( \
		     KC_TAB,  KC_Q,    KC_W,  KC_E,    KC_R, KC_T,    TG(3),                      KC_PGUP, KC_Y,  KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, \
		     KC_LCTL, KC_A,    KC_S,  KC_D,    KC_F, KC_G,    KC_F6,                      KC_PGDN, KC_H,  KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
		     KC_LSFT, KC_Z,    KC_X,  KC_C,    KC_V, KC_B,            KC_INS,    TG(4),            KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), \
		     KC_ESC,  KC_RALT, MO(2), KC_LGUI,       KC_LALT, KC_SPC, KC_DEL,    KC_BSPC, KC_ENT,  MO(1),       KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT),

	[1] = LAYOUT( \
		     KC_NUBS, KC_1,    KC_2,  KC_3,    KC_4,  KC_5,    KC_NO,                        KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
		     KC_TRNS, KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,                        KC_NO,   KC_EQL,  KC_RBRC, KC_BSLS, KC_NO,   KC_NO,   KC_NO, \
		     KC_TRNS, KC_GRV,  KC_NO, KC_NO,   KC_NO, KC_NO,            KC_VOLD,    KC_VOLU,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, \
		     KC_TRNS, KC_LALT, KC_NO, KC_TRNS,        KC_RALT, KC_MPLY, KC_MRWD,    KC_MFFD, KC_MUTE, KC_TRNS,          KC_HOME, KC_PGUP, KC_PGDN, KC_END),

	[2] = LAYOUT( \
		     KC_TAB,  KC_F1,   KC_F2, KC_F3,   KC_F4, KC_F5,   KC_F6,                  KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_NO, \
		     KC_RCTL, KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, \
		     KC_TRNS, KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,          KC_NO,    KC_NO,        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, \
		     KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,        KC_TRNS, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[3] = LAYOUT( \
		     KC_TRNS, KC_NO,   KC_7,    KC_8, KC_9, KC_NO,   TG(3),                     KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, \
		     KC_TRNS, KC_NO,   KC_4,    KC_5, KC_6, KC_NO,   KC_TRNS,                   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, \
		     KC_TRNS, KC_DOT,  KC_1,    KC_2, KC_3, KC_MINS,         KC_DEL,     KC_NO,        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, \
		     KC_TRNS, KC_TRNS, KC_COMM, KC_0,       KC_SPC,  KC_ENT, KC_BSPC,    KC_NO, KC_NO, KC_NO,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[4] = LAYOUT( \
		     KC_TRNS, KC_NO,   KC_UP,   KC_NO,   KC_NO, KC_NO,   KC_TRNS,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,   KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,           KC_ENT,     TG(4),        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
		     KC_TRNS, KC_TRNS, KC_NO,   KC_LGUI,        KC_TRNS, KC_SPC, KC_BSPC,    KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
