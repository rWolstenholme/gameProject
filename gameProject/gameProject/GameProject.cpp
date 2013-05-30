#include "Header.h"

int main(int argc, char *argv[])
{
	SDL_Surface *screen;

	atexit(SDL_Quit);
	if( SDL_Init(SDL_INIT_VIDEO) < 0 ) exit(1);
	//Set window name
	SDL_WM_SetCaption("SDL Window", NULL);

	//Set icon file here
	SDL_Surface *icon = IMG_Load("Resources/favicon.ico");
	SDL_WM_SetIcon(icon, NULL);

	//Declare screen.
	screen = SDL_SetVideoMode( 640 , 480 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);
	SDL_FillRect(screen , NULL , 0xABCDEF);

	//Create Level
	Level *gameWorld = new Level("FakeFileCurrently");

	//Draw everything
	gameWorld->drawLevel(screen);
	gameWorld->drawSprites(screen);

	SDL_Flip(screen);

	SDL_Event event;
	bool gameRunning = true;
	int start = SDL_GetTicks();
	//int start2 = start;
	//long long int numFrames = 0;
	while (gameRunning)
	{
		SDL_FillRect(screen , NULL , 0xABCDEF);
		
		//numFrames++;
		while( SDL_PollEvent( &event ) )
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
			gameWorld->updateSprites(event);
		} 
		
		//Draw everything
		gameWorld->drawLevel(screen);
		gameWorld->drawSprites(screen);

		int diff = SDL_GetTicks() - start;
		if(diff < 1000 / FRAMES_PER_SECOND ) { 
			//Sleep the remaining frame time 
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - diff); 
		}
		start = SDL_GetTicks();
		//std::cout << (int)(( numFrames/(float)(SDL_GetTicks() - start2) )*1000) << "\n"; //Apparently gets 62 FPS, so pretty close.
		SDL_Flip(screen);
	}
	SDL_Quit();
	return 0;
}
