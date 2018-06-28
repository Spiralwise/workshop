using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    static class Dice
    {
        static Random random = new Random();

        static public int ThrowDice()
        {
            return random.Next(1, 7);
        }
    }
}
