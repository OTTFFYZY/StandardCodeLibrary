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
queue<PII> qu;
int dis[M][M];
int bfs(int stx,int sty,int edx,int edy)
{
	while(!qu.empty()) qu.pop();
	memset(dis,-1,sizeof(dis));
	dis[stx][sty]=0;
	qu.emplace(stx,sty);
	while(!qu.empty())
	{
		int nx=qu.front().first,ny=qu.front().second;
		for(int i=0;i<4;i++)
		{
			int x=nx+dx[i],y=ny+dx[i];
			if(0<=x&&x<n&&0<=y&&y<m&&dis[x][y]==-1)
			{
				if(x==edx&&y==edy) return dis[nx][ny]+1;
				dis[x][y]=dis[nx][ny]+1;
				qu.emplace(x,y);
			}
		}
	}
	return -1;
}


int main()
{
	return 0;
}