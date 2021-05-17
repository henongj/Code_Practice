using System;
namespace mainSpace
{
	class mainClass
	{
		public static void Main()
		{
			Practice.Code csCode = new Practice.Code();
			csCode.PrintMessage(3,"대충 메세지");
			csCode.PrintMessage(userMessage : "순서 바꿔서 파라메터 전달", number : 7);
			var code = new Practice.Code();
			code.PrintMessage(4,"var 써보기");
		}
	}
}

using System;

namespace Practice
{
	public class Code
	{
		public void PrintMessage(int number , string userMessage)
		{
			Console.WriteLine("{0} : {1}",number,userMessage);
		}
	}
}
