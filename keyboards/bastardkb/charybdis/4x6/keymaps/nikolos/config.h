#define EE_HANDS
#pragma once

/*
 * Nikolos's Ultimate Charybdis Config
 *
 * This is the configuration file for the custom 'nikolos' keymap.
 * Здесь мы включаем или выключаем основные функции прошивки.
 */

// --- Настройки для VIA/Vial ---
// Указываем, что у нас будет 6 слоев, доступных для настройки в графическом конфигураторе
// (4 рабочих + 2 пустых "на вырост")
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// --- "Родные" фишки Charybdis для трекбола ---

// Раскомментируйте (удалите // в начале) следующую строку, чтобы включить
// автоматическую активацию слоя POINTER при движении трекбола.
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// Таймаут в миллисекундах, через который слой POINTER выключится после бездействия
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000

// Порог чувствительности для срабатывания. Чем меньше значение, тем чувствительнее.
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8

// Указываем, что на слое POINTER должен автоматически включаться режим "снайпера" (пониженное DPI)
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

