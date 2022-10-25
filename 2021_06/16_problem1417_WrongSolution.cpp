#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
T abs(T a, T b)
{
	return a > b ? a - b : b - a;
}
int main(void)
{
	double counter = 0;
	double average = 0; // 합도 동시에 저장
	int numOfValue;
	int daSom;
	cin >> numOfValue;
	cin >> daSom;
	for(int i = 0 ; i < numOfValue - 1 ; i++)
	{//daSom 보다 많은 표를 받는 사람들의 수와 표의 합을 저장한다
		int t;	cin >> t;
		if( daSom <= t)
		{
			counter = counter + 1;
			average += t;
		}
	}
	average = ceil(average / counter); // 평균을 구하고
	average = static_cast<int>(average);
	if(numOfValue == 1)
		cout << 0;
	else if(daSom == average) // 예를들어 input 2 4 4 라면?
		cout << 1;
	else
	{
		cout << average - daSom;
	}
	return 0;
}



/*
greedy 선거
국회의원 후보 N명 // M명의 주민이 선거한다
기호 1번을 매수해서 당선되게 하려고 한다.
당선기준 == 모든 사람의 득표수 보다 많은 득표수를 가질 때
즉 5 7 6 7 -> 7 6 6 6 으로 2, 4번 후보 뽑는사람 1명씩 매수하면 됨

매수해야하는 사람이 최솟값이 되게 프로그램을 작성

N은 1000 이하 자연수 M은 1000이하 자연수

input
3
5
7
7
output
2

input
5
7
4
11
9
10
output : 3

풀이 : input값 중 1번 값보다 큰 것의 평균값을 낸다
그리고 그 값의 올림값과 1번값의 차가 정답이다.
2번 예시 11 + 9 + 10 / 3 == 10 ( 11 - 2 , 9 , 10 -1 이고 7 + 3 매수 끝)
*/
