using System;
namespace mainSpace
{
	class mainClass
	{
		static void Main()
		{
			int[] chess = new int[6]{1,1,2,2,2,8};
			int[] blackPiece = new int[6];
			for(int i = 0 ; i < 6 ; i++)
			{
				string str = Console.Read();
				Console.WriteLine("str : {0}",str);
				blackPiece[i] = Convert.ToInt32(str);
				blackPiece[i] = blackPiece[i] - chess[i];
			}
			
			foreach(int i in blackPiece)
			{
				Console.Write("{0} ",i);
			}
			
		}
	}
}

