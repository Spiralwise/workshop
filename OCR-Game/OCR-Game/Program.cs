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
            Console.WriteLine("---- Start ----");
            Player player = new Player();
            Monster opponent;
            int[] killCount = new int[] { 0, 0 };

            while (player.IsAlive)
            {
                if (Dice.ThrowDice() >= 4)
                    opponent = new HardMonster();
                else
                    opponent = new EasyMonster();
                player.Attack(opponent);
                if (!opponent.IsAlive)
                {
                    if (opponent is EasyMonster)
                        killCount[0] += 1;
                    else
                        killCount[1] += 1;
                }
            }

            Console.WriteLine("You died! During your journey, you killed " + killCount[0] + " easy monsters and " + killCount[1] + " hard monsters.");
            Console.WriteLine("Score: " + player.Score);
        }
    }
}
