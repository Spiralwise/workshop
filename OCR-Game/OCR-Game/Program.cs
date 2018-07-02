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
            Console.WriteLine("---- Denjun ----");
            Console.WriteLine("Votre voyage commence.");
            Player player = new Player();
            Monster opponent;
            int[] killCount = new int[] { 0, 0 };

            while (player.IsAlive)
            {
                if (Dice.Roll() >= 4)
                    opponent = new HardMonster();
                else
                    opponent = new EasyMonster();
                player.Attack(opponent);
                if (!opponent.IsAlive)
                {
                    //Console.WriteLine("Vous avez vaincu votre ennemi !");
                    if (opponent is EasyMonster)
                        killCount[0] += 1;
                    else
                        killCount[1] += 1;
                }
            }

            ShowScore(killCount[0], killCount[1], player.Score);
        }

        static void ShowScore(int easy, int hard, int score)
        {
            ConsoleColor localColor = Console.ForegroundColor;
            Console.Write("You died! During your journey, you killed ");
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.Write(easy + " easy monsters");
            Console.ForegroundColor = localColor;
            Console.Write(" and ");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(hard + " hard monsters");
            Console.ForegroundColor = localColor;
            Console.Write(".");
            Console.ForegroundColor = ConsoleColor.DarkCyan;
            Console.WriteLine("Score: " + score);
            Console.ForegroundColor = localColor;
        }
    }
}
