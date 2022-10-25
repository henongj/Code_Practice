#include<iostream>
#include<vector>

using namespace std;

void searchRelation(int numOfPeople, const vector<int> v[], int visited[], int relation, int target)
{
	for(int i = 0 ; i < v[target].size() ; i++)
	{//
		if(visited[ v[target][i] ] == 0)
		{ // 방문한 적이 없으면
			visited[ v[target][i] ] = relation;
			searchRelation(numOfPeople, v, visited, relation+1, v[target][i]);
		}
		else //방문한 적이 있으면
			continue;
	}
}

template <typename T>
void printArray(T arr[] , size_t size)
{
	for(size_t i = 0 ; i < size ; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int main(void)
{
	int numOfPeople,targetOne, targetTwo;
	int relation;
	vector<int> v[101];
	int visited[101]={}; //false
	cin >> numOfPeople >> targetOne >> targetTwo;
	cin >> relation;
	
	for(int i = 0 ; i < relation ; i++)
	{ // 1촌을 등록한다
		int son, parent;
		cin >> parent >> son; //
		v[parent].push_back(son); //
		v[son].push_back(parent);
	}
	
//	searchRelation(numOfPeople, v, visited, 1, targetOne);
//	부모를 기준(parent node)으로 하향식으로 탐색해야한다.
	searchRelation(numOfPeople, v, visited, 1, targetTwo);
	
	//printArray(visited,numOfPeople);
	
	visited[targetOne] == 0 ? cout << "-1" : cout << visited[targetOne];
	
	return 0;
}

/*
촌수 : 부모|자식 = 1 , 이동시 1추가
각 vector엔 1촌이 등록되어 있다

1촌을 찾을 때마다 visited에 기록을 한다
기록은 0->counter+1값, N이면 pass

target 의 촌수를 대상으로 탐색한다
v[n][ 0 ~ v[n].size()-1 ]에게는 1을 부여
각 v[n][0] ~ v[n][size()-1] 에게 탐색을 시켜서 2를 준다
주우욱. 돌고 나서 visited 값이 0이면 -1출력
n이면 n출력

input
9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
답 : 3

input
10
1 6
5
5 6
4 5
1 4
5 7
2 3
답 : 3

input
7
4 6
4
1 4
4 5
5 2
2 3
답 : -1
*/
