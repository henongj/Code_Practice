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


/*
int BFS(bool visitedCheck[kMaximumArrayLength] , vector<vector<int>>& friendRelationship)
{
	bool visitedCheck[kMaximumArrayLength] = {};
}
*/

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
	
	
	
	return 0;
}
