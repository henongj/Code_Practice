#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int n,m;
int count = 0;
int box[1000][1000];
int check[1000][1000];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1}};
queue <pair<int,int>> q;

bool is_inside(const int &x, const int &y)
{
	if( (0 <= x && x < n) && (0 <=y && y < m) )
		return true;
	else
		return false;
}

void day_search(void)
{
	for(int j = 0 ; j < m ; j ++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(check[j][i] > count)
				count = check[j][i];
		}
	} // check 안의 가장 큰 값 = count
}

bool box_check(void)
{
	for(int j = 0 ; j < m ; j ++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(check[j][i] == -1)
				return true;
		}
	} // check 안의 가장 큰 값 = count
	return 	false;
}

void be_ripe(const int &xpos , const int &ypos)
{
	for(int i = 0 ; i < 4 ; i++)
	{
		int x = dir[i][0] + xpos;
		int y = dir[i][1] + ypos;
		if(is_inside(x,y) && check[y][x] == -1)
		{
			check[y][x] = check[ypos][xpos] + 1;
			q.push(make_pair(x,y));
		}
	}
}

void BFS(void)
{
	while( !(q.empty()) )
	{
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();
		be_ripe(xpos,ypos);
	}
	day_search();
	
}


int main() {
	scanf("%d %d\n",&n,&m);
	for(int j = 0 ; j < m ; j++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf(" %d", &box[j][i]);
			if(box[j][i]==1)
			{
				check[j][i] = 0;
				q.push(make_pair(i,j));
			}
			else if(box[j][i] == 0)
				check[j][i] = -1;
			else
				check[j][i] = -2;
		}
	}
	
	BFS();
	if(box_check()) 
	{
		printf("-1");
		return 0;
	}
	else
		printf("%d",count);

	return 0;
}
