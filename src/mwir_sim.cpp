#include "../include/mwir_sim.hpp"

#include <SDL3/SDL.h>

template <std::floating_point T>
MWIR_SIM<T>::MWIR_SIM(
    T waveband,
    std::uint32_t width,
    std::uint32_t height,
    T pixel_pitch,
    T focal_length,
    T field_of_view,
    T aperture, // f-number
    T optical_blur,
    T noise, // NETD
    T non_uniformity,
    T bad_pixels,
    T integration_time,
    T frame_rate,
    T gain, // contrast
    T level,    // brightness
    T palette,
    T polarity,
    T bit_depth
)
:
waveband(waveband),
width(width),
height(height),
pixel_pitch(pixel_pitch),
focal_length(focal_length),
field_of_view(field_of_view),
aperture(aperture),
optical_blur(optical_blur),
noise(noise),
non_uniformity(non_uniformity),
bad_pixels(bad_pixels),
integration_time(integration_time),
frame_rate(frame_rate),
gain(gain),
level(level),
palette(palette),
polarity(polarity),
bit_depth(bit_depth),
framebuffer(width, height)
{
    
}

