#include "SDL.h"
#include "SDL_image.h"
#include "defs.h"
#define FRAMES_PER_SECOND 60
#define LOCATIONX 100	//Location->x of sprite at start
#define LOCATIONY 100	//Location->y of sprite at start
#include <iostream>
#include <string>

typedef struct Map  
{  
	int tile[_maxX][_maxY];  
} Map;

int main(int argc, char *argv[])
{
	Map *level = new Map;
	for(int i=0;i<_maxX;i++){
		level->tile[i][20]=1;
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
			if(level->tile[x][y]==1){
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

	//Attempt at sprite loading.
	SDL_Surface *sprite = SDL_LoadBMP("Resources/Sprites/ninja.bmp");
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 0, 255) );	//Set magenta as transparent
	SDL_Rect source;	//What parts of sprite surface to draw.
	source.x = 0;
	source.y = 0;
	SDL_Rect toDraw;	//Where to draw the sprite.
	toDraw.x = LOCATIONX;
	toDraw.y = LOCATIONY;
	if (SDL_BlitSurface(sprite, &source, screen, &toDraw) < 0) {
		fprintf(stderr, "BlitSurface error(sprite): %s\n", SDL_GetError());
	}

	SDL_Flip(screen);

	SDL_Event event;
	bool gameRunning = true;
	int start = SDL_GetTicks();
	//int start2 = start;
	//long long int numFrames = 0;
	while (gameRunning)
	{
		//numFrames++;
		if( SDL_PollEvent( &event ) )
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		} 
		int diff = SDL_GetTicks() - start;
		if(diff < 1000 / FRAMES_PER_SECOND ) { 
			//Sleep the remaining frame time 
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - diff); 
		}
		start = SDL_GetTicks();
		//std::cout << (int)(( numFrames/(float)(SDL_GetTicks() - start2) )*1000) << "\n"; //Apparently gets 62 FPS, so pretty close.
	}
	SDL_Quit();
	return 0;
}
