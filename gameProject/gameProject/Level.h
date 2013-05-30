#pragma once
#include "Header.h"

class Level
{
private:
	//Vector of Charsprite in the level.
	std::vector<CharSprite*> spriteList;
	//Vector of Worldblocks, to store where they should be placed.
	std::vector<WorldBlock*> images;
public:
	/**
	@param Takes file location.
	*/
	Level(char*);
	~Level(void);
	/**
	Method to draw the level's world design.
	@param surface to draw unto.
	@return bool indicated false if error.
	*/
	bool drawLevel(SDL_Surface*);

	/**
	Draw Sprites contained in the level.
	@param SDL_Surface - What to draw unto.
	@return bool - indicated false if error.
	*/
	bool drawSprites(SDL_Surface*);

	void updateSprites(SDL_Event);

	//Other Methods:
	//Fill world(world objects).
	//Get player start location.
};
