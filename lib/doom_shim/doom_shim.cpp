#include "doom_shim.h"
#include <atomic>

namespace doom_shim {

static std::atomic<bool> active{false};

bool init(const char* wad_path) {
    (void)wad_path; // unused for shim
    active.store(true);
    return true;
}

bool run_frame() {
    // No-op: pretend we are running but do nothing
    return active.load();
}

void blit_framebuffer() {
    // No framebuffer in shim
}

void send_button(int button_id, bool pressed) {
    (void)button_id; (void)pressed;
}

void shutdown() {
    active.store(false);
}

bool is_active() {
    return active.load();
}

} // namespace doom_shim
