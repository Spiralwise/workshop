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
        }

        public override int Attack()
        {
            if (Dice.ThrowDice() > Dice.ThrowDice() && Dice.ThrowDice() > 2)
                return 10;
            else
                return 0;
        }
    }
}
