/*
 * Nikolos's Ultimate Charybdis Layout
 * Author: nikolos
 * Last Updated: 2025-06-25
 *
 * This layout includes:
 * - QWERTY and phonetic Russian base layers.
 * - A custom one-press language switching key (Alt+Shift).
 * - Integrated trackball functions with auto-layer switching.
 * - Vial/VIA support.
 */
#include QMK_KEYBOARD_H

// Для "родных" функций трекбола
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif

// ===================================================================================
// --- 1. ОПРЕДЕЛЕНИЕ СЛОЕВ И КАСТОМНЫХ КЛАВИШ ---
// ===================================================================================

enum charybdis_keymap_layers {
    LAYER_BASE = 0, // Переименовано для совместимости с документацией
    LAYER_RUSSIAN,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER
};

enum custom_keycodes {
    SWITCH_LANG = SAFE_RANGE, // Наша "волшебная" клавиша
    // Наши "самодельные" русские клавиши
    MY_RU_J, MY_RU_C, MY_RU_U, MY_RU_K, MY_RU_E, MY_RU_N, MY_RU_G, MY_RU_SH, MY_RU_SC, MY_RU_Z, MY_RU_H, MY_RU_SOLIDUS,
    MY_RU_F, MY_RU_Y, MY_RU_W, MY_RU_A, MY_RU_P, MY_RU_R, MY_RU_O,  MY_RU_L,  MY_RU_D, MY_RU_ZH, MY_RU_JE,
    MY_RU_JA, MY_RU_CH, MY_RU_S, MY_RU_M, MY_RU_I, MY_RU_T, MY_RU_SF, MY_RU_B, MY_RU_JU, MY_RU_DOT
};

// --- Определяем "ярлыки" для слоев ---
#define LOWER   MO(LAYER_LOWER)
#define RAISE   MO(LAYER_RAISE)
#define PT_Z    LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// ===================================================================================
// --- 2. РАСКЛАДКИ СЛОЕВ ---
// ===================================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
       KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_LALT,
                                   KC_LGUI, KC_SPC,   LOWER,      RAISE,  KC_ENT,
                                           KC_LALT, KC_BSPC,     KC_DEL
  ),

  [LAYER_RUSSIAN] = LAYOUT(
        KC_ESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,    MY_RU_J,  MY_RU_C,  MY_RU_U,  MY_RU_K,  MY_RU_E,     MY_RU_N,  MY_RU_G,  MY_RU_SH, MY_RU_SC, MY_RU_Z,  MY_RU_H,
        KC_LSFT,   MY_RU_F,  MY_RU_Y,  MY_RU_W,  MY_RU_A,  MY_RU_P,     MY_RU_R,  MY_RU_O,  MY_RU_L,  MY_RU_D,  MY_RU_ZH, MY_RU_JE,
        KC_LCTL,   MY_RU_JA, MY_RU_CH, MY_RU_S,  MY_RU_M,  MY_RU_I,     MY_RU_T,  MY_RU_SF, MY_RU_B,  MY_RU_JU, MY_RU_DOT, KC_LALT,
                                   KC_LGUI, KC_SPC,   LOWER,      RAISE,  KC_ENT,
                                           KC_LALT, KC_BSPC,     KC_DEL
  ),

  [LAYER_LOWER] = LAYOUT(
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
       SWITCH_LANG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
       RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
       RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,      KC_P0
  ),

  [LAYER_RAISE] = LAYOUT(
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       SWITCH_LANG, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
                                  _______, _______, _______,    _______, _______,
                                           _______, _______,    _______
  ),

  [LAYER_POINTER] = LAYOUT(
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,  EE_CLR,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  )
};

// ===================================================================================
// --- 3. ЛОГИКА ДЛЯ КАСТОМНЫХ КЛАВИШ И ФУНКЦИЙ ---
// ===================================================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case SWITCH_LANG:
        tap_code16(LALT(KC_LSFT));
        layer_invert(LAYER_RUSSIAN);
        return false;
      // Логика для русских букв
      case MY_RU_J: tap_code(KC_Q); return false;
      case MY_RU_C: tap_code(KC_W); return false;
      case MY_RU_U: tap_code(KC_E); return false;
      case MY_RU_K: tap_code(KC_R); return false;
      case MY_RU_E: tap_code(KC_T); return false;
      case MY_RU_N: tap_code(KC_Y); return false;
      case MY_RU_G: tap_code(KC_U); return false;
      case MY_RU_SH: tap_code(KC_I); return false;
      case MY_RU_SC: tap_code(KC_O); return false;
      case MY_RU_Z: tap_code(KC_P); return false;
      case MY_RU_H: tap_code(KC_LBRC); return false;
      case MY_RU_SOLIDUS: tap_code(KC_RBRC); return false;
      case MY_RU_F: tap_code(KC_A); return false;
      case MY_RU_Y: tap_code(KC_S); return false;
      case MY_RU_W: tap_code(KC_D); return false;
      case MY_RU_A: tap_code(KC_F); return false;
      case MY_RU_P: tap_code(KC_G); return false;
      case MY_RU_R: tap_code(KC_H); return false;
      case MY_RU_O: tap_code(KC_J); return false;
      case MY_RU_L: tap_code(KC_K); return false;
      case MY_RU_D: tap_code(KC_L); return false;
      case MY_RU_ZH: tap_code(KC_SCLN); return false;
      case MY_RU_JE: tap_code(KC_QUOT); return false;
      case MY_RU_JA: tap_code(KC_Z); return false;
      case MY_RU_CH: tap_code(KC_X); return false;
      case MY_RU_S: tap_code(KC_C); return false;
      case MY_RU_M: tap_code(KC_V); return false;
      case MY_RU_I: tap_code(KC_B); return false;
      case MY_RU_T: tap_code(KC_N); return false;
      case MY_RU_SF: tap_code(KC_M); return false;
      case MY_RU_B: tap_code(KC_COMM); return false;
      case MY_RU_JU: tap_code(KC_DOT); return false;
      case MY_RU_DOT: tap_code(KC_SLSH); return false;
    }
  }
  return true;
}

// --- "Родные" функции для трекбола ---
#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE