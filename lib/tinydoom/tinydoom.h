#pragma once

#include <cstdint>
#include <string>

namespace tinydoom {

// Initialize engine with a path to a WAD (unused in demo). Returns true on success.
bool init(const std::string& wadPath);

// Advance the simulation by one tick/frame. Returns true while running.
bool tick();

// Render the current frame into an 8-bit indexed framebuffer (palette indices).
// The buffer must be at least width*height bytes. Typical doom frame is 320x200.
void render_frame(uint8_t* outBuf, int width, int height);

// Send an input code (simple integer mapping)
void send_input(int code, bool pressed);

// Shutdown engine
void shutdown();

// Query activity
bool is_running();

} // namespace tinydoom
