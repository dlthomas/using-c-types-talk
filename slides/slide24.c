









#include <SDL.h>












SDL_Window * SDL_CreateWindow(

    const char *title, int x, int y, int w, int h, Uint32 flags);

int SDL_PollEvent(          SDL_Event * event);

SDL_Texture * SDL_CreateTextureFromSurface(
              SDL_Renderer * renderer, SDL_Surface * surface);

SDL_Renderer * SDL_CreateRenderer(

    SDL_Window * window, int index, Uint32 flags);

int SDL_Init(          Uint32 flags);

void SDL_RenderPresent(          SDL_Renderer * renderer);

int SDL_RenderClear(          SDL_Renderer * renderer);

int SDL_RenderCopy(

    SDL_Renderer * renderer, SDL_Texture * texture,
    const SDL_Rect * srcrect, const SDL_Rect * dstrect);


