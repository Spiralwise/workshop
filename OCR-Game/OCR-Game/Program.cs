using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class Program
    {
        static void Main(string[] args)
        {
            ConsoleColor localColor = Console.ForegroundColor;
            Console.WriteLine("---- Denjun ----");
            Console.WriteLine("Votre voyage commence.");
            Player player = new Player(150);
            Monster opponent;
            int[] killCount = new int[] { 0, 0 };
            int score = 0;

            while (player.IsAlive)
            {
                opponent = Monster.Create();
                Console.Write("Vous rencontrez un ");
                Console.ForegroundColor = ConsoleColor.DarkRed;
                Console.Write(opponent.Name);
                Console.ForegroundColor = localColor;
                Console.WriteLine(".");
                while (opponent.IsAlive && player.IsAlive)
                {
                    Console.WriteLine("Vous attaquez !");
                    player.Attack(opponent);
                    if (opponent.IsAlive)
                    {
                        Console.WriteLine(opponent.Name + " attaque !");
                        opponent.Attack(player);
                    }
                    else
                    {
                        Console.WriteLine("Vous avez vaincu le " + opponent.Name + " !");
                        if (opponent is EasyMonster)
                            killCount[0] += 1;
                        else
                            killCount[1] += 1;
                        score += opponent.Score;
                    }
                }
            }

            ShowScore(killCount[0], killCount[1], score);
        }

        static void ShowScore(int easy, int hard, int score)
        {
            ConsoleColor localColor = Console.ForegroundColor;
            Console.Write("Vous avez péri ! Durant votre voyage, vous avez tué ");
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.Write(easy + " easy monsters");
            Console.ForegroundColor = localColor;
            Console.Write(" and ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(hard + " hard monsters");
            Console.ForegroundColor = localColor;
            Console.WriteLine(".");
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("Score: " + score);
            Console.ForegroundColor = localColor;
        }
    }
}
