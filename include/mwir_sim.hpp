#pragma once

#include <concepts>
#include <cstdint>
#include <vector>

#include "framebuffer.hpp"

template <std::floating_point T>
class MWIR_SIM
{
private:
    // Camera
    // Camera properties
    T waveband;
    std::size_t width;
    std::size_t height;
    T pixel_pitch;
    T focal_length;
    T field_of_view;
    T aperture;             // f-number
    T optical_blur;
    T noise;                // NETD
    T non_uniformity;
    T bad_pixels;
    // Camera settings
    T integration_time;
    T frame_rate;
    T gain;                 // contrast
    T level;                // brightness
    T palette;
    T polarity;
    T bit_depth;
    // Rendering
    Framebuffer framebuffer;
public:
    MWIR_SIM(
        T waveband,
        std::size_t width,
        std::size_t height,
        T pixel_pitch,
        T focal_length,
        T field_of_view,
        T aperture,         // f-number
        T optical_blur,
        T noise,            // NETD
        T non_uniformity,
        T bad_pixels,
        T integration_time,
        T frame_rate,
        T gain,             // contrast
        T level,            // brightness
        T palette,
        T polarity,
        T bit_depth
    );

    ~MWIR_SIM();
};