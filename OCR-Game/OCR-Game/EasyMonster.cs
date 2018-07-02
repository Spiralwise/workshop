using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class EasyMonster : Monster
    {
        public EasyMonster() : base(1)
        {
            Console.WriteLine("Vous rencontrez un petit troll.");
        }

        public override int Attack()
        {
            if (Dice.Roll() > Dice.Roll() && Dice.Roll() > 2)
                return 10;
            else
                return 0;
        }
    }
}
