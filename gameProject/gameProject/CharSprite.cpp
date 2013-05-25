#include "CharSprite.h"


CharSprite::CharSprite(char* fileLocation, int x, int y)
{
	sprite = SDL_LoadBMP(fileLocation);
	source.x = x;
	source.y = y;
	/*source.w = w;
	source.h = h;*/
}


CharSprite::~CharSprite(void)
{
	free(sprite);
}

int CharSprite::drawSprite(SDL_Surface* screen, int x, int y) {
	//Set any magenta in the sprite as transparent
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 0, 255) );

	toDraw.x = x;
	toDraw.y = y;
	return SDL_BlitSurface(sprite, &source, screen, &toDraw);
}


void moveSprite(void) {}
