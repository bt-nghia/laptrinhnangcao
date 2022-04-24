#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void clean();
    void pickcharacter();
    bool running() { return isRunning; };

    static std::vector<ColliderComponent*> colliders;
    static SDL_Renderer* renderer;
    static SDL_Event event;
private:
    bool isRunning;
    SDL_Window* window;
};