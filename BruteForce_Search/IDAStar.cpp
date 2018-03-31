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

int stx,sty,edx,edy;
int h(int x,int y)
{
	return abs(edx-x)+abs(edy-y);
	// an example for heuristic function
	// if h==0 IDA-Star -> ID
}

int vis[M][M];
int maxd;
bool dfs(int nx,int ny,int dep)
{
	if(dep==maxd)
	{
		if(nx==edx&&ny==edy) return 1;
		return 0;
	}
	if(dep+h(nx,ny)>maxd) return 0;
	for(int i=0;i<4;i++)
	{
		int x=nx+dx[i],y=ny+dy[i];
		if(0<=x&&x<n&&0<=y&&y<m&&!vis[x][y])
		{
			vis[x][y]=1;
			if(dfs(x,y,dep+1)) return 1;
			vis[x][y]=0;
		}
	}
	return 0;
}


int main()
{
	memset(vis,0,sizeof(vis));
	for(maxd=0;;maxd++)
		if(dfs(stx,sty,0)) break;
	cout<<maxd<<endl;
	return 0;
}