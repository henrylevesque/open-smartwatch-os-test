#include "doom_shim.h"
#include "../tinydoom/tinydoom.h"
#include <OswHal.h>
#include <cstring>

namespace doom_shim {

static bool active = false;
static int frame_w = 320;
static int frame_h = 200;
static std::vector<uint8_t> fb;

bool init(const char* wad_path) {
    std::string wp = wad_path ? wad_path : std::string();
    if(!tinydoom::init(wp)) return false;
    active = true;
    fb.resize(frame_w * frame_h);
    return true;
}

bool run_frame() {
    if(!active) return false;
    if(!tinydoom::tick()) { active = false; return false; }
    tinydoom::render_frame(fb.data(), frame_w, frame_h);
    return true;
}

void blit_framebuffer() {
    if(!active) return;
    // map tinydoom 8-bit indices to RGB using a simple palette and draw to OswHal gfx
    auto gfx = OswHal::getInstance()->gfx();
    // Scale tinydoom frame to display size (nearest-neighbor)
    const int W = DISP_W;
    const int H = DISP_H;
    for(int y=0;y<H;y++){
        int sy = (y * frame_h) / H;
        for(int x=0;x<W;x++){
            int sx = (x * frame_w) / W;
            uint8_t idx = fb[sy*frame_w + sx];
            // simple pseudo-palette: convert index to RGB
            uint8_t r = idx;
            uint8_t g = (uint8_t)(~idx);
            uint8_t b = (uint8_t)(idx ^ (idx<<3));
            uint16_t color = gfx->color565(r, g, b);
            gfx->drawPixel(x, y, color);
        }
    }
}

void send_button(int button_id, bool pressed) {
    if(!active) return;
    tinydoom::send_input(button_id, pressed);
}

void shutdown() {
    tinydoom::shutdown();
    active = false;
    fb.clear();
}

bool is_active() { return active; }

} // namespace doom_shim
