
#include "CheckedSDL.h"


SDL_Surface * volatile surface = NULL;

int load_image_thread(void *renderer) {
	surface = SDL_LoadBMP("myimage.bmp");

	return 0;
}

void render_image(TH(main)) {
	SDL_Window *win = SDL_CreateWindow(th, "Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);	
	SDL_Renderer *renderer = SDL_CreateRenderer(th, win, -1, 0);
	SDL_CreateThread(load_image_thread, "image loader", renderer);
	SDL_Texture *texture = NULL;

	for(;;) {
		SDL_Event e;
		while (SDL_PollEvent(th, &e)){
			switch(e.type) {
				case SDL_QUIT: return;
			}
		}

		if(surface) {
			texture = SDL_CreateTextureFromSurface(th, renderer, surface);
			surface = NULL;
		}

		SDL_RenderClear(th, renderer);
		if(texture) SDL_RenderCopy(th, renderer, texture, NULL, NULL);
		SDL_RenderPresent(th, renderer);
		SDL_Delay(100);
	}
}

int main() {
	main_thread_t th;
	if(SDL_Init(th, SDL_INIT_VIDEO) != 0) return EXIT_FAILURE;

	render_image(th);
	return EXIT_SUCCESS;
}
