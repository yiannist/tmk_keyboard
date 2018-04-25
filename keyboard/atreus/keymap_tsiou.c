#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters
  *
  *  q    w      e      r     t         ||        y    u    i   o     p
  *  a    s      d      f     g         ||        h    j    k   l     ç
  *  z    x      c      v     b         ||        n    m    ,   .     ;
  * esc  caps  super  shift  bksp  ctrl || alt  space  fn   ´   ~   enter
  */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,    \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_CAPS, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT,           \
           KC_LCTL, KC_SPC, KC_FN0, KC_LBRC, KC_QUOT, KC_ENT),          \
  /* 1: punctuation and numbers
   *
   *  /   ?     up      {     }        ||      pgup    7    8   9   *
   *  @  left  down   right   $        ||      pgdn    4    5   6   +
   *  [   ]     (       )     &        ||        '     1    2   3   \
   * L2  tab   super  shift  del  ctrl || alt  space   fn   -   0   =
   */
  KEYMAP(KC_FN4, KC_FN5, KC_UP, SHIFT(KC_RBRC), SHIFT(KC_BSLS),         \
           KC_PGUP, KC_7, KC_8, KC_9, SHIFT(KC_8),                      \
         SHIFT(KC_2), KC_LEFT, KC_DOWN, KC_RIGHT, SHIFT(KC_4),          \
           KC_PGDN, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),                  \
         KC_RBRC, KC_BSLS, SHIFT(KC_9), SHIFT(KC_0), SHIFT(KC_7),       \
           KC_GRAVE, KC_1, KC_2, KC_3, KC_NUBS,                         \
         KC_FN1, KC_TAB, KC_LGUI, KC_LSFT, KC_DEL, KC_LALT,             \
           KC_LCTL, KC_SPC, KC_FN0, KC_MINS, KC_0, KC_EQUAL),           \
  /* 2: arrows and function keys
   *
   *       home    up    end              ||       up    F7   F8   F9   F10
   *       left   down   right            ||      down   F4   F5   F6   F11
   *  del   e      4      c    reset      ||             F1   F2   F3   F12
   *  esc  ins   super  shift  bksp  ctrl || alt  space  L0  ralt
   */
  KEYMAP(KC_NO, KC_HOME, KC_UP, KC_END, KC_NO,                        \
           KC_UP, KC_F7, KC_F8, KC_F9, KC_F10,                        \
         KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,                    \
           KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,                      \
         KC_DEL, KC_E, KC_4, KC_C, KC_FN3,                            \
           KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                        \
         KC_ESC, KC_INS, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT,          \
           KC_LCTL, KC_SPC, KC_FN2, KC_RALT, KC_NO, KC_NO)
};

enum macro_id {
  PB_SLSH,
  PB_QMARK,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MACRO(PB_SLSH), // write "/" in L1
  [5] = ACTION_MACRO(PB_QMARK) // write "?" in L1
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case PB_SLSH:
      return (record->event.pressed ?
              MACRO( D(RALT), T(Q), U(RALT), END ) :
              MACRO_NONE);
    case PB_QMARK:
      return (record->event.pressed ?
              MACRO( D(RALT), T(W), U(RALT), END ) :
              MACRO_NONE);
  }
}
