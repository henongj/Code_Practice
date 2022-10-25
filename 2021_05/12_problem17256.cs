using System;

namespace mainSpace
{
	class mainClass
	{
		public static void Main()
		{
			boj17256.CsCode.answer();
		}
	}
}

namespace boj17256
{
	public class CsCode
	{
		public static void answer(){
			
			// aCakeB = a.z + b.x, a.y × b.y, a.x + b.z
			string cakeA = Console.ReadLine();
			string[] splitedCakeA = cakeA.Split(new string[] {" "}, StringSplitOptions.None);
			string cakeC = Console.ReadLine();
			string[] splitedCakeC = cakeC.Split(new string[] {" "},StringSplitOptions.None);
			int bX = Convert.ToInt32(splitedCakeC[0]) - Convert.ToInt32(splitedCakeA[2]);
			int bY = Convert.ToInt32(splitedCakeC[1]) / Convert.ToInt32(splitedCakeA[1]);
			int bZ = Convert.ToInt32(splitedCakeC[2]) - Convert.ToInt32(splitedCakeA[0]);
	
			Console.WriteLine("{0} {1} {2}",bX,bY,bZ);

		}
	}
}
