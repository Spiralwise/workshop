using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    abstract class Monster
    {
        int m_life;

        public bool IsAlive
        {
            get
            {
                return m_life > 0;
            }
        }

        public int Score { get; private set; }

        public Monster(int value)
        {
            m_life = 1;
            Score = value;
        }

        public abstract int Attack();

        public void Kill()
        {
            m_life = 0;
        }
    }
}
