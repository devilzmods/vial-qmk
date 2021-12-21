/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x24, 0x47, 0x4C, 0xE2, 0xA8, 0x53, 0x83, 0x94}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 } //Esc + Space
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

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
