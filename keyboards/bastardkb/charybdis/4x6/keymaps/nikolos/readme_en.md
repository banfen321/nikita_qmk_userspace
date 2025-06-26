# Nikolos's Ultimate Charybdis Layout Guide

This is a quick start guide for all the features of your custom firmware for the Charybdis (4x6) keyboard.

---

### Layer Map

Your keyboard has 5 layers:

* **`BASE` (Layer 0):** The primary layer with a standard English QWERTY layout.
* **`RUSSIAN` (Layer 1):** The primary layer with a phonetic Russian (YCUKEN) layout.
* **`LOWER` (Layer 2):** A momentary layer for symbols, numbers, and system control.
* **`RAISE` (Layer 3):** A momentary layer for navigation, F-keys, and media control.
* **`POINTER` (Layer 4):** A momentary layer for trackball and mouse control.

---

### How to Use the Features

#### **1. Switching Languages (English <-> Russian)**

This is the main action you will perform.

1.  **Press and hold** one of the lower thumb keys (`LOWER` or `RAISE`).
2.  While holding it, **press** the `SWITCH_LANG` key (it is located where the `TAB` key is on the left hand).
3.  Release both keys.

This action simultaneously toggles the layer on the keyboard and sends the `Win+Space` command to the computer to change the OS input language.

#### **2. Typing Symbols ( `! @ # $ %` )**

1.  **Press and hold** the `LOWER` key (left lower thumb key).
2.  Press the desired keys on the top number row.
3.  Release the `LOWER` key.

#### **3. Text Navigation (Arrow Keys)**

1.  **Press and hold** the `RAISE` key (right lower thumb key).
2.  Use the `K` (Up), `J` (Down), `H` (Left), and `L` (Right) keys as arrows.
3.  Release the `RAISE` key.

#### **4. Mouse Control (Trackball)**

To use the mouse functions, you need to activate the `POINTER` layer.

* **Activating the Layer:**
    * **Method 1 (Manual):** Press and hold the `Z` or `/` key. The layer is active as long as you hold the key.
    * **Method 2 (Automatic):** Simply start moving the trackball. The layer will activate automatically and deactivate after one second of inactivity (this feature can be enabled/disabled in the `config.h` file).

* **Actions on the `POINTER` Layer:**
    * **Cursor Movement:** Move the trackball.
    * **Mouse Clicks:** The thumb cluster keys become mouse buttons (Left, Right, and Middle click).
    * **Scrolling:** Use the `K` (Up), `J` (Down), `H` (Left), and `L` (Right) keys to scroll.

#### **5. Accidentally Entering Bootloader Mode (`QK_BOOT`)**

If you accidentally put your keyboard into flashing mode (it stops typing), don't worry.

* **How to Exit:** Simply **unplug and replug the USB cable**.
* **How to Remove:** If this feature bothers you, find `QK_BOOT` on the `LOWER` and `RAISE` layers in your `keymap.c` file and replace it with `XXXXXXX`.