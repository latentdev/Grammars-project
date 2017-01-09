
using System;
namespace HelloWorld
{
	class Hello
	{
		static void Main()
		{
			int x = 0;
			x++;
			x=x+x;
			Console.WriteLine("Hello World!");
			Console.WriteLine("Press any key to exit.");
			Console.ReadKey();
			x++;
		}
	}
}