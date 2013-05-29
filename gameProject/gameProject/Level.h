#pragma once

#include "Header.h"

class Level
{
private:
	//CharSprite spriteList[];
	//Map of SDL_Surface* to an arraylist(vector) of SDL_Rect*, to store where level blocks should be placed.
	std::map<SDL_Surface*, std::vector<SDL_Rect*>> images;
public:
	/**
	@param Takes file location.
	*/
	Level(char*);
	~Level(void);
	/**
	Method to draw the level's world design.
	@return bool indicated false if error.
	*/
	bool drawLevel(SDL_Surface*);

	//Other Methods:
	//Fill world(world objects).
	//Draw sprites.
};

