
namespace boj
{
	public class problem3058
	{
		public static void code(){
			int testCase = Convert.ToInt32(Console.ReadLine());
			for(int i = 0 ; i < testCase ; i++)
			{
				int minimum = 1000;
				int sum = 0;
				string s = Console.ReadLine();
				string[] str = s.Split(new string[] {" "} , StringSplitOptions.None);
				for(int j = 0 ; j < 7 ; j++)
				{
					int temp = Convert.ToInt32(str[j]);
					if( isEven(temp) )
					{
						sum += temp;
						minimum = pickSmaller( minimum , temp );
					}
				}
				
				Console.WriteLine("{0} {1}",sum , minimum);
			}
		}
		public static int pickSmaller(int a, int b)
		{s
			return a <= b ? a : b;
		}
		public static bool isEven(int a)
		{
			return (a & 1) == 1 ? false : true;
		}
		
	}
}
