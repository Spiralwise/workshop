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
        }

        public override int Attack()
        {
            int damage = 0;
            if (Dice.ThrowDice() > Dice.ThrowDice() && Dice.ThrowDice() > 2)
                damage = 10;
            int magicAttack = Dice.ThrowDice();
            if (magicAttack < 6)
                damage = 5 * magicAttack;
            return damage;
        }
    }
}
