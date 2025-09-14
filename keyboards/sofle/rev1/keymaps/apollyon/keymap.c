
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
// #include <stdio.h>

#include QMK_KEYBOARD_H

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______)}
};
#endif

/*
#define INDICATOR_BRIGHTNESS 30
#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
*/

// enum sofle_layers {
//     _BASE = 0,
//     _NAV,
//     _NUM,
//     _GAME
// };

// enum custom_keycodes {
//     KC_BASE = SAFE_RANGE,
//     KC_NAV,
//     KC_NUMP,
//     KC_GAME
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE
    [0] = LAYOUT(
        //,------------------------------------------------.                                          ,---------------------------------------------------.
        QK_GESC,       KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
        //|------+-------+--------+--------+--------+------|                                        |--------+-------+--------+--------+--------+---------|
    LT(2,KC_TAB),KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_MINUS,
        //|------+-------+--------+--------+--------+------|                                        |--------+-------+--------+--------+--------+---------|
        KC_LCTL,       KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //|------+-------+--------+--------+--------+------|  ===  |                        |  ===  |--------+-------+--------+--------+--------+---------|
        KC_LSFT,       KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  C(A(KC_DEL)),               XXXXXXX,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        //|------+-------+--------+--------+--------+------|  ===  |                        |  ===  |--------+-------+--------+--------+--------+---------|
                KC_BSPC, KC_GRAVE, LGUI_T(KC_APP), LT(1, KC_ENT), ALT_T(KC_SPC),          KC_SPC,  LT(1, KC_ENT), RGUI_T(KC_APP), KC_MINUS, KC_DEL
    //                \--------+--------+--------+---------+-------|                        |--------+---------+--------+---------+-------/
    ),

    //NAV
    [1] = LAYOUT(
        //,------------------------------------------------.                                         ,---------------------------------------------------.
        KC_F12,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        //|------+-------+--------+--------+--------+------|                                        |--------+-------+--------+--------+--------+---------|
        KC_GRV,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN,                                        KC_PGUP, KC_HOME, KC_UP,   KC_END, KC_PGDN, KC_EQL,
        //|------+-------+--------+--------+--------+------|                                        |--------+-------+--------+--------+--------+---------|
        _______,C(KC_LEFT),KC_LEFT,KC_DOWN,KC_RIGHT,C(KC_RIGHT),                                     C(KC_LEFT),KC_LEFT,KC_DOWN,KC_RIGHT,C(KC_RIGHT),_______,
        //|------+-------+--------+--------+--------+------|  ===  |                        |  ===  |--------+-------+--------+--------+--------+---------|
            _______,_______,_______,_______,_______,_______,  _______,                         _______,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, _______,
        //|------+-------+--------+--------+--------+------|  ===  |                        |  ===  |--------+-------+--------+--------+--------+---------|
                        DF(3), _______, _______, _______, _______,                          _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|                        |--------+---------+--------+---------+-------/
    ),

    //NUMPAD
    [2] = LAYOUT(
        //,---------------------------------------------------.                                       ,---------------------------------------------------.
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_NUM,  KC_ESC, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
        //|-------+--------+--------+--------+--------+--------|                                     |-------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,                              XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, XXXXXXX,
        //|-------+--------+--------+--------+--------+--------|                                     |--------+-------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                                      XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PENT, KC_PENT,
        //|-------+--------+--------+--------+--------+--------|  ====  |                   |  ====  |--------+-------+--------+--------+--------+--------|
            RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN, XXXXXXX,          XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PENT, KC_PENT,
        //|-------+--------+--------+--------+--------+--------|  ====  |                   |  ====  |--------+-------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,   KC_P0,   KC_P0, KC_PDOT, KC_PENT
        //            \--------+--------+--------+---------+-------|                             |--------+--------+--------+--------+-------/
    ),

    //GAME
    [3] = LAYOUT( 
        //,---------------------------------------------------.                                       ,---------------------------------------------------.
            KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                                      _______, _______, _______, _______, _______, _______,
        //|-------+--------+--------+--------+--------+--------|                                     |-------+--------+--------+--------+--------+--------|
            KC_6,     KC_7,    KC_Q,    KC_W,    KC_E,    KC_R,                                      _______, _______, _______, _______, _______, _______,
        //|-------+--------+--------+--------+--------+--------|                                     |--------+-------+--------+--------+--------+--------|
            KC_8,     KC_9,    KC_A,    KC_S,    KC_D,    KC_F,                                      _______, _______, _______, _______, _______, _______,
        //|-------+--------+--------+--------+--------+--------|  ====  |                   |  ====  |--------+-------+--------+--------+--------+--------|
            KC_0, KC_MINUS,    KC_Z,    KC_X,    KC_C,    KC_V, XXXXXXX,                    _______, _______, _______, _______, _______, _______, _______,
        //|-------+--------+--------+--------+--------+--------|  ====  |                   |  ====  |--------+-------+--------+--------+--------+--------|
                        DF(0), KC_GRV, KC_LALT,KC_LCTL, KC_SPC,                               _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|                             |--------+--------+--------+--------+-------/
    )
};

// #ifdef RGBLIGHT_ENABLE
// char layer_state_str[70];
// // Now define the array of layers. Later layers take precedence

// // QWERTY,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
//   SET_LAYER_ID(HSV_RED)

// );

// // _NUM,
// // Light on outer column and underglow
// const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_TEAL)

// );
// // _SYMBOL,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_BLUE)

//     );
// // _COMMAND,
// // Light on inner column and underglow
// const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
//   SET_LAYER_ID(HSV_PURPLE)
// );

// //_NUMPAD
// const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_INDICATORS(HSV_ORANGE),
//     SET_UNDERGLOW(HSV_ORANGE),
// 	SET_NUMPAD(HSV_BLUE),
//     {7, 4, HSV_ORANGE},
//     {25, 2, HSV_ORANGE},
//     {35+6, 4, HSV_ORANGE},
//     {35+25, 2, HSV_ORANGE}
//     );
// // _SWITCHER   // light up top row
// const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_GREEN),
// 	SET_NUMROW(HSV_GREEN)
// );

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

//     layer_qwerty_lights,
// 	layer_num_lights,// overrides layer 1
// 	layer_symbol_lights,
//     layer_command_lights,
// 	layer_numpad_lights,
// 	layer_switcher_lights  // Overrides other layers
// );

// layer_state_t layer_state_set_user(layer_state_t state) {
// 	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
// 	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
// 	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
// 	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
// 	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
// 	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
//     return state;
// }
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;

// 	rgblight_mode(10);// haven't found a way to set this in a more useful way

// }
// #endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Base "), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Game "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base "), false);
            break;
        case 1:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case 2:
            oled_write_P(PSTR("Num  "), false);
            break;
        case 3:
            oled_write_P(PSTR("Game "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

// #ifdef ENCODER_ENABLE

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLD);
//         } else {
//             tap_code(KC_VOLU);
//         }
//     }
//     return true;
// }
// #endif