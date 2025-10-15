// Minimal Doom shim API — provides hooks for engine initialization, frame blit and input
#pragma once

#include <cstdint>

namespace doom_shim {

// Return true if engine initialized successfully
bool init(const char* wad_path);
// Run one frame of the engine; returns true if running
bool run_frame();
// Blit the engine framebuffer to the display. Expected to be called from the UI draw loop.
void blit_framebuffer();
// Send a key/button event
void send_button(int button_id, bool pressed);
// Shutdown engine
void shutdown();

// Query whether the engine is active
bool is_active();

} // namespace doom_shim
