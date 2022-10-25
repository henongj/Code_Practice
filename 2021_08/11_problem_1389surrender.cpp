/*
	BOJ1389 케빈 베이컨의 6단계 법칙
	
	첫 줄에 사람 수 N | 친구 관계 수 M (2 ~ 100 , 1 ~ 100)
	두 번째 줄에 친구 관계, A B 일 경우 A와 B는 친구
	
	각 친구관계를 통해 서로를 몇 번 만에 갈 수 있는지 세서 누적 합을 구하고
	그 합이 가장 적은 사람의 수를 구하시오.
	
	그래프 문제, 최단거리 노드 연결의 합 값을 넣어서 가장 적은 값이 나오는 사람을 출력할 것.

	해결 방법 vector 2차원 배열을 이용해서 정보를 입력한다. 
	BFS를 이용해서 pop을 할 때마다 카운팅을 하는데 visited check할 배열이 더 필요하다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int kMaximumArrayLength = 101;

template <typename T>
ostream& operator <<(ostream& os, const vector<T>&v)
{
	for(const auto& i : v)
		cout << i << " ";
	cout << "\n";
	return os;
}

template <typename T>
ostream& operator <<(ostream& os, const vector<vector<T>>&v)
{
	for(size_t i = 0 ; i < v.size() ; i++)
	{
		for(const auto& j : v[i])
			cout << j << " ";
		cout << "\n";
	}
	return os;
}

void inputArrayInQueue(vector<vector<int>>& friendRelationship, queue<int>& q, int visitedCheck[] ,int& distanceCounter, int, humanCounting)
{

}
int searchAndDistanceCounting(bool visitedCheck[kMaximumArrayLength] , vector<vector<int>>& friendRelationship, int persons, int index)
{ // index = targetArray , persons 는 목표 인원수

/* 	무차별 탐색을 한다. 방법은 너비우선이다. 
	한 배열을 전부 순회하며 모두 push(방문)한다.
	해당 원소를 방문할 경우 visitedCheck를 한다.
	해당 원소를 방문할 경우 counting을 해서 persons와 같아지면 종료한다.
	해당 원소를 방문할 경우 distance를 더해서 카운팅한다.
	해당 원소를 방문할 경우 몇 번 pop해야하는지 샌다.
*/	
	int distance = 1;
	int iterator = 0;
	int distanceCounter = 0;
	int humanCounting = 0;
	int top = index;
	int popCounter =  friendRelationship[index].size();

	while( !humanCounting == persons ) 
	{ // index에 대한 반복
		bool visitedCheck[persons + 1] = {};
		queue<int> q;
				
		// push all element in a index
		for(int i = 0 ; i < friendRelationship[index].size() ; i++)
		{
			if( visitedCheck[ friendRelationship[index][i] ] == false )
			{// 방문한 적이 없으면 
				q.push_back(friendRelationship[index][i]); //방문
				visitedCheck[ friendRelationship[index][i] ] = true; // visitedCheck
				distanceCounter += distance; // distance counting
				humanCounting++; // humanCounting
				popCounter++;
			}
		}
		
		distance = distance + 1;
		top = q.top();
	}
}


int main(void)
{
	// declration //
	int persons; int numOfRelation;
	
	vector<vector<int>> friendRelationship;
	
	// input data //
	cin >> persons >> numOfRelation;
	for(int i = 0 ; i < persons + 1 ; i++)
	{
		vector<int> v;
		friendRelationship.push_back(v);
	}
	for(int i = 0 ; i< numOfRelation ; i++)
	{
		int friendOne, friendTwo;
		cin >> friendOne >> friendTwo;
		friendRelationship[friendOne].push_back(friendTwo);
		friendRelationship[friendTwo].push_back(friendOne);
	}
	cout << "run 1";
	cout << friendRelationship;
	cout << "run 2";
	//
	
	// BFS
	
	
	
	return 0;
}
