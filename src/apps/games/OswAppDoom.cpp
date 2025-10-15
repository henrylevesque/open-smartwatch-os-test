#include "apps/games/OswAppDoom.h"
#include <OswIcon.h>
#include <osw_ui.h>
#include <cstdio>
#include <string>

OswAppDoom::OswAppDoom(): OswAppV2() {
}

const char* OswAppDoom::getAppId() { return "osw.game.doom"; }
const char* OswAppDoom::getAppName() { return "DOOM"; }

void OswAppDoom::onStart() {
    OswAppV2::onStart();
    this->viewFlags = (OswAppV2::ViewFlags)(this->viewFlags | OswAppV2::ViewFlags::KEEP_DISPLAY_ON | OswAppV2::ViewFlags::NO_FPS_LIMIT);
    this->needsRedraw = true;
    this->lastTick = millis();
    this->frame = 0;
    // Try to find a WAD on the SD or SPIFFS
    wadPath.clear();
    // Check common locations for WAD files
    const char* candidates[] = { "/data/doom.wad", "/doom.wad", "/sd/doom.wad", "/sdcard/doom.wad", nullptr };
    for(int i=0; candidates[i]!=nullptr; i++) {
        FILE* f = fopen(candidates[i], "rb");
        if(f) {
            fclose(f);
            wadPath = std::string(candidates[i]);
            break;
        }
    }

    if(!wadPath.empty()) {
        engineRunning = doom_shim::init(wadPath.c_str());
        if(!engineRunning) {
            this->ui->showNotification("Failed to init DOOM engine (shim)", true);
        }
    } else {
        this->ui->showNotification("No WAD found. See docs/doom.md", true);
    }
}

void OswAppDoom::onLoop() {
    OswAppV2::onLoop();
    if(engineRunning) {
        doom_shim::run_frame();
        this->needsRedraw = true;
    } else {
        unsigned long now = millis();
        if(now - lastTick > 100) { // advance simple animation
            lastTick = now;
            frame = (frame + 1) % 4;
            this->needsRedraw = true;
        }
    }
}

void OswAppDoom::onDraw() {
    auto gfx = this->hal->gfx();
    gfx->fill(0); // clear
    if(engineRunning && doom_shim::is_active()) {
        // Let shim blit the current frame
        doom_shim::blit_framebuffer();
    } else {
        gfx->setTextSize(1.0f);
        gfx->setTextCenterAligned();
        gfx->setTextCursor(DISP_W/2, 8);
        gfx->print("DOOM (no engine)");
        int x = DISP_W/2 - 20;
        int y = DISP_H/2 - 10;
        for(int i=0;i<4;i++) {
            uint16_t col = (i==frame) ? this->ui->getInfoColor() : this->ui->getForegroundDimmedColor();
            gfx->fillFrame(x + i*10, y, 8, 8, col);
        }
    }
}

void OswAppDoom::onButton(Button id, bool up, ButtonStateNames state) {
    OswAppV2::onButton(id, up, state);
    if(engineRunning) {
        // map select/left/right/up/down to doom inputs
        if(up && state == ButtonStateNames::SHORT_PRESS) {
            int bid = (int)id;
            doom_shim::send_button(bid, true);
            doom_shim::send_button(bid, false);
        }
    } else {
        if(up && state == ButtonStateNames::SHORT_PRESS && id == Button::BUTTON_SELECT) {
            this->ui->showNotification("No engine: place WAD on SD or SPIFFS and restart app", true);
        }
        if(up && state == ButtonStateNames::LONG_PRESS && id == Button::BUTTON_SELECT) {
            this->ui->showNotification("See docs/doom.md for integration steps", true);
        }
    }
}
