#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int M=1005;
int ma[M][M],n,m;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct Node
{
	int x,y;
	int f;    //f=g+h
	Node(){}
	Node(int x=0,int y=0,int f=0):x(x),y(y),f(f){}
	bool operator<(const Node &B) const
	{
		return f>B.f; // f==B.f : g < B.g : f>B.f
	}
};

priority_queue<Node> qu;
int stx,sty,edx,edy;
int h(int x,int y)
{
	return abs(edx-x)+abs(edy-y);
	// an example for heuristic function
	// if h==0 AStar -> BFS
}

int dis[M][M];
int vis[M][M];
int AStar()
{
	while(!qu.empty()) qu.pop();
	memset(dis,-1,sizeof(dis));
	dis[stx][sty]=0;
	qu.emplace(stx,sty,h(stx,sty));
	while(!qu.empty())
	{
		int nx=qu.top().x,ny=qu.top().y;
		if(vis[nx][ny]==2) continue;
		vis[nx][ny]=2;
		for(int i=0;i<4;i++)
		{
			int x=nx+dx[i],y=ny+dx[i];
			if(x<0||n<=x||y<0||m<=y||vis[x][y]==2||ma[x][y]) continue;
			if(x==edx&&y==edy) return dis[nx][ny]+1;
			if(!vis[x][y]||dis[x][y]>dis[nx][ny]+1)
			{
				vis[x][y]=1;
				dis[x][y]=dis[nx][ny]+1;
				qu.emplace(x,y,dis[x][y]+h(x,y));
			}
		}
	}
	return -1;
}


int main()
{
	return 0;
}