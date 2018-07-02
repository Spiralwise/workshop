using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    abstract class Monster
    {
        public bool IsAlive { get; private set; }
        public int Score { get; private set; }

        public Monster(int value)
        {
            IsAlive = true;
            Score = value;
        }

        public abstract int Attack();

        public void Kill()
        {
            IsAlive = false;
        }
    }
}
