using System;
namespace mainSpace
{
	class mainClass
	{
		public static void Main()
		{
			boj2010.code.answer();
		}
	}
}
namespace boj2010
{
	public class code
	{
		public static void answer()
		{
			string s = Console.ReadLine();
			int looper = Convert.ToInt32(s);
			int maxPlug = 1 - looper;
			for(int i = 0 ; i < looper ; i++)
			{
				string a = Console.ReadLine();
				maxPlug += Convert.ToInt32(a);
			}
			
			Console.WriteLine("{0}",maxPlug);
		}
	}
}
