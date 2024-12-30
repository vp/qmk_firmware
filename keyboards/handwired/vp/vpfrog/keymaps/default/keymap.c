// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT_1,
    _DEFAULT_2,
    _DEFAULT_3,
    _NUMBER_1,
    _NUMBER_2
};

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define SFTLLCK LSFT_T(KC_0)
#define LGUILLCK LGUI_T(KC_0)
#define LT_DEFAULT_3 LT(_DEFAULT_3, KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT_1] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_Z, KC_X, KC_C, KC_V, KC_B,
        LT(_DEFAULT_2,KC_SPC), LT_DEFAULT_3, KC_NO, SC_SENT, LGUILLCK
    ),
    [_DEFAULT_2] = LAYOUT(
        KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_DEFAULT_3] = LAYOUT(
        KC_ESC, KC_HOME, KC_END, KC_PAUS, KC_PGUP,
        KC_INS, KC_LSFT, KC_LALT, KC_UP, KC_PGDN,
        KC_DEL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NUMBER_1] = LAYOUT(
        KC_PDOT, KC_7, KC_8, KC_9, KC_PPLS,
        KC_PSLS, KC_4, KC_5, KC_6, KC_PAST,
        KC_0, KC_1, KC_2, KC_3, KC_PMNS,
        LT(_NUMBER_2,KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
    [_NUMBER_2] = LAYOUT(
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_PMNS,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_F12,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PEQL,
        KC_TRNS, KC_TRNS, KC_PCMM, KC_PDOT, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTLLCK:
            if (record->tap.count) {
                if (record->event.pressed) {
                    // Toggle the lock on the highest layer.
                   // layer_lock_invert(get_highest_layer(layer_state));
                }
                return false;
            }
            break;
        case LGUILLCK:
            if (record->tap.count) {
                if (record->event.pressed) {
                    // Toggle the lock on the highest layer.
                  layer_lock_invert(get_highest_layer(layer_state));
                }
                return false;
            }
            break;

        case LT_DEFAULT_3:
            if (record->tap.count) {
                if (record->event.pressed) {
                   layer_invert(_NUMBER_1);
                }
                return false;
            }
            break;
    }

    return true;
}
