#include "Application.hpp"
#include "Window.hpp"

int main()
{
    Cobra::Application* app = Cobra::Application::init(SDL_INIT_VIDEO);
    
    Cobra::Window window(0);
    
    app->run();
    
    return 0;
}
