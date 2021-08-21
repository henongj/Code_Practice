#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

노드가 N 이면 간선은 N-1 만 있으면 된다

모든 노드의 간선(edge)을 오름차순 정렬해서(최소 비용부터) 연결시키는 것이 기본인 알고리즘
단, cycle이 생기면 안 됨

Union-Find 알고리즘 정보를 기반으로 함

*/

int getParent(int parent[], int x) 
{
	if(parent[x] == x) 
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	a < b ? parent[b] = a : parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	return a == b ? 1 : 0;
}

class Edge
{
	public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance)
	{
		this->node[0] = a; // 연결되는 노드 1
		this->node[1] = b; // 연결되는 노드 2
		this->distance = distance;
	}
	
	bool operator <(Edge &edge)
	{
		return this->distance < edge.distance;
	}
};

int main(void)
{
	int node = 7;
	int m = 11;
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12));
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(2,5,17));
	v.push_back(Edge(2,4,24));
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13));
	v.push_back(Edge(5,6,45));
	v.push_back(Edge(5,7,73));
	
	
	// 간선 비용 기준 정렬
	sort(v.begin(), v.end());
	
	int parent[node];
	for(int i =  0 ; i < node ; i++)
		parent[i] = i;
	
	
	int sum = 0;
	for(int i = 0 ; i < v.size() ; i++)
	{
		if( !findParent(parent,v[i].node[0]-1, v[i].node[1]-1 )) // 간선에서 첫번째 노드와 두 번째 노드가 연결되어 있지 않은 경우(사이클x)
		{
			sum = sum + v[i].distance;
			unionParent(parent, v[i].node[0] - 1 , v[i].node[1] - 1 );
		}
	}
	
	cout << "sum : " << sum << "\n";
	return 0;
}





