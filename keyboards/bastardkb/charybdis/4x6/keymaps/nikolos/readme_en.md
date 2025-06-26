# Complete Guide to the "Nikolos's Ultimate" Charybdis Layout

Hello! This is your personal guide to the custom firmware for the Charybdis (4x6) keyboard. You've come a long way to create it, and this guide will help you get the most out of your work.

The goal of this layout is maximum ergonomics and efficiency for bilingual work. All features are designed to minimize hand movement and make your computer workflow faster and more comfortable.

---

### Layer Map

Your keyboard has 5 layers:

* **`BASE` (Layer 0):** The main layer with a standard English QWERTY layout.
* **`RUSSIAN` (Layer 1):** The main layer with a phonetic Russian (YCUKEN) layout.
* **`LOWER` (Layer 2):** A momentary layer for symbols, numbers, and system control.
* **`RAISE` (Layer 3):** A momentary layer for navigation, F-keys, and media.
* **`POINTER` (Layer 4):** A momentary layer for trackball and mouse control.

---

### How to Use the Features

#### **1. Switching Languages (English <-> Russian)**

1.  **Press and hold** one of the lower thumb keys (`LOWER` or `RAISE`).
2.  While holding it, **press** the `SWITCH_LANG` key (it is located where the `TAB` key is on the left hand).
3.  Release both keys.

This action simultaneously toggles the layer on the keyboard and sends the `Win+Space` command to the computer to change the OS input language. **Keep an eye on the language indicator on your computer screen** to confirm that it has switched as well.

#### **2. Typing Symbols ( `! @ # $ %` )**

1.  **Press and hold** the `LOWER` key (left lower thumb key).
2.  Press the desired keys on the top number row.
3.  Release the `LOWER` key.

#### **3. Text Navigation (Arrow Keys)**

1.  **Press and hold** the `RAISE` key (right lower thumb key).
2.  Use the `K` (Up), `J` (Down), `H` (Left), and `L` (Right) keys as arrows.
3.  Release the `RAISE` key.

#### **4. Mouse & Trackball Control**

To use the mouse functions, you need to activate the `POINTER` layer.

* **Activating the Layer:**
    * **Method 1 (Manual):** Press and hold the `Z` or `/` key. The layer is active as long as you hold the key.
    * **Method 2 (Automatic):** Simply start moving the trackball. The layer will activate automatically and deactivate after one second of inactivity (this feature can be enabled in your keymap's `config.h` file).

* **Actions on the `POINTER` Layer:**
    * **Cursor Movement:** Move the trackball.
    * **Mouse Clicks:** The thumb cluster keys become mouse buttons (Left, Right, and Middle click).
    * **Key-based Scrolling:** Use the `K` (Up), `J` (Down), `H` (Left), and `L` (Right) keys to scroll pages.
    * **Trackball Scrolling:** Press and hold `Z` (to activate the layer), then press and hold `X` (`DRGSCRL`) and move the ball to scroll.

---

### Additional Settings

#### **1. Adjusting Backlight Brightness**

You can change the RGB backlight brightness directly from the keyboard.

1.  **Press and hold** the `LOWER` key (left lower thumb key).
2.  Press the keys located at the `W` and `E` positions of the base layout:
    * **Key at `E` position (`RGB_VAI`):** Increases brightness.
    * **Key at `W` position (`RGB_VAD`):** Decreases brightness.
3.  On this layer, you also have `RGB_MOD` (changes animation mode) and `RGB_TOG` (toggles the backlight on/off).

#### **2. Adjusting Trackball Speed (DPI)**

You can cycle through different cursor sensitivity (speed) levels.

1.  **Activate the `POINTER` layer** (e.g., by holding the `Z` key).
2.  On this layer, find the **`DPI_MOD`** key. It is located at the `T` position (left hand) and `Y` position (right hand).
3.  Each press of `DPI_MOD` will cycle the cursor speed to the next preset level. Find the one that is most comfortable for you.
4.  This layer also has the **`SNIPING`** key (at the `C` position). Holding it will temporarily activate a very low speed mode for precise cursor positioning.