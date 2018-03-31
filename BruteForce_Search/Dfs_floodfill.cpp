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
int col[M][M];
int cnt;

void dfs(int nx,int ny)
{
	for(int i=0;i<4;i++)
	{
		int x=nx+dx[i],y=ny+dy[i];
		if(0<=x&&x<n&&0<=y&&y<m&&!col[x][y])
		{
			col[x][y]=cnt;
			dfs(x,y);
		}
	}
}


int main()
{
	memset(col,0,sizeof(col));
	cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(!col[i][j])
			{
				col[i][j]=++cnt;
				dfs(i,j);
			}
		}
	return 0;
}