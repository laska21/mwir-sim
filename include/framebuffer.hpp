#pragma once

#include <cstdint>
#include <memory>
#include <SDL3/SDL.h>
#include <vector>
#include <span>

namespace std
{
    template<> struct default_delete<SDL_Window> { void operator()(SDL_Window* p); };
    template<> struct default_delete<SDL_Renderer> { void operator()(SDL_Renderer* p); };
    template<> struct default_delete<SDL_Texture>  { void operator()(SDL_Texture* p); };
}

class Framebuffer
{
private:
    std::size_t width;
    std::size_t height;
    std::unique_ptr<SDL_Window> win;
    std::unique_ptr<SDL_Renderer> ren;
    std::unique_ptr<SDL_Texture> tex; 
public:
    Framebuffer(std::uint32_t width, std::uint32_t height);
    void update_texture(std::span<std::uint32_t> pixels);
    void render_texture();
    ~Framebuffer();
};