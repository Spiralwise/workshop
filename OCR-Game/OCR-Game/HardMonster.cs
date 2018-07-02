using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class HardMonster : Monster
    {
        public HardMonster() : base(2)
        {
            Console.WriteLine("Vous rencontrez un ogre.");
        }

        public override int Attack()
        {
            int damage = 0;
            if (Dice.Roll() > Dice.Roll() && Dice.Roll() > 2)
                damage = 10;
            int magicAttack = Dice.Roll();
            if (magicAttack < 6)
                damage = 5 * magicAttack;
            return damage;
        }
    }
}
