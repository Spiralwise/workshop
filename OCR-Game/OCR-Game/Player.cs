using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class Player
    {
        private int damage = 10;

        public int Life { get; private set; }

        public bool IsAlive
        {
            get { return Life > 0; }
        }

        public Player(int life)
        {
            Life = life;
        }

        public void Attack(Monster monster)
        {
            if (Dice.Roll() >= Dice.Roll())
                monster.Hurt(damage);
        }

        public void Hurt(int damage)
        {
            if (!Shield())
                Life -= damage;
        }

        private bool Shield()
        {
            return Dice.Roll() <= 2;
        }
    }
}
