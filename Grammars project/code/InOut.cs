using System;

namespace Parse
{
    public class InOut
    {
        int count;
        public InOut()
        {
            count = 0;
        }

        public string input()
        {
            Console.Write("Please enter some text: ");
            count++;
            return Console.ReadLine();
        }

        public void output()
        {
            count++;
            Console.WriteLine(input() + " Lines: " + count);
        }

        public int getCount()
        {
            return count;
        }
    }
}
