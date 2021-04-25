using System;
namespace Practice
{
	public class One
	{
		public static void arrayPractice()
		{
			int[] arr = new int[30];
			for(int i = 0 ; i < 30 ; i++)
				arr[i] = i;
			Console.WriteLine("Rank 와 Length 는 Property 입니다. 메소드가 아닙니다.");
			Console.WriteLine("배열이 몇 차원인지는 .Rank를 쓰면 됩니다\n	arr's Rank : {0}", arr.Rank);
			Console.WriteLine("배열의 길이는 .Length를 쓰면 됩니다\n	arr's Length : {0}\n", arr.Length);
			
			Console.WriteLine("Use foreach foreach는 reserved Word다");
			foreach(int i in arr)
			{// foreach 는 예약어
				arr[i] = i + 31;
				Console.Write("{0,3}",arr[i]);
			}
			
			int searchIndex = Array.IndexOf(arr , 44);
			Console.WriteLine("\nUse Array.indexOf(arr , 44)\n	arr in 44's index is : {0}",searchIndex);
			
			
		}
	}
}
