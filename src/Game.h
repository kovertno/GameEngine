//
// Created by Konrad Kurzak on 05/10/2024.
//

#include <SDL2/SDL.h>>

#ifndef GAME_H
#define GAME_H



class Game
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    int winWidth;  //window parameters
    int winHeight; //
public:
    Game();
    ~Game();

    void Initialize();
    void Run();
    void Setup();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
};



#endif //GAME_H
