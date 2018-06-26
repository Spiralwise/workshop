using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCR_Loto
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> tirages = GenerateTirage();
            PrintTirage(tirages);
        }

        static List<int> GenerateTirage()
        {
            Random rand = new Random();
            List<int> tirages = new List<int>();

            int tirage;
            while (tirages.Count < 7)
            {
                tirage = 1 + rand.Next(49);
                if (tirages.IndexOf(tirage) == -1)
                    tirages.Add(tirage);
            }
            tirages.Sort();
            return tirages;
        }

        static void PrintTirage(List<int> l)
        {
            foreach (int x in l)
                Console.WriteLine(x);
        }
    }
}
