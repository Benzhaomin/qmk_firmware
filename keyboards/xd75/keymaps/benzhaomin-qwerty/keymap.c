/* Copyright 2020 Benjamin Maisonnas <ben@wainei.net>
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

// layers
#define _QWERTY 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | DEL    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | q      | w      | e      | r      | t      | y      | u      | i      | o      | p      | [      | ]      | HOME   | END    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | `      | a      | s      | d      | f      | g      | h      | j      | k      | l      | ;      | '      | |      | ENTER  | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | z      | x      | c      | v      | b      | n      | m      | ,      | .      | /      | \      | PG UP  | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | CMD    | ALT    | FN     |        | SPACE  | SPACE  | SPACE  | SPACE  |        |        | MENU   | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  	KC_1,   	KC_2,   	KC_3,    	KC_4,   KC_5,   	KC_6,   	KC_7,    	KC_8,    	KC_9,    	KC_0,   	KC_MINS,  KC_EQL,    	KC_DEL,  	KC_BSPC,
    KC_TAB,  	KC_Q,   	KC_W,    	KC_E,    	KC_R,   KC_T,    	KC_Y,    	KC_U,     KC_I,     KC_O,   	KC_P,    	KC_LBRC,  KC_RBRC,   	KC_HOME,  KC_END,
    KC_GRV, 	KC_A,   	KC_S,    	KC_D,    	KC_F,   KC_G,    	KC_H,    	KC_J,     KC_K,     KC_L,     KC_SCLN, 	KC_QUOT,  KC_PIPE,   	KC_ENT,  	KC_ENT,
    KC_LSFT, 	KC_Z,    	KC_X,    	KC_C,    	KC_V,   KC_B,    	KC_N,     KC_M,   	KC_COMM,  KC_DOT,  	KC_SLSH, 	KC_BSLS,  KC_PGUP,  	KC_UP,    KC_PGDN,
    KC_LCTL, 	KC_LGUI, 	KC_LALT, 	MO(_FN),	KC_NO,  KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_NO,  	KC_NO,  	KC_MENU,  KC_LEFT,  	KC_DOWN,  KC_RIGHT
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | PRINT  | LED    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | PREV   | PLAY   | NEXT   |        |        |        |        |        | 7      | 8      | 9      |        |        | LED+   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | MUTE   |        | RESET  |        |        |        |        | 4      | 5      | 6      |        |        | LED-   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | 1      | 2      | 3      |        |        | LEDMAX |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     |        |        |        |        |        |        | 0      | .      |        |        | LEDLVL |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_NO,  	KC_F1,  	KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,    KC_F9,  	KC_F10, 	KC_F11,  	KC_F12,  	KC_PSCR,	BL_TOGG,
    KC_NO,  	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_7,     KC_8,   	KC_9,    	KC_NO,  	KC_NO,  	BL_INC,
    KC_NO,  	KC_NO,  	KC_MUTE,	KC_NO,  	RESET,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_4,     KC_5,   	KC_6,    	KC_NO,  	KC_NO,  	BL_DEC,
    KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_1,     KC_2,   	KC_3,    	KC_NO,  	KC_NO,  	BL_ON,
    KC_NO,  	KC_NO,  	KC_NO,  	KC_TRNS,	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_0,   	KC_DOT,  	KC_NO,  	KC_NO,  	BL_STEP
 ),

};
