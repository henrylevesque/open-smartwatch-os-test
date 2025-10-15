#include "tinydoom.h"
#include <atomic>
#include <vector>
#include <cstring>

namespace tinydoom {

static std::atomic<bool> running{false};
static int tickCounter = 0;
static int frameW = 320, frameH = 200;

bool init(const std::string& wadPath) {
    (void)wadPath;
    running.store(true);
    tickCounter = 0;
    return true;
}

bool tick() {
    if(!running.load()) return false;
    tickCounter++;
    return true;
}

void render_frame(uint8_t* outBuf, int width, int height) {
    // Simple demo: vertical bars that move with tickCounter
    if(!running.load()) {
        if(outBuf && width>0 && height>0) std::memset(outBuf, 0, width*height);
        return;
    }
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            // produce a repeating pattern
            uint8_t idx = (uint8_t)(((x/8) + (y/8) + (tickCounter/4)) & 0xFF);
            outBuf[y*width + x] = idx;
        }
    }
}

void send_input(int code, bool pressed) {
    (void)code; (void)pressed; // no-op for demo
}

void shutdown() {
    running.store(false);
}

bool is_running() { return running.load(); }

} // namespace tinydoom
