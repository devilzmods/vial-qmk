/* Copyright 2020 marksard
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
#include "../common/oled_helper.h"
#include "keymap_german.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

#define KC_TBSF  LSFT_T(KC_TAB)
#define KC_ALAP  LALT_T(KC_APP)
#define KC_GRSF  RSFT_T(KC_GRV)

enum combos {
    AE,
    OE,
    UE,
    SZ
};

const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM sz_combo[] = {KC_S, DE_Z, COMBO_END};

combo_t key_combos[] = {
  [AE] = COMBO(ae_combo, DE_ADIA),
  [OE] = COMBO(oe_combo, DE_ODIA),
  [UE] = COMBO(ue_combo, DE_UDIA),
  [SZ] = COMBO(sz_combo, DE_SS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_base(
  //,--------------------------------------------------------------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,           KC_ENT,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_UP,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LGUI, KC_LALT,   LOWER,         KC_SPC, LT(_RAISE, KC_SPC),  KC_DEL, KC_ALAP, KC_LEFT, KC_DOWN, KC_RGHT,
  //`-------------------------------------------------------------------------------------------------------------------'
      KC_GRSF
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_RAISE] = LAYOUT_base(
  //,--------------------------------------------------------------------------------------------------------------------.
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, DE_SLSH, DE_LPRN, DE_RPRN,  DE_EQL,           KC_DEL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      _______, _______, _______, _______, _______, _______, DE_PIPE, DE_QUES, DE_LBRC, DE_RBRC, DE_QUOT,          _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, DE_BSLS, DE_LABK, DE_RABK, DE_LCBR, DE_RCBR, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,           KC_DEL,          _______, _______, XXXXXXX, KC_HOME, KC_PGDN,  KC_END,
  //`-------------------------------------------------------------------------------------------------------------------'
      DE_HASH
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_LOWER] = LAYOUT_base(
  //,--------------------------------------------------------------------------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_4,    KC_5,    KC_6, KC_QUOT,          _______,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_1,    KC_2,    KC_3, KC_INT1, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,          _______,          _______, _______,    KC_0,  KC_DOT, KC_COMM, KC_SLSH,
  //`-------------------------------------------------------------------------------------------------------------------'
      _______
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  ),

  [_ADJUST] = LAYOUT_base(
  //,--------------------------------------------------------------------------------------------------------------------.
      XXXXXXX,   QK_BOOT,  RGBRST, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_HOME, KC_PGUP,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+-----------------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_D,  KC_END, KC_PGDN,          XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, KC_MS_U,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,          XXXXXXX,          XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R,
  //`-------------------------------------------------------------------------------------------------------------------'
      _______
  // ExtraKey: This key is an extra key. REV1 is a split back space. REV2 is to the right of the arrow-up key.
  )
};

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_ENABLE
#include <stdio.h>
#include <string.h>

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(void) {

  oled_write(layer_status_buf, false);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()

static inline void render_status(void) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS();
  render_keymap_status();
  UPDATE_LOCK_STATUS();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

//   if (is_keyboard_master())
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {

  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#else

#define UPDATE_KEYMAP_STATUS()

#endif

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LNG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  UPDATE_KEYMAP_STATUS();
  return result;
}


const rgblight_segment_t PROGMEM numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_GREEN}
);
const rgblight_segment_t PROGMEM symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM config_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    numbers_layer,
    symbols_layer,
    config_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    return state;
}

