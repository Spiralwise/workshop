#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


int main (int argc, char** argv)
{
	SDL_Event event;
	SDL_Surface* screen = NULL;
	SDL_Surface* myrect = NULL;
	int running = 1;

	// Initialization
	if (SDL_Init (SDL_INIT_VIDEO))
	{
		fprintf (stderr, "E: SDL not initialized. %s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode (640, 480, 32, SDL_HWSURFACE);
	if (screen == NULL)
	{
		fprintf (stderr, "E: Can't set this video mode : %s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	SDL_WM_SetCaption ("Mini SDL", NULL);

	// Intro
	Uint32 backcolor = SDL_MapRGB (screen->format, 75, 92, 122);
	SDL_FillRect (screen, NULL, backcolor);
	myrect = SDL_CreateRGBSurface (SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
	SDL_Rect position;
	position.x = 200;
	position.y = 150;
	SDL_BlitSurface (myrect, NULL, screen, &position);

	// Loop
	while (running)
	{
		SDL_WaitEvent (&event);
		SDL_Flip (screen);
		switch (event.type)
		{
			case SDL_QUIT: running = 0; break;
		}
	}

	// Extro
	SDL_FreeSurface (myrect);
	SDL_Quit ();

	return EXIT_SUCCESS;
}

