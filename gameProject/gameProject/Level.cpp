#include "Header.h"


Level::Level(char* file)
{
	SDL_Surface *image;
	std::vector<SDL_Rect*> points;
	//Read given file, to get below.
	//Store a list of sprites and their starting postions.
	//Store a Map of images to an arraylist(vector) of SDL_Rect* for world design.
	//Store a list of world objects, and locations.

	//Prototype to fake implementation, without reading a file:
	for(int i=0; i< 10; i ++) {	
		image = IMG_Load("Resources/Sprites/grassDirt.png");
		SDL_Rect *temp = new SDL_Rect();
		temp->x = 50 + (i*_tileSize);
		temp->y = 300;
		points.push_back(temp);
	}
	images.emplace(image, points);
}


Level::~Level(void)
{
	//Free all used.
}

bool Level::drawLevel(SDL_Surface* drawTo)
{
	for(std::map<SDL_Surface*, std::vector<SDL_Rect*>>::iterator it = images.begin(); it != images.end(); ++it) {
		SDL_Rect *temp = new SDL_Rect();
		temp->x = 5;
		temp->y = 300;
		int count = 0;
		for (int i = 0; i < (int)it->second.size(); ++i) {
			if(SDL_BlitSurface(it->first, NULL, drawTo, (it->second).at(i)) < 0){
				fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());
				return false;
			}
			++count;
		}
	}
	return true;
}
