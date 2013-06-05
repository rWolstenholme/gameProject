#include "Header.h"


CharSprite::CharSprite(char* fileLocation, int x, int y)
{
	sprite = SDL_LoadBMP(fileLocation);
	source.x = 0;
	source.y = 0;
	toDraw.x = x;
	toDraw.y = y;
	/*source.w = w;
	source.h = h;*/
}

CharSprite::~CharSprite(void)
{
	SDL_FreeSurface(sprite);
}

int CharSprite::drawSprite(SDL_Surface* screen, int x, int y) {
	//Set any magenta in the sprite as transparent
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 0, 255) );

	toDraw.x = x;
	toDraw.y = y;
	return SDL_BlitSurface(sprite, &source, screen, &toDraw);
}

int CharSprite::drawSprite(SDL_Surface* screen) {
	//Set any magenta in the sprite as transparent
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format,255, 0, 255) );
	return SDL_BlitSurface(sprite, &source, screen, &toDraw);
}

void CharSprite::updateSprite(bool keysDown[323]){
	if (keysDown[SDLK_LEFT]){toDraw.x -= 4;		right=false;}
	if (keysDown[SDLK_RIGHT]){toDraw.x += 4;	right=true;}
	if (keysDown[SDLK_UP]){toDraw.y -= 4;}
	if (keysDown[SDLK_DOWN]){toDraw.y += 4;}
}

