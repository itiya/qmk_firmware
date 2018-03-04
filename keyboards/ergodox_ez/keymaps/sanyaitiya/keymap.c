#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define CLIP 3 // clipstudio layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  #include "0_BasicLayer.h"
  #include "1_SymbolLayer.h"
  #include "2_MediaLayer.h"
  #include "3_ClipStudioLayer.h"
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
    if (record->event.pressed) {
      return MACRO( D(LCTL), T(Z), U(LCTL), END);
    }
    break;
    case 1:
    if (record->event.pressed)
      return MACRO( T(LANG2), END );
    break;
    case 2:
    if (record->event.pressed)
      return MACRO( T(LANG1), END );
    break;
    case 3:
    if (record->event.pressed)
      return MACRO(T(F16), T(LANG2), END);
    break;
    case 4:
    if (record->event.pressed)
      return MACRO(T(F17), T(LANG1), END);
    break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
      ergodox_right_led_3_on();
      break;
    case 2:
      ergodox_right_led_1_on();
      break;
    case 3:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
    }

};
