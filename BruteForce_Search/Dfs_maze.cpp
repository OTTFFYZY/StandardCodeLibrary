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
int vis[M][M];
int stx,sty,edx,edy;

void dfs(int nx,int ny)
{
	if(nx==edx&&ny==edy)
	{
		//do something
		return;
	}
	//do something
	
	for(int i=0;i<4;i++)
	{
		int x=nx+dx[i],y=ny+dy[i];
		if(0<=x&&x<n&&0<=y&&y<m&&!vis[x][y])
		{
			vis[x][y]=1;
			dfs(x,y);
		}
	}
}


int main()
{
	memset(vis,0,sizeof(vis));
	vis[stx][sty]=1;
	dfs(stx,sty);
	return 0;
}