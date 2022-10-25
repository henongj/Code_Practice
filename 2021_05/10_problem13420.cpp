#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long int64;

vector<string> inputInfo(void)
{
	vector<string> v;
	string str;
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	return v;
}

bool isCorrect(vector<string>v)
{
	int64 num1 = stoll(v[0]);
	int64 num2 = stoll(v[2]);
	int64 num3 = stoll(v[4]);
	if(v[1] == "+")
		return num1 + num2 == num3 ? true : false;
	else if(v[1] == "-")
		return num1 - num2 == num3 ? true : false;
	else if(v[1] == "*")
		return num1 * num2 == num3 ? true : false;
	else if(v[1] == "/")
		return num1 / num2 == num3 ? true : false; 
}

int main(void)
{
	int testCase;
	cin >> testCase;
	for(int i = 0 ; i < testCase ; i++)
	{
		vector<string> v = inputInfo();
/*		for(auto i : v)
			cout << i << " ";
		cout << "\n";*/
		isCorrect(v) ? cout << "correct\n" : cout << "wrong answer\n";
	}
	return 0;
}

/* 계산기 문제다

testCase 만큼 식을 간단한 계산하는 문제
tokenizer 로 잘라서 스택에 넣는게 가장 정석이지만
식이 단순하고, 확인을 받아야 하므로 심플한 방법을 쓴다.

atoi 함수 써서 심플하게 간다

4
3 * 2 = 6
11 + 11 = 11
7 - 9 = -2
3 * 0 = 0

correct
wrong answer
correct
correct

*/
