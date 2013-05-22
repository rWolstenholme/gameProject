 #include "SDL.h"

int main(int argc, char *argv[])
{

SDL_Surface *screen;

atexit(SDL_Quit);

if( SDL_Init(SDL_INIT_VIDEO) < 0 ) exit(1);

SDL_WM_SetCaption("SDL Window", NULL);

screen = SDL_SetVideoMode( 640 , 480 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);

SDL_FillRect(screen , NULL , 0x66FF00);

SDL_Flip(screen);

SDL_Delay( 5000 );

return 0;
}
