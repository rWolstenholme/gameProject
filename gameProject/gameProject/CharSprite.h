#pragma once
#include "SDL.h"
#include "SDL_image.h"

/**
    Class for Chracter Sprites, available to be drawn and moved around the screen(eventually).
	*/
class CharSprite
{
private:
	SDL_Rect source;
	SDL_Rect toDraw;
	SDL_Surface *sprite;
public:
/**
	Contructor!
	*/
	CharSprite(char*, int, int);
	~CharSprite(void);
	/**
	Hopefully draw it.
	@return int - Will return -1 if there is an error, otherwise 0.
	*/
	int drawSprite(SDL_Surface*, int, int);
	void moveSprite(void); //To Do
	void updateSprite(SDL_Event);
	int CharSprite::drawSprite(SDL_Surface*);
};

