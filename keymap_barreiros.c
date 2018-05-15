#include "keymap_common.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = { /* Qwerty MAC */
        {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     S(KC_LBRACKET)},
        {KC_BSPC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    M(0),  KC_QUOTE},
        {KC_ENTER,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINUS, KC_LBRACKET},
        {KC_TAB,    KC_LSFT, KC_TRNS, FUNC(3), FUNC(2),    KC_SPC,   KC_SPC,    KC_LGUI,   FUNC(4), KC_TRNS, KC_LALT,  KC_LCTRL}
    },

    [1] = { /* Qwerty WINDOWS */
        {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     S(KC_LBRACKET)},
        {KC_BSPC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    M(0),  KC_QUOTE},
        {KC_ENTER,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINUS, KC_LBRACKET},
        {KC_TAB,    KC_LSFT, KC_TRNS, FUNC(3), FUNC(2),    KC_SPC,   KC_SPC,    KC_LCTRL,   FUNC(4), KC_TRNS, KC_LALT,  KC_LGUI}
    },

    [2] = { /* Qwerty MAC/WINDOWS Custom shift*/
        {KC_ESC, S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),  S(KC_Y),    S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),    S(KC_RBRACKET)},
        {KC_BSPC,   S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),    S(KC_J),    S(KC_K),    S(KC_L),    M(1),  S(KC_QUOTE)},
        {KC_ENTER,  S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),    S(KC_M),    KC_SCOLON, S(KC_SCOLON), S(KC_MINUS), KC_RBRACKET},
        {KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS} 
    },

    [3] = { /* RAISE MAC/WINDOWS */
        {KC_BSLASH, S(KC_3), S(KC_2), LALT(S(KC_2)), S(KC_4), S(KC_5), S(KC_7), KC_SLASH, S(KC_9), S(KC_0), M(3), M(4)},
        {KC_BSPC, LALT(KC_9), KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_TRNS, LALT(S(KC_SLASH)), S(KC_SLASH), LALT(KC_1), S(KC_1), M(5), KC_GRAVE},
        {KC_ENTER, KC_TRNS, KC_KP_DOT, LALT(KC_C), S(KC_6), S(KC_BSLASH), S(KC_COMMA), S(KC_DOT), KC_EQUAL, S(KC_8), S(KC_EQUAL), LALT(KC_L)},
        {KC_LSFT, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  FUNC(1)} 
    },

    [4] = { /* LOWER MAC/WINDOWS */
        {KC_ESC, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12},
        {KC_BSPC, LALT(KC_0), KC_4, KC_5, KC_6, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, S(KC_6)},
        {KC_ENTER, KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6},
        {KC_LSFT, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS} 
    }

};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TOGGLE(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
    [3] = ACTION_LAYER_MOMENTARY(3),
    [4] = ACTION_LAYER_MOMENTARY(4)
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            return MACRODOWN(DOWN(KC_LALT), TYPE(KC_N), UP(KC_LALT), TYPE(KC_N), END);
            break;
        case 1:
            return MACRODOWN(DOWN(KC_LALT), TYPE(KC_N), UP(KC_LALT), DOWN(KC_LSFT), TYPE(KC_N), UP(KC_LSFT), END);
            break;
        case 2:
            return MACRODOWN(DOWN(KC_LALT), TYPE(KC_A), UP(KC_LALT), END);
            break;
        case 3:
            return MACRODOWN(TYPE(KC_QUOTE), TYPE(KC_SPC), END);
            break;
        case 4:
            return MACRODOWN(DOWN(KC_LSFT), TYPE(KC_QUOTE), UP(KC_LSFT), TYPE(KC_SPC), END);
            break;
        case 5:
            return MACRODOWN(DOWN(KC_LSFT), TYPE(KC_GRAVE), UP(KC_LSFT), TYPE(KC_SPC), END);
            break;

    } 
    return MACRO_NONE;
};
