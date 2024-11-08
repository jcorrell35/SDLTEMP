#include <stdio.h>
#include <SDL2/SDL.h>
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
#define FRAMES 30

int game_is_running = 0;
struct game_object{
    int x;
    int y;
    int width;
    int height;
}player;
void initialize_window(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game Window",	//window title
                       0,				//initial x position
                       0,				//initial y position
                       640,				//width (pixels)	
                       480,				//height (pixels)
                         0);				//flags
    //RENDER SETUP
    renderer = SDL_CreateRenderer(window, -1, 0); 
}

void destroy_window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); 
}

void handle_input(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            game_is_running = 0;
        } 
        switch (event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                        printf("LEFT");
                        break;
                    case SDLK_RIGHT:
                        printf("RIGHT");
                        break;
                    case SDLK_UP:
                        printf("UP");
                        break;
                    case SDLK_DOWN:
                        printf("DOWN");
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                        printf("LEFT");
                        break;
                    case SDLK_RIGHT:
                        printf("RIGHT");
                        break;
                    case SDLK_UP:
                        printf("UP");
                        break;
                    case SDLK_DOWN:
                        printf("DOWN");
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}
void update(){

}
int main(int argc, char *argv[]){
    game_is_running = 1;
    initialize_window();
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rect = {220,140,200,200};  
    SDL_RenderFillRect(renderer ,&rect);	
    SDL_RenderPresent(renderer);
 
    //GAME LOOP
    while (game_is_running == 1) {
        handle_input();
        update();
        //UPDATE GAME
        //RENDER
        SDL_Delay(1000/FRAMES);
    }
    destroy_window(); 
    return 0;
}

