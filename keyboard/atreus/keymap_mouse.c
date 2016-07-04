#include "keymap_common.h"

/* The default Atreus layout, plus a layer for mouse keys. First layer
   is normal keys, second (momentary fn layer) is numbers, most
   punctuation, and arrows. Third (modal, persistent) layer is
   function keys and other rarely-used keys. Fourth (modal,
   persistent) layer is mouse actions. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,     \
         KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER,                                     \
  /* 2: arrows and function keys, reached by fn+esc, leave by pressing fn */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END,                                  KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT,                              KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         // mouse layer                   bootloader
         KC_FN4, KC__VOLUP, KC_NO, KC_NO, KC_FN3,                         KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         //                                                                       back layer
         KC_NO, KC__VOLDOWN, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, KC_FN2, KC_PSCREEN, KC_SLCK, KC_PAUSE), \
  /* 3: mouse control, reached by fn+esc, then z, leave by pressing fn */
  KEYMAP( /* 3: mouse */
         //       acceleration settings                                   buttons: 4   left   middle   right    5
         KC_NO,   KC_FN19, KC_FN20, KC_FN21, KC_NO,                       KC_FN17,   KC_FN14, KC_FN16, KC_FN15, KC_FN18, \
         //              mouse wheel                                        movement: left    up/down  right
         KC_NO,   KC_FN12, KC_FN10, KC_FN13, KC_NO,                       KC_NO,     KC_FN8,  KC_FN6,  KC_FN9, KC_NO,   \
         KC_NO,   KC_NO,   KC_FN11, KC_NO,   KC_NO,                       KC_NO,     KC_NO,   KC_FN7,  KC_NO,   KC_NO,   \
         //                                                                        back layer
         KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS,   KC_NO,     KC_FN5,  KC_NO,   KC_NO,   KC_NO  \
          )
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER), // reset for uploading new code
  [4] = ACTION_LAYER_ON(3, 1),  // switch to layer 2
  [5] = ACTION_LAYER_OFF(3, 1),  // switch back to layer 0

  [6] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [7] = ACTION_MOUSEKEY(KC_MS_D),
  [8] = ACTION_MOUSEKEY(KC_MS_L),
  [9] = ACTION_MOUSEKEY(KC_MS_R),
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_WH_D),
  [12] = ACTION_MOUSEKEY(KC_WH_L),
  [13] = ACTION_MOUSEKEY(KC_WH_R),
  [14] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [15] = ACTION_MOUSEKEY(KC_BTN2),
  [16] = ACTION_MOUSEKEY(KC_BTN3),
  [17] = ACTION_MOUSEKEY(KC_BTN4),
  [18] = ACTION_MOUSEKEY(KC_BTN5),
  [19] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [20] = ACTION_MOUSEKEY(KC_ACL1),
  [21] = ACTION_MOUSEKEY(KC_ACL2),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
