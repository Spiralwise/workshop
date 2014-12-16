#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main (int argc, char** argv)
{
	SDL_Event event; // This can handle events from SDL.
	SDL_Surface* screen = NULL; // This is the screen, the whole displayable window.
	SDL_Surface* myrect = NULL; // This is juste a rectangle which can be drawn on the screen.
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
	SDL_WM_SetIcon (SDL_LoadBMP("res/sdl_icone.bmp"), NULL);

	// Intro
	Uint32 backcolor = SDL_MapRGB (screen->format, 75, 92, 122); // This is how a color is handled by SDL.
	SDL_FillRect (screen, NULL, backcolor);
	myrect = SDL_CreateRGBSurface (SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0); // This creates a rectangle to be drawn on the screen.
	SDL_Rect position;
	position.x = 200;
	position.y = 150;
	SDL_BlitSurface (myrect, NULL, screen, &position); // This pastes the rectangle onto the screen.

	SDL_Surface* myimage = SDL_LoadBMP ("res/lac_en_montagne.bmp"); // This load an image onto the rectangle.
	position.x = position.y = 0;
	SDL_BlitSurface (myimage, NULL, screen, &position);
	
	SDL_Surface* donkey = SDL_LoadBMP ("res/zozor.bmp");
	position.x = position.y = 200;
	SDL_SetColorKey (donkey, SDL_SRCCOLORKEY, SDL_MapRGB(donkey->format, 0, 0, 255)); // Makes the blue color transparent.
	SDL_SetAlpha (donkey, SDL_SRCALPHA, 192); // Makes alpha
	SDL_BlitSurface (donkey, NULL, screen, &position);

	SDL_Surface* sapin = IMG_Load ("res/sapin.png"); // Load an image with SDL_Image. Thus, it is a PNG and its transparent will be automaticaly enabled.
	position.x = 400;
	SDL_BlitSurface (sapin, NULL, screen, &position);

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
	SDL_FreeSurface (myrect); // All created object must be destroyed!
	SDL_FreeSurface (myimage);
	SDL_FreeSurface (donkey);
	SDL_Quit (); // Fortunatly, SDL destroys itself what it created.

	return EXIT_SUCCESS;
}

