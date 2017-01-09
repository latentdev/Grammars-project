using System;

namespace Parse
{
    class Program
    {
        static void Main(string[] args)
        {
            Boolean Switch = true;
            InOut x = new InOut();
            while (Switch){
                x.output();
                if (x.getCount()>10)
                {
                    Switch = false;
                }

            }

        }
    }
}
