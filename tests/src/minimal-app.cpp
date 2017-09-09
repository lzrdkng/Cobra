#include "SDL.hpp"
#include "Application.hpp"
#include "Window.hpp"
#include "Renderer.hpp"

int main()
{
  SDL::Application::init(SDL::InitVideo);

  SDL::Window root("Minimal app", 0, 0, 250, 250, SDL::WindowResizable);

  SDL::Renderer render(root, SDL::RendererAccelerated);

  SDL::Application::run(root);

  return 0;
}
