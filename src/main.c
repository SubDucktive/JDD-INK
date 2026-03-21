#include <stdio.h>
#include <SDL2/SDL.h>

int running = 1;

int rect_x = 0;
int rect_y = 0;
int rect_vx = 0;
int rect_vy = 0;

int main(int argc, char* argv[]){

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
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

    SDL_Rect rect = {
        rect_x,
        rect_y,
        32,
        32
    };

    while(running){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        rect_x += rect_vx;
        rect_y += rect_vy;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);


        SDL_RenderPresent(renderer);
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