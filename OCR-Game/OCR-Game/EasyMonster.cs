using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class EasyMonster : Monster
    {
        public EasyMonster() : base()
        {
            Name = "troll";
            Score = 1;
        }

        public override void Attack(Player player)
        {
            if (Dice.Roll() > Dice.Roll())
                player.Hurt(m_damage);
        }
    }
}
