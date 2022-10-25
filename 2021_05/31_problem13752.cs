using System;
namespace mainSpace
{
	class MainContainer
	{
		static void Main(string[] arguments)
		{
//			
			boj13752.Code code = new boj13752.Code();
			code.Answer();
			
		}
	}
}
namespace boj13752
{
	public class Code
	{
		public void Answer()
		{
			string temp = Console.ReadLine();
			int times = Convert.ToInt32(temp);
			char t = '=';
			for(int i = 0 ; i < times ; i++)
			{
				string data = Console.ReadLine();
				int n = Convert.ToInt32(data);
				for(int j = 0 ; j < n ; j++)
					Console.Write("{0}" , t);
				Console.WriteLine("");
			}
		}
	}
}
