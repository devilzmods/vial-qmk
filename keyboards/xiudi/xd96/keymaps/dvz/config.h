 /* Copyright 2021 Milan Düwel
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

#pragma once

#define VIAL_COMBO_ENTRIES 4
#define COMBO_TERM 100

#define VIAL_KEYBOARD_UID {0x24, 0x47, 0x4C, 0xE2, 0xA8, 0x53, 0x83, 0x94}

//#define UNICODE_SELECTED_MODES UC_WINC

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK

#define RGBLIGHT_ANIMATIONS
/*#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_TWINKLE*/

#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// EEPROM usage

// TODO: refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x451F
#define EEPROM_MAGIC_ADDR 32
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x08
#define EEPROM_VERSION_ADDR 34

// Dynamic keymap starts after EEPROM version
#define DYNAMIC_KEYMAP_EEPROM_ADDR 35
// Dynamic macro starts after dynamic keymaps (35+(4*10*6*2)) = (35+480)
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR 899    // **** CHANGE THIS BASED ON MATRIX_ROWS & MATRIX_COLS ****
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 125    // **** CHANGE THIS BASED ON 1024-DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR ****
#define DYNAMIC_KEYMAP_MACRO_COUNT 16
