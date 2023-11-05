// Copyright 2023 Dariusz Luksza
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

// "??????" layer when hold, KC_ESC when tapped
#define SLSH_NUM LT(_NUM, KC_SLSH)
// "??????" layer when hold, KC_ENT when tapped
#define ESC_SYM LT(_SYM, KC_ESC)
// navigation layer when hold, KC_SPC when tapped
#define SPC_NAV LT(_NAV, KC_SPC)
// shift when hold, KC_A when tapped
#define A_SFT LSFT_T(KC_A)
// shift when hold, KC_SCLN when tapped
#define SCLN_SFT LSFT_T(KC_SCLN)
// "(" on press, ")" with SFT
#define PAREN KC_LPRN
// "[" on press, "]" with SFT
#define BRCKE KC_LBRC
// "{" on press, "}" wiht SFT
#define CRBRC KC_LCBR
// Browser back
#define BBACK LGUI(KC_LBRC)
// Browser forward
#define BFORW LGUI(KC_RBRC)
// Previous tab
#define TPREV SGUI(KC_LBRC)
// Next tab
#define TNEXT SGUI(KC_RBRC)
// TAB when tapped, OPT+GUI when held
#define MOD_TAB LAG_T(KC_TAB)

enum layer_names {
    _QW,
    _NUM,
    _SYM,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*                            QWERTY
      * ┌───────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬─────┬───┐
      * │  (|)  │ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │  P  │[|]│
      * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼─────┼───┤
      * │   `   │ A │ S │ D │ F │ G │           │ H │ J │ K │ L │  ;  │ ' │
      * ├───────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼─────┼───┤
      * │Tab|MEH│ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │/|NUM│Ent│
      * └───────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴─────┴───┘
      *               ┌───┐                         ┌───┐
      *               │GUI├───┐               ┌─────┤Alt│
      *               └───┤Bsp├───────┐   ┌───┤ |NAV├───┘
      *                   └───┤Esc|SYM│   │Ctl├─────┘
      *                       └───────┘   └───┘
      */
    [_QW] = LAYOUT_split_3x6_3(
           PAREN,    KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,                         KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,      BRCKE,
           KC_GRV,   A_SFT,  KC_S,  KC_D,  KC_F,  KC_G,                         KC_H,  KC_J,  KC_K,     KC_L,    SCLN_SFT,  KC_QUOT,
           MOD_TAB,  KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,                         KC_N,  KC_M,  KC_COMM,  KC_DOT,  SLSH_NUM,  KC_ENT,
                                KC_LGUI,  KC_BSPC,  ESC_SYM,      KC_LCTL,  SPC_NAV,  KC_RALT
    ),
     /*                        NUMBERS (/)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │ _ │7|#│8|*│9|(│ \ │{|}│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ = │4|$│5|%│6|^│ | │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │ - │1|!│2|@│3|#│ ⇓ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤0|)│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NUM] = LAYOUT_split_3x6_3( // numbers
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    LSFT(KC_MINS),  KC_7,    KC_8,  KC_9,  KC_BSLS,        CRBRC,
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PEQL,        KC_4,    KC_5,  KC_6,  LSFT(KC_BSLS),  KC_TRNS,
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MINS,        KC_1,    KC_2,  KC_3,  KC_TRNS,        KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_0
    ),
     /*                        SYMBOLS (Esc)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬────┬────┬────┬───┬───┐
      * │   │   │   │   │   │   │       │   │ F7 │ F8 │ F9 │F10│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼────┼────┼────┼───┼───┤
      * │   │   │   │   │   │   │       │   │ F4 │ F5 │ F6 │F11│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼────┼────┼────┼───┼───┤
      * │   │   │   │   │   │   │       │   │ F1 │ F2 │ F3 │F12│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴────┴────┴────┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤ ⇓ │   │   ├───┘
      *                       └───┘   └───┘
      */    [_SYM] = LAYOUT_split_3x6_3( // special keys like F1, F2 etc.
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F7,    KC_F8,  KC_F9,  KC_F10,  KC_TRNS,
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F4,    KC_F5,  KC_F6,  KC_F11,  KC_TRNS,
           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F1,    KC_F2,  KC_F3,  KC_F12,  KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),
     /*                       NAVIGATION ( )
      * ┌───┬───┬───┬───┬───┬───┐       ┌────┬───┬────┬────┬────┬────┐
      * │   │   │   │   │   │   │       │PgUP│HOM│    │    │PTab│NTab│
      * ├───┼───┼───┼───┼───┼───┤       ├────┼───┼────┼────┼────┼────┤
      * │   │   │   │   │   │   │       │ <- │DOW│ Up │ -> │Back│Forw│
      * ├───┼───┼───┼───┼───┼───┤       ├────┼───┼────┼────┼────┼────┤
      * │   │   │   │   │   │   │       │PgDw│End│    │    │    │ =  │
      * └───┴───┴───┴───┴───┴───┘       └────┴───┴────┴────┴────┴────┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤ ⇓ ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */    [_NAV] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PGUP,    KC_HOME,    KC_END,   KC_TRNS,   TPREV,    TNEXT,
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,  BBACK,    BFORW,
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PGDN,    KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_PEQL,
                                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    )
};

const key_override_t right_parentacy = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t right_bracket = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t right_curly_brace = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);

const key_override_t **key_overrides = (const key_override_t *[]){
    &right_parentacy,
    &right_bracket,
    &right_curly_brace,
    NULL, // Null terminate the array of overrides!
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_SFT:
            return TAPPING_TERM + 45;
        default:
            return TAPPING_TERM;
    }
};


     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

