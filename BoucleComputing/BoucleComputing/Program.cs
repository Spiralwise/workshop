using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoucleComputing
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Sum(1, 10));
            Console.WriteLine(Sum(1, 100));

            List<double> list = new List<double> { 1.0, 5.5, 9.9, 2.8, 9.6 };
            Console.WriteLine(Mean(list));

            Console.WriteLine(Special());
            Console.WriteLine(Special2());
        }

        static int Sum(int min, int max)
        {
            int ans = 0;
            for (int i = min; i <= max; ++i)
                ans += i;
            return ans;
        }

        static double Mean(List<double> list)
        {
            return list.Sum() / list.Count;
        }

        static int Special()
        {
            List<int> three = new List<int>();
            for (int i = 3; i <= 100; i += 3)
                three.Add(i);

            List<int> five = new List<int>();
            for (int i = 5; i <= 100; i += 5)
                five.Add(i);

            int ans = 0;
            int idx_three = 0, idx_five = 0;
            while (idx_three < three.Count && idx_five < five.Count)
            {
                if (three[idx_three] == five[idx_five])
                {
                    ans += three[idx_three];
                    ++idx_three;
                    ++idx_five;
                }
                else if (three[idx_three] > five[idx_five])
                {
                    ++idx_five;
                }
                else
                {
                    ++idx_three;
                }
            }
            return ans;
        }

        static int Special2()
        {
            int ans = 0;
            for (int i = 1; i <= 100; ++i)
                if (i % 3 == 0 && i % 5 == 0)
                    ans += i;
            return ans;
        }
    }
}
