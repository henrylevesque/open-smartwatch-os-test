# Running DOOM on the Open Smartwatch

This document explains how to get a playable DOOM port running on the watch. The repository includes a minimal "DOOM (stub)" app that provides a placeholder and explains integration steps. A full DOOM port needs more work (binary, assets, and possibly PSRAM and build changes).

Summary:
- We added a placeholder app `OswAppDoom` (registered when `GAME_DOOM` is enabled).
- To run a real DOOM port, you'll normally use an ESP32 port such as `esp32-doom` or `TinyDoom` and adapt the graphics/audio backends.

High-level steps to integrate a full DOOM port
1. Choose a port: look for `esp32-doom` or similar projects. Confirm the license is compatible (GPL3 is used in this repo; DOOM WAD licensing must be respected).
2. Add the port's source to `lib/` or as a submodule. Prefer a small, embeddable port.
3. Provide a WAD file (e.g. DOOM.WAD). Place it in SPIFFS, SD card, or embed it (note: WAD files are ~20-30MB; you'll need storage).
4. Adapt the port to use the OSW display API:
   - Use OswHal::getInstance()->gfx() as the Graphics2D backend (implement a small wrapper that the DOOM port can call to blit frames).
   - Forward button events from OswAppDoom::onButton() to the port's input APIs.
5. Update `platformio.ini` build flags:
   - Enable PSRAM/extra RAM if needed: define BOARD_HAS_PSRAM and set correct board env that supports it.
   - Add `-D GAME_DOOM` to your `build_flags` so the DOOM app registers. Alternatively, add `#define GAME_DOOM 1` in a config header for local testing.
6. Add any extra libraries to `lib_deps` in `platformio.ini` or vendored under `lib/`.

Flashing and running (Windows PowerShell)
Prerequisites:
- PlatformIO installed (via VSCode or `pip install platformio`).
- Watch connected via USB; use the correct board env from `platformio.ini` (e.g. LIGHT_EDITION_V3_3).

Build + flash steps (PowerShell):
```powershell
# Build and upload using the default env
pio run -t upload -e LIGHT_EDITION_V3_3

# If you changed build flags for DOOM (e.g., created an env called DOOM), use:
pio run -t upload -e DOOM
```

If you see a "Failed to connect to ESP32" error: hold down the watch FLASH button while pressing RESET when PlatformIO starts uploading (see repository README).

How to enable the stub or the real DOOM app
- To enable the stub (already added by us), define `GAME_DOOM=1` in your build flags. For quick testing, edit `platformio.ini` and under the env you're using add:
  build_flags =
    -D GAME_DOOM=1

- For a real DOOM port, follow the integration steps above and ensure the port's main entry is called from `OswAppDoom::onStart()`.

Memory and performance notes
- Full DOOM may require significantly more RAM/flash than available. Consider using a board env with PSRAM (set `BOARD_HAS_PSRAM` and appropriate board in `platformio.ini`).
- Using SPIFFS/SD for the WAD file is recommended instead of embedding it in flash.

Testing without hardware
- The repository includes an emulator (`emulator/`). You can run the emulator to develop graphics/backends before testing on hardware.

Next steps I can do for you
- Try to integrate a specific ESP32 DOOM port as a proof-of-concept (this may be large and need tuning).
- Create a small graphics wrapper that maps the DOOM port framebuffer onto OswHal->gfx() so frames are drawn correctly.
- Add SD/SPIFFS WAD loader helper.
