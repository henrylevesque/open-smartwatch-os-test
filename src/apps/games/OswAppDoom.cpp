#include "apps/games/OswAppDoom.h"
#include <OswIcon.h>
#include <osw_ui.h>

OswAppDoom::OswAppDoom(): OswAppV2() {
}

const char* OswAppDoom::getAppId() { return "osw.game.doom"; }
const char* OswAppDoom::getAppName() { return "DOOM (stub)"; }

void OswAppDoom::onStart() {
    OswAppV2::onStart();
    this->viewFlags = (OswAppV2::ViewFlags)(this->viewFlags | OswAppV2::ViewFlags::KEEP_DISPLAY_ON | OswAppV2::ViewFlags::NO_FPS_LIMIT);
    this->needsRedraw = true;
    this->lastTick = millis();
    this->frame = 0;
}

void OswAppDoom::onLoop() {
    OswAppV2::onLoop();
    unsigned long now = millis();
    if(now - lastTick > 100) { // advance simple animation
        lastTick = now;
        frame = (frame + 1) % 4;
        this->needsRedraw = true;
    }
}

void OswAppDoom::onDraw() {
    // Very small placeholder: draw a 2x2 pixel "sprite" animation
    auto gfx = this->hal->gfx();
    gfx->fill(0); // clear
    gfx->setTextSize(1.0f);
    gfx->setTextCenterAligned();
    gfx->setTextCursor(DISP_W/2, 8);
    gfx->print("DOOM (stub)");
    int x = DISP_W/2 - 20;
    int y = DISP_H/2 - 10;
    // draw 4 frames of simple pattern
    for(int i=0;i<4;i++) {
        uint16_t col = (i==frame) ? this->ui->getInfoColor() : this->ui->getForegroundDimmedColor();
        gfx->fillFrame(x + i*10, y, 8, 8, col);
    }
}

void OswAppDoom::onButton(Button id, bool up, ButtonStateNames state) {
    OswAppV2::onButton(id, up, state);
    if(up && state == ButtonStateNames::SHORT_PRESS && id == Button::BUTTON_SELECT) {
        // Normally would toggle pause or bring up in-game menu
        this->ui->showNotification("DOOM stub: press LONG to learn how to install real DOOM", true);
    }
    if(up && state == ButtonStateNames::LONG_PRESS && id == Button::BUTTON_SELECT) {
        this->ui->showNotification("See docs/doom.md for integration steps", true);
    }
}
