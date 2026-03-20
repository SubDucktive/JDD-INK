#include <stdio.h>
#include <SDL2/SDL.h>

int running = 1;

int main(int argc, char* argv[]){

    if(SDL_Init(SDL_INIT_VIDEO) > 1){
        printf("ERROR! SDL COULD NOT INITIALIZE. SDL ERROR: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* win;

    win = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if(win == NULL){
        printf("ERROR! NULL POINTER TO WINDOW THROWN.");
        return 1;
    }

    SDL_Renderer* renderer;

    renderer = SDL_CreateRenderer(
        win,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if(renderer == NULL){
        printf("ERROR! NULL POINTER TO RENDERER THROWN.");
        return 1;
    }

    SDL_Event e;

    while(running){
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    running = 0;
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}