#include "SDL.h"
#include "SDL_image.h"
#include "defs.h"


typedef struct Map  
{  
    int tile[_maxX][_maxY];  
} Map;

int main(int argc, char *argv[])
{
	Map level;
	for(int i=0;i<_maxX;i++){
		level.tile[i][20]=1;
	}

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

	for(int x = 0; x<_maxX; x++){
		for(int y = 0; y<_maxY; y++){
			if(level.tile[x][y]==1){
				SDL_Rect pos;
				pos.x=x*_tileSize;
				pos.y=y*_tileSize;
				SDL_Rect *posP = &pos;
				if(SDL_BlitSurface(image, NULL, screen, posP) < 0){
					fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());
				}
			}
			SDL_UpdateRect(screen, _maxX*_tileSize, _maxY*_tileSize, image->w, image->h);
		}
	}

	SDL_Flip(screen);

	SDL_Delay( 5000 );

	return 0;
}
