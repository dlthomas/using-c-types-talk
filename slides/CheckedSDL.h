/* CheckedSDL.h */

#define SDL_CreateTextureFromSurface SDL_CreateTextureFromSurface_Nope
#define SDL_CreateRenderer SDL_CreateRenderer_Nope
#define SDL_CreateWindow SDL_CreateWindow_Nope
#define SDL_PollEvent SDL_PollEvent_Nope
#define SDL_RenderClear SDL_RenderClear_Nope
#define SDL_RenderCopy SDL_RenderCopy_Nope
#define SDL_RenderPresent SDL_RenderPresent_Nope
#define SDL_Init SDL_Init_Nope
#include <SDL.h>
#undef SDL_CreateTextureFromSurface
#undef SDL_CreateRenderer
#undef SDL_CreateWindow
#undef SDL_PollEvent
#undef SDL_RenderClear
#undef SDL_RenderCopy
#undef SDL_RenderPresent
#undef SDL_Init

typedef struct main_thread_s { /* int unused; */ } main_thread_t;
#define TH(THREAD_NAME) THREAD_NAME##_thread_t th __attribute__((unused))

extern DECLSPEC SDL_Window * SDLCALL SDL_CreateWindow(
    TH(main),
    const char *title, int x, int y, int w, int h, Uint32 flags);

extern DECLSPEC int SDLCALL SDL_PollEvent(TH(main), SDL_Event * event);

extern DECLSPEC SDL_Texture * SDLCALL SDL_CreateTextureFromSurface(
    TH(main), SDL_Renderer * renderer, SDL_Surface * surface);

extern DECLSPEC SDL_Renderer * SDLCALL SDL_CreateRenderer(
    TH(main),
    SDL_Window * window, int index, Uint32 flags);

extern DECLSPEC int SDLCALL SDL_Init(TH(main), Uint32 flags);

extern DECLSPEC void SDLCALL SDL_RenderPresent(TH(main), SDL_Renderer * renderer);

extern DECLSPEC void SDLCALL SDL_RenderClear(TH(main), SDL_Renderer * renderer);

extern DECLSPEC int SDLCALL SDL_RenderCopy(
    TH(main),
    SDL_Renderer * renderer, SDL_Texture * texture,
    const SDL_Rect * srcrect, const SDL_Rect * dstrect);


