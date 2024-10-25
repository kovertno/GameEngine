//
// Created by Konrad Kurzak on 05/10/2024.
//
#ifndef GAME_H
#define GAME_H


#include <SDL2/SDL.h>
#include <glm/glm.hpp>


const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000/FPS;

class Game
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    int millisecsPrevFrame;

    int winWidth;  //window parameters
    int winHeight; //
public:
    Game();
    ~Game();

    void Initialize();
    void Setup();
    void Run();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};



#endif //GAME_H
