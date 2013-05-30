#include "Header.h"

Level::Level(char* file)
{
	//Read given file, to get the below.
	//Read player start location.
	//Store a list of sprites and their starting postions.
	//Store a Vector of worldblocks.
	//Store a list of world objects, and their respective locations.

	spriteList.push_back(new CharSprite("Resources/Sprites/ninja.bmp",50,50));

	SDL_Surface *image;
	image = IMG_Load("Resources/Sprites/grassDirt.png");
	for(int i=0; i< 10; i ++) {	
		SDL_Rect *temp = new SDL_Rect();
		temp->x = 50 + (i*_tileSize);
		temp->y = 320;
		images.push_back(new WorldBlock(image, temp));
	}

}


Level::~Level(void)
{
	//Free all used.
}

bool Level::drawLevel(SDL_Surface* drawTo)
{
	for (int i = 0; i < images.size(); ++i) {
		if (SDL_BlitSurface(images.at(i)->getImage(), NULL, drawTo, images.at(i)->getLocation()) < 0){
			fprintf(stderr, "BlitSurface error(level): %s\n", SDL_GetError());
			return false;
		}
	}
	return true;
}

bool Level::drawSprites(SDL_Surface* drawTo) {
	//Eventually change to a loop that stops upon reaching end of the screen.
	//i.e to only draw sprites that are able to be seen.
	for (int i = 0; i < spriteList.size(); ++i) {
		if (spriteList.at(i)->drawSprite(drawTo) < 0) {
			fprintf(stderr, "BlitSurface error(sprite): %s\n", SDL_GetError());
			return false;
		}
	}
	return true;
}

void Level::updateSprites(SDL_Event e) {
	for (int i = 0; i < spriteList.size(); ++i) {
		spriteList.at(i)->updateSprite(e);
	}
}