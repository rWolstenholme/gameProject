#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char *argv[])
{

	SDL_Surface *screen;

	atexit(SDL_Quit);

	if( SDL_Init(SDL_INIT_VIDEO) < 0 ) exit(1);

	SDL_WM_SetCaption("SDL Window", NULL);

	//Set icon file here
	SDL_Surface *icon = IMG_Load("Resources/favicon.ico");
	SDL_WM_SetIcon(icon, NULL);

	screen = SDL_SetVideoMode( 640 , 480 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);

	SDL_FillRect(screen , NULL , 0xABCDEF);

	SDL_Surface *image;
	//image = SDL_LoadBMP("ninja.bmp");
	image = IMG_Load("Resources/Sprites/grassDirt.png");
	//SDL_SetAlpha(image, SDL_SRCALPHA, 255); no idea what this does
	if (image->format->palette && screen->format->palette) {
		SDL_SetColors(screen, image->format->palette->colors, 0,
			image->format->palette->ncolors);
	}
	if(SDL_BlitSurface(image, NULL, screen, NULL) < 0)
		fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());
	SDL_UpdateRect(screen, 0, 0, image->w, image->h);

	SDL_Flip(screen);

	SDL_Delay( 5000 );

	return 0;
}
