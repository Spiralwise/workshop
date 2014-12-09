#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Vecteur contenant l'ensemble du dictionnaire chargé
vector<string> words;
// Mot à trouver
string game_word;
// Mot à trouver mélangé (pour l'affichage)
string scrambled_word;
// Nombre d'essais maximal
const int max_life = 5;
// Nombre d'essais restant
int life;
// Entrée utilisateur
string user_input;


// Charge le dictionnaire de mots à partir d'un fichier texte.
// Si le dictionnaire n'a pu être chargé, l'application est interrompue.
bool loadDictionnary (const string& filename)
{
	ifstream file (filename.c_str());
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			words.push_back (line);
			// Retire le carriage return (dû au format Windows d'origine)
			if (words.back()[words.back().size()-1] == '\r')
				words.back().erase(words.back().size()-1);
		}
		file.close ();
		return true;
	}
	else
	{
		cout << "E: An error occured whle opening dictionnary file." << endl;
		return false;
	}
}


// Renvoie la forme mélangée du mot donné en paramètre.
string scrambleWord (string word)
{
	string result = "";
	int selected_letter;
	while (word.length() > 0)
	{
		selected_letter = rand() % word.length();
		result += word[selected_letter];
		word.erase (selected_letter, 1);
	}
	return result;
}


// Convertit les minuscules d'un mot en majuscule.
string upperCase (string word)
{
	string result = "";
	for (int i = 0; i < word.length(); i++)
		if (word[i] >= 'a')
			result += word[i] - (char)32;
		else
			result += word[i];
	return result;
}


int main (int argc, char** argv)
{
	// Initialisation
	string dic_to_load = "easy.dic";
	if (argc == 2)
		dic_to_load = string(argv[1]);

	if (loadDictionnary (dic_to_load))
		cout << "Le dictionnaire " << dic_to_load << " a été chargé." << endl;
	else
	{
		cout << "Un problème est survenu pendant le chargement du dictionnaire " << dic_to_load << " ! L'application va se terminer." << endl;
		return 1;
	}
	srand (time(NULL));

	// Boucle de partie
	do
	{
		// Génération de la partie
		game_word      = words[rand() % words.size()];
		scrambled_word = scrambleWord (game_word);
		life           = max_life;
		user_input     = "";

		// Boucle principale
		cout << "Devinez le mot mystère !" << endl;
		do
		{
			cout << scrambled_word << "? > ";
			cin >> user_input;
			user_input = upperCase (user_input);
			if (user_input != game_word)
			{
				life--;
				if (life == 0)
					cout << "Dommage. Vous avez perdu. Le mot à trouver était " << game_word << "." << endl;
				else
					cout << "Ce n'est pas le bon mot, essayez encore. Il vous reste " << life << " essais." << endl;
			}
			else
				cout << "Vous avez devinez le mot mystère ! GG !" << endl;
		} while (life > 0 && user_input != game_word);

		cout << "Voulez-vous faire une autre partie ? (o/n) > ";
		cin >> user_input;

	} while (user_input == "o" || user_input == "O");

	cout << "Merci d'avoir joué ! Au revoir !" << endl;

	return 0;
}

