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

void CharSprite::updateSprite(SDL_Event e){
	if(e.type == SDL_KEYUP ) { 
		switch( e.key.keysym.sym ) { 
		case SDLK_UP: toDraw.y -= 50; break; 
		case SDLK_DOWN: toDraw.y += 50; break; 
		case SDLK_LEFT: toDraw.x -= 50; break; 
		case SDLK_RIGHT: toDraw.x += 50; break; 
		} 
	}
}
