/* Copyright 2020 Purdea Andrei
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUM,
    _FN,
    _EMOJI
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    TEST = 400,
    VDRT,                   //Desktop Right "set to move right a space on mac"
    VDLT,                   //Desktop Left "set to move left a space on mac"
    VDUP,                   //V-Desktop Up "set to mission controll on mac"
    VDDN,                   //Min All "set to show desktop on mac"
    EXPL,                   //New Explorer On Windows "set to show launchpad on mac"
    SNIP,                   //Snip Tool Windows "set to save picture of selected area on mac"
    COPY,                   //Copy All
    PAST,                   //Paste Over
    TASK,                   //Task Manager
    DZRO,                   //Double Zero
    ATAB,                   //Alt + Tab "brew install alt-tab on mac"
    //Discord Section
    THIS,                   //Macro for ":this:" emoji on discord
    OOF,                    //Macro for ":oof:" emoji on discord
    PIKA,                   //Macro for ":surprised:" emoji on discord
    SCAT,                   //Macro for ":smiley_cat_spanish:" emoji on discord
    FCAT,                   //Macro for ":smiley_cat_fancy:" emoji on discord
    HART,                   //Macro for ":heart:" emoji on discord
    DROL,                   //Macro for ":drooling_face:" emoji on discord
    MONY,                   //Macro for ":smiley_takemoney:" emoji on discord
    FHAT,                   //Macro for "::smiley_tip_fedora:" emoji on discord
    SPIT                    //Macro for ":smiley_spit_surprised:" emoji on discord
};
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {                              //Code for macros
        switch(keycode) {
            case TEST:
            if (record->event.pressed) {
                SEND_STRING("TEST");
                } else {}break;
            case VDRT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL) ));
                } else {}break;
            case VDLT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI( SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL) ));
                } else {}break;
            case VDUP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_TAB)"t"));
                } else {}break;
            case VDDN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("d"));
                } else {}break;
            case EXPL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("e"));
                } else {}break;
            case SNIP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("s")));
                } else {}break;
            case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("ac"));
                } else {}break;
            case PAST:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F2) SS_LCTRL("v"));
                } else {}break;
            case TASK:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_DOWN(X_RSHIFT)SS_TAP(X_ESCAPE)SS_UP(X_RSHIFT)));
                SEND_STRING(SS_LGUI(SS_DOWN(X_LALT)SS_TAP(X_ESCAPE)SS_UP(X_LALT)));
                } else {}break;
            case DZRO:
            if (record->event.pressed) {
                SEND_STRING("00");
                } else {}break;
            case ATAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                } else {}break;
                //Discord Section
                case THIS:
                if (record->event.pressed) {
                    SEND_STRING(":this:" SS_TAP(X_ENTER) );
                    } else {}break;
                case OOF:
                if (record->event.pressed) {
                    SEND_STRING(":oof:" SS_TAP(X_ENTER));
                    } else {}break;
                case PIKA:
                if (record->event.pressed) {
                    SEND_STRING(":surprised:" SS_TAP(X_ENTER));
                    } else {}break;
                case SCAT:
                if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_spanish:" SS_TAP(X_ENTER));
                    } else {}break;
                case FCAT:
                if (record->event.pressed) {
                    SEND_STRING(":smiley_cat_fancy:" SS_TAP(X_ENTER));
                    } else {}break;
                case HART:
                if (record->event.pressed) {
                    SEND_STRING(":heart:" SS_TAP(X_ENTER));
                    } else {}break;
                case DROL:
                if (record->event.pressed) {
                    SEND_STRING(":drooling_face:" SS_TAP(X_ENTER));
                    } else {}break;
                case MONY:
                if (record->event.pressed) {
                    SEND_STRING(":smiley_takemoney:" SS_TAP(X_ENTER));
                    } else {}break;
                case FHAT:
                if (record->event.pressed) {
                    SEND_STRING(":smiley_tip_fedora:" SS_TAP(X_ENTER));
                    } else {}break;
                case SPIT:
                if (record->event.pressed) {
                    SEND_STRING(":smiley_spit_surprised:" SS_TAP(X_ENTER));
                    } else {}break;
        }
    }
#ifdef CONSOLE_ENABLE //Console Debug
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
    
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_all(
         KC_ESC,    TASK,     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,TG(_NUM), KC_PSLS, KC_PAST,  KC_PMNS,
        DM_PLY1, DM_PLY2,     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,    KC_7,    KC_8,    KC_9,  KC_PPLS,
           EXPL,    SNIP,LT(_EMOJI,KC_CAPS),KC_A, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,   KC_NO,  KC_ENT,    KC_4,    KC_5,    KC_6,  KC_PEQL,
           COPY,    PAST,    KC_LSFT,   KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,    KC_1,    KC_2,    KC_3,  KC_BSPC,
           VDLT,    VDRT,   KC_LCTRL, MO(_FN), KC_LALT,                   KC_BSPC,   KC_NO,  KC_SPC,                   KC_RALT, KC_RCTRL,KC_LEFT, KC_DOWN, KC_RGHT,    KC_0, KC_PDOT,  KC_PENT
    ),
    [_NUM] = LAYOUT_all(
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS, KC_HOME, KC_PGUP, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,  KC_END, KC_PGDN, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_all(
          RESET,   DEBUG,     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______, _______, _______, _______,
        DM_REC1, DM_REC2,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,    VDUP, _______, _______, _______, _______,
        _______, _______,    KC_LGUI, _______, _______,                   _______, _______, _______,                   _______, _______,    VDLT,    VDDN,    VDRT, _______, _______, _______
    ),
    [_EMOJI] = LAYOUT_all(
        _______, _______,    _______,    THIS,     OOF,    PIKA,    SCAT,    FCAT,    HART,    DROL,    MONY,    FHAT,    SPIT, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______
    )
};
