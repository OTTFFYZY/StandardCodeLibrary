#include <iostream>
#include <stdio.h>
#include <string.H>
using namespace std;

const int M=1e3+5;
const int INF=0x3f3f3f3f;
int g[M][M];
int vis[M],d[M];
void dijkstra(int st,int n) //O(V^2)
{
	memset(vis,0,sizeof(vis));
	memset(d,INF,sizeof(d));
	d[st]=0;
	int u,mind;
	for(int i=0;i<n;i++)
	{
		mind=INF;
		for(int j=0;j<n;j++)
			if(!vis[j]&&mind>d[j]) mind=d[u=j];
		vis[u]=1;
		for(int j=0;j<n;j++)
			d[j]=min(d[j],d[u]+g[u][j]);
	}
}

int main()
{
	return 0;
}