#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int M=1e3+5;
const int INF=0x3f3f3f3f;
struct Edge
{
	int fr,to,d;
}edges[M];
int d[M];
void bellmanFord(int st,int nv,int ne)
{
	memset(d,INF,sizeof(d));
	d[st]=0;
	int u,v;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m;j++)
		{
			u=edges[j].fr; v=edges[j].to;
			if(d[u]<INF) d[v]=min(d[v],d[u]+edges[i].d);
		}
}

int main()
{
	return 0;
}