using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BonWeekend
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintGreetings(DateTime.Now);
            PrintGreetings(new DateTime(2018, 6, 24, 12, 0, 0));
            PrintGreetings(new DateTime(2018, 6, 25, 20, 30, 0));
            PrintGreetings(new DateTime(2018, 6, 29, 19, 30, 0));
        }

        static void PrintGreetings(DateTime d)
        {
            Console.WriteLine(GetGreetings(d) + " " + Environment.UserName);
        }

        static string GetGreetings(DateTime d)
        {
            if (d.DayOfWeek == DayOfWeek.Saturday || d.DayOfWeek == DayOfWeek.Sunday
                || d.DayOfWeek == DayOfWeek.Monday && d.Hour < 9
                || d.DayOfWeek == DayOfWeek.Friday && d.Hour >= 18)
                return "Bon week-end";

            else if (d.Hour >= 9 && d.Hour < 18)
                return "Bonjour";

            else
                return "Bonsoir";
        }
    }
}
