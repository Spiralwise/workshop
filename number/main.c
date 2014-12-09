#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Paramètres du jeu
int MAX_VALUE;
int MIN_VALUE = 1;
int difficulty; // Difficulté du jeu

// Variables du jeu
int hiddenNumber; // Nombre à deviner
int userNumber; // Nombre donné par le joueur
int coups; // Nombre de coups effectués par le joueur pour deviner le nombre
char userInput; // Entrée utilisateur autre qu'un nombre
int minBound, maxBound; // Indique les bornes min et max dans lequel trouver le nombre

int main (int argc, char** argv)
{
	// Intro
	printf ("SYSTEM LOG IN ...\n");
	printf ("OPENOS INITIALIZING...\n");
	printf ("Hello ! Vous allez deviner à quel nombre je pense ! (Oui, les ordinateurs pensent...)\n");

	// Boucle principale
	do
	{
		printf ("Choisissez un niveau de difficulté\n");
		printf ("1 - Entre 1 et 100\n");
		printf ("2 - Entre 1 et 1000\n");
		printf ("3 - Entre 1 et 10000 !\n");
		printf ("> ");
		scanf ("%d", &difficulty);

		// Initalisation du jeu
		srand (time(NULL));
		switch (difficulty)
		{
			case 1: MAX_VALUE = 100;
				printf ("Woaw... T'as peur de te fouler un neurone ?\n");
				break;
			case 2: MAX_VALUE = 1000;
				printf ("Je ne serais pas aussi méchant que HAL, promis.\n");
				break;
			case 3: MAX_VALUE = 10000;
				printf ("Tu as déjà entendu parlé de Deep Blue ?\n");
				break;
			default: printf ("Je vois qu'on essaie de tricher ! Voilà une difficulté bien spécial ! Bienvenue dans la matrice ! >:D\n");
				MAX_VALUE = 100000000;
		}
		hiddenNumber = rand() % (MAX_VALUE+1 - MIN_VALUE) + MIN_VALUE;
		minBound     = 0;
		maxBound     = MAX_VALUE;
		coups        = 0;

		// Boucle du jeu
		printf ("Allez ! C'est parti !\n");
		char c;
		do
		{
			while ((c = getchar()) != EOF && c != '\n'); // Petite astuce du dimanche pour vider scanf si le format entrée est incorrect.
			printf ("> ");
			scanf ("%d", &userNumber);
			if (userNumber > MAX_VALUE || userNumber < MIN_VALUE)
				printf ("T'es sérieux ? ");
			if (userNumber > hiddenNumber)
			{
				if (maxBound > userNumber)
					maxBound = userNumber;
				printf ("C'est moins...\n");
			}
			else if (userNumber < hiddenNumber)
			{
				if (minBound < userNumber)
					minBound = userNumber;
				printf ("C'est plus !\n");
			}
			coups++;
			printf ("C'est entre %d et %d.\n", minBound, maxBound);
		}
		while (userNumber != hiddenNumber);
		if (coups > 1)
			printf ("Bravo ! Tu as trouvé mon nombre fétiche en %d coups !\n", coups);
		else
			printf ("Woaw ! Tu as deviné mon nombre du premier coup ! Tu es un ordinateur, toi aussi ?\n");

		// Fin de partie
		printf ("Voulez-vous refaire une partie ? (o/n) (dis oui, dis oui, steup!) > ");
		scanf ("%s", &userInput);//TODO PAsse au travers...
	}
	while (userInput == 'o' || userInput == 'O');

	printf ("C'était sympa, faudra revenir !\nSYSTEM LOG OUT\n");
	return 0;
}

