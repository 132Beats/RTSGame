//
// Created by hendrik on 15.10.19.
//

#include "mockwindow.h"


#define GLCall(x) GLClearError();x;GLPrintError(#x, __FILE__, __LINE__);
#ifndef M_PI
#define M_PI	3.14159265358979323846f
#endif


Mockwindow::Mockwindow() : sdl_window(SDL_CreateWindow("RTS", 20, 20, 1280, 720, SDL_WINDOW_OPENGL)) {
    std::cout << "Window()" << std::endl;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    context_ = SDL_GL_CreateContext(sdl_window);
    if (context_ == nullptr) {
        std::cout<<"lollol";
        throw "no context";
    }
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
}
Mockwindow::~Mockwindow() {
    SDL_GL_DeleteContext(context_);
    SDL_DestroyWindow(sdl_window);
}
void Mockwindow::Show() {
    //std::cout << "Window::Show()" << std::endl;
    SDL_ShowWindow(sdl_window);
}
void Mockwindow::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //std::cout << "Clear()" << std::endl;
}
void Mockwindow::Swap() {
    SDL_GL_SwapWindow(sdl_window);
    //std::cout << "Swap()" << std::endl;
}
void Mockwindow::SetBackground(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
    //std::cout << "SB()" << std::endl;
}