// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAKDH,
    _SYMBOL,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAKDH,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_ALTTB,
    KC_ALTSTB,
};

    // enum combos {
    //     TWO_CTL_META,
    // };

    // const uint16_t PROGMEM two_ctl_combo[] = {KC_LCTL, KC_RCTL, COMBO_END};

    // combo_t key_combos[] = {
    //     [TWO_CTL_META] = COMBO(two_ctl_combo, KC_LGUI),
    // };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/SYM|  A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |'/SYM |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI |LAlt  |TAB/LCtr|Space|/LOWER  /       \RAISE \  |Bspc  |Ent/RCtr|RAlt| RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  MO(_ADJUST),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  LT(_SYMBOL, KC_ESC),KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  LT(_SYMBOL, KC_QUOT),
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI,KC_LALT,MT(MOD_LCTL, KC_TAB),KC_SPC, MO(_LOWER),          MO(_RAISE), KC_BSPC, MT(MOD_RCTL, KC_ENT), KC_RALT, KC_RGUI
),
/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------. 
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC/SYM|  A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |'/SYM |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI |LAlt  |TAB/LCtr|Space|/LOWER  /       \RAISE \  |Bspc  |Ent/RCtr|RAlt| RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAKDH] = LAYOUT(
  MO(_ADJUST),        KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_TAB,             KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_EQL,
  LT(_SYMBOL, KC_ESC),KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     LT(_SYMBOL, KC_QUOT),
  KC_LSFT,            KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,   XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                  KC_LGUI,KC_LALT,MT(MOD_LCTL, KC_TAB),KC_SPC,  MO(_LOWER),          MO(_RAISE), KC_BSPC, MT(MOD_RCTL, KC_ENT), KC_RALT, KC_RGUI
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   {  |   [  |   (  |   <  |-------.    ,-------|   >  |   )  |   ]  |   }  |   ?  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|      |   `  |   ~  |   \  |   |  |-------|    |-------|   -  |   _  |   =  |   +  |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  | Bspc |Enter | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 * the idea: have a 'symbol shift' key that allows for symbol layer with opposing modifier ala the standard shift keys
 */

[_SYMBOL] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                       KC_F6,  KC_F7,    KC_F8,    KC_F9,  KC_F10,  KC_F11,
  _______,   KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, KC_F12,
  XXXXXXX,  XXXXXXX,  KC_LCBR, KC_LBRC, KC_LPRN,KC_LABK,                      KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR,  KC_QUES, XXXXXXX,
  _______,  XXXXXXX, KC_GRV, KC_TILD, KC_BSLS, KC_PIPE,  _______,       _______, KC_MINS,  KC_UNDS, KC_EQL, KC_PLUS, XXXXXXX, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | G(1) | G(2) | G(3) | G(4) | G(5) |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |WindowCap|PRVTAB|   |NXTTAB|ZOOM +|                    |      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |RegionCap|ALTSTB|   | ALTTB|ZOOM -|-------.    ,-------|   .  |   4  |   5  |   6  |   -  |   /  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|SnipTool |BACK  |   | FWRD |ZOOM 0|-------|    |-------|   0  |   1  |   2  |   3  |   +  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  | Bspc |Enter | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 * note: numlock has to be on for numpad keys to be registered as numbers and not nav cluster
 * set as normal number keycodes for now, may change to add numlock check later in the future
 * because already have another layer with nav cluster
 * 
 * note: window and region capture requires sharex
 * 
 * left/right/space is for media play/pause/seeking, if it can be done with media keys i would do that
 */

[_LOWER] = LAYOUT(
  _______,   G(KC_1),  G(KC_2),  G(KC_3),  G(KC_4),  G(KC_5),                         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
  _______,   A(KC_PSCR),C(KC_PGUP), XXXXXXX, C(KC_PGDN), C(KC_EQL),                      XXXXXXX,KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
  _______,  C(KC_PSCR), KC_ALTSTB, XXXXXXX,  KC_ALTTB,  C(KC_MINS),                      KC_DOT, KC_4,    KC_5,    KC_6, KC_MINS, KC_SLSH,
  _______,  G(S(KC_S)), A(KC_LEFT), XXXXXXX, A(KC_RIGHT),C(KC_0),_______,        _______,KC_0,   KC_1,    KC_2,    KC_3 ,KC_PLUS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      | Menu |      |      |                    | Home |  End | PgUp |Pgdown|  Ins | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LGui | LAlt | LCtl |LShift| Caps |-------.    ,-------| Left | Down |  Up  | Right|  Del |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------| Pscr |      |      |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  | Bspc |Enter | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                       KC_F6,  KC_F7,    KC_F8,    KC_F9,  KC_F10,  KC_F11,
  _______,  XXXXXXX,  XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX,                        KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_INS, KC_F12,
  _______, KC_LGUI, KC_LALT,  KC_LCTL,  KC_LSFT, KC_CAPS,                         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_DEL, XXXXXXX,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  KC_PSCR, XXXXXXX, XXXXXXX,XXXXXXX,  XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  |Enter | RCTR | RAlt | RShift |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAKDH, XXXXXXX,XXXXXXX,                     XXXXXXX, DT_DOWN,DT_PRNT,DT_UP, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )

};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_ALTTB:
            if (record->event.pressed) {
                if (!(mod_state & MOD_MASK_ALT)) {
                    register_mods(MOD_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case KC_ALTSTB:
            if (record->event.pressed) {
                if (!(mod_state & MOD_MASK_ALT)) {
                    register_mods(MOD_LALT);
                }
                register_mods(MOD_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_mods(MOD_LSFT);
            }
            break;
        case MO(_LOWER): // change to whatever layer is being entered for the alt tab behavior
            if (!record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    unregister_mods(MOD_LALT);
                }
            }
            return true;
    }
    return true;
}

// char oled_text[] = "qwrt"; 
// bool is_colemak;
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _QWERTY:
//         is_colemak = false;
//         break;
//     case _COLEMAKDH:
//         is_colemak = true;
//         break;
//     default: 
//         break;
//     // case _SYMBOL: 
//     //     oled_text = "symb";
//     //     break;
//     // case _LOWER: 
//     //     oled_text = "lowr";
//     //     break;
//     // case _RAISE: 
//     //     oled_text = "rais";
//     //     break;
//     // case _ADJUST: 
//     //     oled_text = "adjs";
//     //     break;
//     }
//     return state;
// }


/*___________OLED HANDLING___________*/

#ifdef OLED_ENABLE

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;
//     } else {
//         return OLED_ROTATION_0;
//     }
//     // return OLED_ROTATION_270;
// }

// bool oled_task_user(void) {
//     if (is_keyboard_master()) {
//         // if (is_colemak) {
//         //     oled_write("clmk", false);
//         // } else {
//         //     oled_write("qwrt", false);
//         // }
//         switch(get_highest_layer(layer_state)) {
//             case _QWERTY:
//                 oled_write("qwrt", false);
//                 break;
            
//             case _COLEMAKDH:
//                 oled_write("clmk", false);
//                 break;
//             default:
//                 break;
//         }
//         return false;
//     } else {
//         return true;
//     }
//     return false;
// }

#endif