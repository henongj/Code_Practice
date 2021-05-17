using System;
namespace mainSpace
{
	class mainClass
	{
		public static void Main()
		{
			csCode.Code Practice = new csCode.Code();
//			Practice.casting();
			int sumNum = Practice.integerSum(9,2,3,4,5,7,4);
			Console.WriteLine("sumNum : {0}" , sumNum);
		}
	}
}

namespace csCode
{
	public class Code
	{
		public int integerSum(params int[] args)
		{
			int sum = 0;
			foreach (int item in args)
			{
				sum += item;
			}
			return sum;
		}
		
		public void casting()
		{
//			string str = Console.ReadLine();
			int number1 = int.Parse(Console.ReadLine());
			int number2 = int.Parse(Console.ReadLine());
			Console.WriteLine("number1 & number2 ==> {0} & {1} == {2}", number1,number2 , number1&number2);
			int i = 3; int j = 6;
			int t = i & j;
			Console.WriteLine("t is {0} & {1} == {2}", i,j , t);
			
		}
		
	}
}
