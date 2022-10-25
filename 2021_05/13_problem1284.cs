using System;
namespace mainSpace
{
	class mainClass
	{
		public static void Main()
		{
			boj.problem1284.code();
		}
	}
}

namespace boj
{
	public class problem1284
	{
		public static void code()
		{
			string number;
			while(true)
			{
				number = Console.ReadLine();
				if(number == "0")
					break;
				int basicBlank = 1 + number.Length;
				int blankStack = 0;
				for(int i = 0 ; i < number.Length ; i++)
				{
					if(number[i] == '1')
						blankStack += 2;
					else if(number[i] == '0')
						blankStack += 4;
					else
						blankStack += 3;
				}
				Console.WriteLine(basicBlank + blankStack);
			}
		}
	}
}
