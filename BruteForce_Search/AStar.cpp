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
	int h;
	Node(){}
	Node(int x,int y,int h):x(x),y(y),h(h){}
	bool operator<(const Node &B) const
	{
		return h>B.h;
	}
};

priority_queue<Node> qu;
int stx,sty,edx,edy;
int geth(int x,int y)
{
	return abs(edx-x)+abs(edy-y);
	// an example for heuristic function
}

int dis[M][M];
int bfs()
{
	while(!qu.empty()) qu.pop();
	memset(dis,-1,sizeof(dis));
	dis[stx][sty]=0;
	qu.emplace(stx,sty,geth(stx,sty));
	while(!qu.empty())
	{
		int nx=qu.top().x,ny=qu.top().y;
		for(int i=0;i<4;i++)
		{
			int x=nx+dx[i],y=ny+dx[i];
			if(0<=x&&x<n&&0<=y&&y<m&&dis[x][y]==-1)
			{
				if(x==edx&&y==edy) return dis[nx][ny]+1;
				dis[x][y]=dis[nx][ny]+1;
				qu.emplace(x,y,geth(x,y));
			}
		}
	}
	return -1;
}


int main()
{
	return 0;
}