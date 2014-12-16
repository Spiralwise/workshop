#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <fmodex/fmod.h>


int main (int argc, char** argv)
{
	SDL_Event event; // This can handle events from SDL.
	SDL_Surface* screen = NULL; // This is the screen, the whole displayable window.
	SDL_Surface* myrect = NULL; // This is juste a rectangle which can be drawn on the screen.
	SDL_Surface* donkey = NULL; 
	SDL_Rect donkey_pos;
	SDL_Surface* sapin = NULL;
	SDL_Rect sapin_pos; 
	FMOD_SOUND* beep = NULL;
	int running = 1;

	// Initialization
	if (SDL_Init (SDL_INIT_VIDEO))
	{
		fprintf (stderr, "E: SDL not initialized. %s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode (640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	if (screen == NULL)
	{
		fprintf (stderr, "E: Can't set this video mode : %s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	SDL_WM_SetCaption ("Mini SDL", NULL);
	SDL_WM_SetIcon (SDL_LoadBMP("res/sdl_icone.bmp"), NULL);
	SDL_EnableKeyRepeat (10, 10);
	
	FMOD_SYSTEM *fmod; // This is for the sound.
	FMOD_System_Create (&fmod);
	FMOD_System_Init (fmod, 2, FMOD_INIT_NORMAL, NULL);

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
	
	donkey = SDL_LoadBMP ("res/zozor.bmp");
	SDL_SetColorKey (donkey, SDL_SRCCOLORKEY, SDL_MapRGB(donkey->format, 0, 0, 255)); // Makes the blue color transparent.
	SDL_SetAlpha (donkey, SDL_SRCALPHA, 192); // Makes alpha
	donkey_pos.x = screen->w / 2 - donkey->w / 2;
	donkey_pos.y = screen->h / 2 - donkey->h / 2;

	sapin = IMG_Load ("res/sapin.png"); // Load an image with SDL_Image. Thus, it is a PNG and its transparent will be automaticaly enabled.
	sapin_pos.x = 300;
	sapin_pos.y = 150;

	FMOD_System_CreateSound (fmod, "k_tone.wav", FMOD_CREATESAMPLE, 0, &beep); // This loads a sound.
	FMOD_System_PlaySound (fmod, FMOD_CHANNEL_FREE, beep, 0, NULL); // This plays a sound.
		
	// Loop
	while (running)
	{
		// Handle events
		SDL_WaitEvent (&event);
		switch (event.type)
		{
			case SDL_QUIT: running = 0; break;
			case SDL_KEYDOWN: switch (event.key.keysym.sym) // This handles keyboard events.
				{
					case SDLK_ESCAPE: running = 0; break;
					case SDLK_UP: donkey_pos.y--; break;
					case SDLK_DOWN: donkey_pos.y++; break;
					case SDLK_RIGHT: donkey_pos.x++; break;
					case SDLK_LEFT: donkey_pos.x--; break;
				}
				break;
			case SDL_MOUSEBUTTONUP: // This handles mouse events.
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					sapin_pos.x = event.button.x - sapin->w / 2;
					sapin_pos.y = event.button.y - sapin->h / 2;
				}
				break;
		}

		// Draw
		SDL_FillRect (screen, NULL, backcolor);
		SDL_BlitSurface (donkey, NULL, screen, &donkey_pos);
		SDL_BlitSurface (sapin, NULL, screen, &sapin_pos);

		// Swap buffer
		SDL_Flip (screen);
	}

	// Extro
	SDL_FreeSurface (myrect); // All created object must be destroyed!
	SDL_FreeSurface (myimage);
	SDL_FreeSurface (donkey);
	FMOD_Sound_Release (beep);
	FMOD_System_Close (fmod);
	FMOD_System_Release (fmod);
	SDL_Quit (); // Fortunatly, SDL destroys itself what it created.

	return EXIT_SUCCESS;
}

