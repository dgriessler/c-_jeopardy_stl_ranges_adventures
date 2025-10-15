#pragma once

#include <bit>
#include <cstdint>

// Convert float to uint32_t at compile-time.

constexpr uint32_t float_to_bits(float f) { return std::bit_cast<uint32_t>(f); }
