//
// Created by hendrik on 15.10.19.
//

#ifndef RTS_MOCKWINDOW_H
#define RTS_MOCKWINDOW_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include "glm/gtc/matrix_transform.hpp"
#ifndef _WIN32
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#else
#include <SDL.h>
#include <glm\glm.hpp>
#endif

class Mockwindow {

public:
    Mockwindow();
    ~Mockwindow();
    void Show();
    void Clear();
    void Swap();
    void SetBackground(float red, float green, float blue, float alpha);
private:
    SDL_Window* sdl_window{ nullptr };
    SDL_GLContext context_{ nullptr };
};

#endif //RTS_MOCKWINDOW_H
