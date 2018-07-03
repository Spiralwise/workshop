using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    abstract class Monster
    {
        protected string m_name = "monstre";
        protected int m_damage = 10;
        protected int m_life = 1;

        public string Name { get; protected set; }

        public int Score { get; protected set; }

        public bool IsAlive
        {
            get { return m_life > 0; }
        }

        public Monster() { }

        static public Monster Create()
        {
            if (Dice.Roll() <= 3)
                return new EasyMonster();
            else
                return new HardMonster();
        }

        public abstract void Attack(Player player);

        public void Hurt(int damage)
        {
            m_life -= damage;
        }
    }
}
