#include <print>

//#include "../include/mwir_sim.hpp"

#include "../include/framebuffer.hpp"

int main(int argc, char** argv)
{
    // Read values

    // Init sim
    // MWIR_SIM<float> mwir_sim{

    // };

    std::println("Hello, World!");

    Framebuffer fb{128, 128};
    std::vector<uint32_t> bf(128 * 128, 0xFF00FF);
    fb.update_texture(bf);
    fb.render_texture();

    return 0;
}