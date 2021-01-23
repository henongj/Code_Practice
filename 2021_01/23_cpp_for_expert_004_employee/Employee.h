#pragma once
#include<string>

namespace Records{
	
	const int kDefalueSalary = 30000;
	
	class Employee
	{
		public:
		Employee() = default;
		Employee(const std::string& firstName, const std::string& lastName);
		
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); //채용 or 재임용
		void fire(); // 해고 
		void display() const; //직원 정보를 콘솔에 출력
		
		//게터와 세터
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;
		
		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;
		
		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;
		
		void setSalary(int newSalary);
		int getSalary() const;
		
		bool isHired() const;
		
		private:
		std::string mFirstName();
		std::string mLastName();
		int mEmployeeNumber = -1;
		int mSalary = kDefalueSalary;
		bool mHired = false;
			
	};
}
	
