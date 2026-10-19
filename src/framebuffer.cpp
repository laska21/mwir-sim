#include "../include/framebuffer.hpp"

void std::default_delete<SDL_Window>::operator()(SDL_Window* p) { SDL_DestroyWindow(p); };
void std::default_delete<SDL_Renderer>::operator()(SDL_Renderer* p) { SDL_DestroyRenderer(p); };
void std::default_delete<SDL_Texture>::operator()(SDL_Texture* p) { SDL_DestroyTexture(p); };

Framebuffer::Framebuffer(std::uint32_t width, std::uint32_t height)
    : width(width), height(height)
{
    // TODO: Find a way to solve this shit
    if (!SDL_Init(SDL_INIT_VIDEO)) 
        throw std::runtime_error(SDL_GetError());

    win.reset(SDL_CreateWindow("MWIR_SIM", width, height, 0));
    ren.reset(SDL_CreateRenderer(win.get(), 0));
    tex.reset(SDL_CreateTexture(ren.get(), 
            SDL_PIXELFORMAT_RGBA8888, 
            SDL_TEXTUREACCESS_STREAMING, 
            width, 
            height));
    
    if (!win || !ren || !tex)
        throw std::runtime_error(SDL_GetError());

    SDL_SetTextureScaleMode(tex.get(), SDL_SCALEMODE_NEAREST); // crisp pixels
}

void Framebuffer::update_texture(std::span<uint32_t> pixels)
{
    SDL_UpdateTexture(tex.get(), nullptr, pixels.data(), width * sizeof(uint32_t));
}

void Framebuffer::render_texture()
{
    SDL_RenderClear(ren.get());
    SDL_RenderTexture(ren.get(), tex.get(), nullptr, nullptr);
    SDL_RenderPresent(ren.get());
}

Framebuffer::~Framebuffer()
{
    win.reset();
    ren.reset();
    tex.reset();
    SDL_Quit();
}