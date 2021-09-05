#include<iostream>
#include<iomanip>
#include<random>
#include<map>
// use random 
using namespace std;

int main(void)
{
	random_device rd; // random_device 객체를 이용해 
	mt19937 gen(rd()); // 난수 생성 엔진 객체를 정의한다 , rd 대신 아무 숫자나 넣어도 된다
	
	
/*	// 어디에서 수를 생성하는지 정해야 한다. 균등분포(uniform distribution) 0 ~ 99일 경우
	int start = 'A';
	int end = 'z';
	uniform_int_distribution<int> dis( start, end ); 
	
	// 그리고 그 범위의 난수를 10번 출력할 수 있음
	for(int i = 0 ; i < 10 ; i++)
		cout << "난수(문자 cast) : " << (char)dis(gen) << "\n";
*/
	
// 정규분포(normal distribution)의 경우
	
	int average = 0; int standard_deviation = 10; // 평균값과 표준편차, 표준편차를 늘리면 표본이 늘어남(왜??)
	normal_distribution<double> dist( average , standard_deviation ); // 선언(평균, 표준편차)

	map<int, int> hist{}; // 
	for (int n = 0; n < 10000; ++n) { // 10000개의 샘플을 무작위로 뽑음
  		++hist[std::round(dist(gen))];
	}
	for (auto p : hist) {
  		cout << setw(2) << p.first << ' ' << std::string(p.second / 100, '*') << " " << p.second << '\n';
  	}
	return 0;
}
