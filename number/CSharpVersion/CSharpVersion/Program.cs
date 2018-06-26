using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpVersion
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();

            // Intro
            Console.WriteLine("SYSTEM LOG IN...");
            Console.WriteLine("OPENOS INITIALIZING...");
            Console.WriteLine("Hello ! Vous allez deviner à quel nombre je pense ! (Oui, les ordinateurs pensent...)");

            // Boucle principale
            do
            {
                Console.WriteLine("Choisissez une niveau de difficulté");
                Console.WriteLine("1 - Entre 1 et 100");
                Console.WriteLine("2 - Entre 1 et 1000");
                Console.WriteLine("3 - Entre 1 et 10000 !");

                // Initialisation du jeu
                int target, MAX_VALUE;
                int trials = 0, minBound, maxBound;

                ConsoleKeyInfo difficulty = Console.ReadKey(true);
                switch (difficulty.Key)
                {
                    case ConsoleKey.D1:
                    case ConsoleKey.NumPad1:
                        MAX_VALUE = 100;
                        Console.WriteLine("Woaw... T'as peur de te fouler un neurone ?");
                        break;

                    case ConsoleKey.D2:
                    case ConsoleKey.NumPad2:
                        MAX_VALUE = 1000;
                        Console.WriteLine("Je ne serais pas aussi méchant que HAL, promis.");
                        break;

                    case ConsoleKey.D3:
                    case ConsoleKey.NumPad3:
                        MAX_VALUE = 10000;
                        Console.WriteLine("Tu as déjà entendu parlé de Deep Blue ?");
                        break;

                    default:
                        MAX_VALUE = 100000000;
                        Console.WriteLine("Je vois qu'on essaie de tricher ! Voilà une difficulté bien spécial ! Bienvenue dans la matrice ! >:D");
                        break;
                }
                target = 1 + rand.Next(MAX_VALUE);
                minBound = 1;
                maxBound = MAX_VALUE;

                // Boucle de jeu
                Console.WriteLine("Allez ! C'est parti !");
                int userNumber;
                do
                {
                    Console.WriteLine("C'est entre " + minBound + " et " + maxBound + ".");
                    Console.Write("> ");
                    if (int.TryParse(Console.ReadLine(), out userNumber))
                    {
                        if (userNumber > MAX_VALUE || userNumber < 1)
                        {
                            Console.WriteLine("T'es sérieux ?");
                        }
                        else if (userNumber > target)
                        {
                            if (maxBound > userNumber)
                                maxBound = userNumber;
                            Console.WriteLine("C'est moins...");
                        }
                        else if (userNumber < target)
                        {
                            if (minBound < userNumber)
                                minBound = userNumber;
                            Console.WriteLine("C'est plus !");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Les humains. Si fragile. Ça te comptera comme un coup !");
                    }
                    ++trials;
                }
                while (userNumber != target);

                // Fin de partie
                if (trials > 1)
                    Console.WriteLine("Bravo ! Tu as trouvé mon nombre fétiche en " + trials + " coups !");
                else
                    Console.WriteLine("Woaw ! Tu as deviné mon nombre du premier coup ! Tu es un ordinateur, toi aussi ?");
                Console.WriteLine("Voulez-vous refaire une partie ? (o/n) (dis oui, dis oui, steup!)");
            }
            while (Console.ReadKey(true).Key == ConsoleKey.O);

            Console.WriteLine("C'était sympa, faudra revenir !\nSYSTEM LOG OUT\n");
            Console.Write("Press any key to exit...");
            Console.ReadKey(true);
        }
    }
}
