#include <stdio.h> 
#include <SDL2/SDL.h>



int main(int argc, char *argv[]){
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow("Game Window",	//window title
								   0,				//initial x position
								   0,				//initial y position
								   640,				//width (pixels)	
								   480,				//height (pixels)
						           0);				//flags
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_Rect rect = {220,140,200,200};

		SDL_RenderFillRect(renderer ,&rect);	
		SDL_RenderPresent(renderer);
		
		SDL_Event event;
		int running = 1;

		while (running) {
				while (SDL_PollEvent(&event)) {
						if (event.type == SDL_QUIT) {
								running = 0;
						} 
				}
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
}

