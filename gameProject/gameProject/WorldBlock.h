#pragma once
#include "Header.h"

class WorldBlock
{
private:
	SDL_Surface* image;
	SDL_Rect* location;
public:
	WorldBlock(SDL_Surface*, SDL_Rect*);
	~WorldBlock(void);
	SDL_Surface *getImage();
	SDL_Rect *getLocation();

	//Could implement the draw function here, rather than inside of level.
};

