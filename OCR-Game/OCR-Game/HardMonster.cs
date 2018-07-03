using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class HardMonster : Monster
    {
        private int m_damageMagic = 5;

        public HardMonster() : base()
        {
            Name = "ogre";
            Score = 2;
        }

        public override void Attack(Player player)
        {
            if (Dice.Roll() > Dice.Roll())
                player.Hurt(m_damage);
            player.Hurt(MagicAttack());
        }

        private int MagicAttack()
        {
            int damage = 0;
            int magicAttack = Dice.Roll();
            if (magicAttack < 6)
                damage = m_damageMagic * magicAttack;
            return damage;
        }
    }
}
