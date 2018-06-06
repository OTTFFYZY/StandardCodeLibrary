#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
const int MV=1e3+5;
int g[MV][MV];

bool inmst[MV];
int dis[MV],pre[MV];

int prim(int nv)
{
	int mst=0;
	dis[0]=0; inmst[0]=1;
	for(int i=1;i<nv;i++)
	{
		//pre[i]=0;
		inmst[i]=0;
		dis[i]=g[0][i];
	}
	for(int i=1;i<nv;i++)
	{
		int mi=INF,p;
		for(int j=1;j<nv;j++)
			if(!inmst[j]&&dis[j]<mi)
			{
				mi=dis[j];
				p=j;
			}
		mst+=dis[p];
		inmst[p]=1;
		for(int j=1;j<nv;j++)
			if(!inmst[j]&&dis[j]>g[p][j])
			{
				dis[j]=g[p][j];
				pre[j]=p;
			}
	}
	return mst;
}

int main()
{
	return 0;
}