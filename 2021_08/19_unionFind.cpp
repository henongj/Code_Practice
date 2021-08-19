#include<iostream>

using namespace std;

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

int main(void)
{
	int parent[11];
	for(size_t i = 1 ; i <= 10 ; i++)
		parent[i] = i;
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	unionParent(parent, 9, 10);
	cout << "1 과 8 연결 여부 : " << findParent(parent, 1, 8) << "\n";
	unionParent(parent, 1,8);
	cout << "1 과 8을 unionParent 한 뒤에 값 : " << findParent(parent, 1,8) << "\n";
	
	return 0;
  
}
