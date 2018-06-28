using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Game
{
    class Player
    {
        public int Life { get; private set; }
        public int Score { get; private set; }

        public bool IsAlive
        {
            get
            {
                return Life > 0;
            }
        }

        public Player()
        {
            Life = 150;
        }

        public void Attack(Monster monster)
        {
            while (monster.IsAlive && this.IsAlive)
            {
                if (Dice.ThrowDice() >= Dice.ThrowDice())
                {
                    monster.Kill();
                    Score += monster.Score;
                }
                else if (Dice.ThrowDice() < 6)
                {
                    Life -= monster.Attack();
                }
            }
        }
    }
}
