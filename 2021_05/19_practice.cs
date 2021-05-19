using System;
namespace mainSpace
{
	struct Student
	{
		public int id;
		public string name;
	}
	class containMain
	{ 
		static void printStudent(Student a)
		{
			Console.WriteLine("학번 : {0} \n이름 : {1}",a.id,a.name);
		}
		public static void Main()
		{
			Student militaryServiceMan;
			militaryServiceMan.id = 20174475;
			militaryServiceMan.name = "구닌";
			mainSpace.containMain.printStudent(militaryServiceMan);
		}

	}
	
}
