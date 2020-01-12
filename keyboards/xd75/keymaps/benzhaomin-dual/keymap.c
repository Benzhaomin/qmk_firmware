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
#define _AZERTY 1
#define _FN 2

// shifted keys
#define SC_EXCL		LSFT(KC_1)
#define SC_LPAR		LSFT(KC_5)
#define SC_RPAR		LSFT(KC_0)
#define SC_DQUOT	LSFT(KC_QUOT)
#define SC_UNDS		LSFT(KC_MINS)
#define SC_COLN		LSFT(KC_SCLN)
#define SC_QMARK	LSFT(KC_SLSH)

// custom codes
enum custom_keycodes {
  CC_AGRV = SAFE_RANGE,
  CC_EGRV,
  CC_UGRV,
  CC_EACU,
  CC_EHAT,
  CC_OHAT,
  CC_CCED
};

// dead keys are used to send è, à, ù, é and ç
#define X_COMPOSE X_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | DEL    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | q      | w      | e      | r      | t      | y      | u      | i      | o      | p      | [      | ]      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | `      | a      | s      | d      | f      | g      | h      | j      | k      | l      | ;      | '      | |      | ENTER  | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | z      | x      | c      | v      | b      | n      | m      | ,      | .      | /      | \      | PG UP  | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | CMD    | ALT    | FN     |        | SPACE  | SPACE  | SPACE  | SPACE  |        |        | AZERTY | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  	KC_1,   	KC_2,   	KC_3,    	KC_4,    	KC_5,   	KC_6,   	KC_7,    	KC_8,    	KC_9,    	KC_0,   	KC_MINS,  		KC_EQL,    	KC_DEL,  	KC_BSPC,
    KC_TAB,  	KC_Q,   	KC_W,    	KC_E,    	KC_R,     	KC_T,    	KC_Y,    	KC_U,     	KC_I,     	KC_O,   	KC_P,     	KC_LBRC,   		KC_RBRC,   	KC_NO,  	KC_NO,
    KC_GRV, 	KC_A,   	KC_S,    	KC_D,    	KC_F,     	KC_G,    	KC_H,    	KC_J,     	KC_K,     	KC_L,     	KC_SCLN,   	KC_QUOT,  		KC_PIPE,   	KC_ENT,  	KC_ENT,
    KC_LSFT, 	KC_Z,    	KC_X,    	KC_C,    	KC_V,     	KC_B,    	KC_N,      	KC_M,   	KC_COMM,  	KC_DOT,  	KC_SLSH,  	KC_BSLS,  		KC_PGUP,  	KC_UP,    	KC_PGDN,
    KC_LCTL, 	KC_LGUI, 	KC_LALT, 	MO(_FN),	KC_NO,  	KC_SPACE, 	KC_SPACE, 	KC_SPACE,  	KC_SPACE,  	KC_NO,  	KC_NO,  	TG(_AZERTY),   	KC_LEFT,  	KC_DOWN,  	KC_RIGHT
  ),

/* AZERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    |        | é      | "      | '      | (      | -      | è      | _      | ç      | à      | )      | =      | DEL    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | a      | z      | e      | r      | t      | y      | u      | i      | o      | p      | ê      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | `      | q      | s      | d      | f      | g      | h      | j      | k      | l      | m      | ù      |        | ENTER  | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | w      | x      | c      | v      | b      | n      | ,      | .      | :      | !      | ?      | PG UP  | UP     | PG DN  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | CMD    | ALT    | FN     |        | SPACE  | SPACE  | SPACE  | SPACE  |        |        | QWERTY | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_AZERTY] = LAYOUT_ortho_5x15( /* AZERTY */
    KC_ESC,  	KC_NO, 		CC_EACU, 	SC_DQUOT, 	KC_QUOT,  	SC_LPAR, 	KC_MINS, 	CC_EGRV,  	SC_UNDS,  	CC_CCED,  	CC_AGRV,  	SC_RPAR,  		KC_EQL,  	KC_DEL,  	KC_BSPC,
    KC_TAB,  	KC_A,   	KC_Z,    	KC_E,    	KC_R,     	KC_T,    	KC_Y,    	KC_U,     	KC_I,     	KC_O,		KC_P,     	CC_EHAT,   		CC_OHAT,   	KC_NO,  	KC_NO,
    KC_GRV, 	KC_Q,   	KC_S,    	KC_D,    	KC_F,     	KC_G,    	KC_H,    	KC_J,     	KC_K,     	KC_L,     	KC_M,     	CC_UGRV,  		KC_NO,   	KC_ENT,  	KC_ENT,
    KC_LSFT, 	KC_W,    	KC_X,    	KC_C,    	KC_V,     	KC_B,    	KC_N,    	KC_COMM,  	KC_DOT,  	SC_COLN,  	SC_EXCL,  	SC_QMARK,  		KC_PGUP,  	KC_UP,    	KC_PGDN,
    KC_LCTL, 	KC_LGUI, 	KC_LALT, 	MO(_FN),	KC_NO,  	KC_SPACE, 	KC_SPACE, 	KC_SPACE,  	KC_SPACE,  	KC_NO,  	KC_NO,  	TG(_AZERTY),   	KC_LEFT,  	KC_DOWN,  	KC_RIGHT
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
    KC_NO,  	KC_F1,  	KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,    	KC_F9,  	KC_F10, 	KC_F11,  	KC_F12,   	KC_PSCR,	BL_TOGG,
    KC_NO,  	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_7,     	KC_8,   	KC_9,    	KC_NO,  	KC_NO,  	BL_INC,
    KC_NO,  	KC_NO,  	KC_MUTE,	KC_NO,  	RESET,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_4,     	KC_5,   	KC_6,    	KC_NO,  	KC_NO,  	BL_DEC,
    KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_1,     	KC_2,   	KC_3,    	KC_NO,  	KC_NO,  	BL_ON,
    KC_NO,  	KC_NO,  	KC_NO,  	KC_TRNS,	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_NO,  	KC_0,   	KC_DOT,  	KC_NO,  	KC_NO,  	BL_STEP
 ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CC_AGRV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"`a");
      }
      break;
    case CC_EGRV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"`e");
      }
      break;
    case CC_UGRV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"`u");
      }
      break;
    case CC_EACU:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"'e");
      }
      break;
    case CC_EHAT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"^e");
      }
      break;
    case CC_OHAT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"^o");
      }
      break;
    case CC_CCED:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_COMPOSE)"c,");
      }
      break;
  }
  return true;
};
