#include "Header.h"

WorldBlock::WorldBlock(SDL_Surface* image, SDL_Rect* location)
{
	WorldBlock::image = image;
	WorldBlock::location = location;
}


WorldBlock::~WorldBlock(void)
{
	//Free
}

SDL_Surface* WorldBlock::getImage(void) {
	return image;
}

SDL_Rect* WorldBlock::getLocation(void) {
	return location;
}

