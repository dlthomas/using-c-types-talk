
#include <SDL.h>


SDL_Texture * volatile texture = NULL;

int load_image_thread(void *renderer) {
	SDL_Surface *surface = SDL_LoadBMP("myimage.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	return 0;
}

void render_image() {
	SDL_Window *win = SDL_CreateWindow("Hello World!",
      100, 100, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
	SDL_CreateThread(load_image_thread, "image loader", renderer);


	for(;;) {
		SDL_Event e;
		while (SDL_PollEvent(&e)){
			switch(e.type) {
				case SDL_QUIT: return;
			}
		}






		SDL_RenderClear(renderer);
		if(texture) SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}
}

int main() {

	if(SDL_Init(SDL_INIT_VIDEO) != 0) return EXIT_FAILURE;

	render_image();
	return EXIT_SUCCESS;
}
