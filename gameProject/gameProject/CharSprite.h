#pragma once
#include "Header.h"

/**
    Class for Chracter Sprites, available to be drawn and moved around the screen.
	Probably make this abstract later on? Then have seperate class for each sprite type. 
	i.e. Player, enemyType1, enemyType2... 
	*/
class CharSprite
{
private:
	SDL_Rect source;
	SDL_Rect toDraw;
	SDL_Surface *sprite;
	bool right;
public:
/**
	Contructor!
	@param Takes file location and start location values.
	*/
	CharSprite(char*, int, int);
	~CharSprite(void);
	/**
	Hopefully draw it.
	@return int - Will return -1 if there is an error, otherwise 0.
	*/
	int drawSprite(SDL_Surface*, int, int);
	void updateSprite(bool []);
	int CharSprite::drawSprite(SDL_Surface*);

	//getStart();
	//getCurrentLocation();
};

