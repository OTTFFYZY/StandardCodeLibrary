#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int M=2e4+5;

vector<int> g[M];
int iscut[M];
int nxt[M];
int dep[M];
int mark[M];

int ncut=0;
void dfs(int u,int fa,int d)
{
	dep[u]=d;
	int cnt=0;
	for(int v:g[u])
	{
		if(v==fa) continue;
		if(!dep[v])
		{
			cnt++;
			nxt[u]=v;
			dfs(v,u,d+1);
			mark[u]+=mark[v];
			if(!mark[v]) iscut[u]=1;
		}
		else if(dep[v]<dep[u])
		{
			mark[nxt[v]]--;
			mark[u]++;
		}
	}
	if(fa==-1&&cnt==1)
		iscut[u]=0;
	if(iscut[u]) ncut++;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!dep[i]) dfs(i,-1,1);
	printf("%d\n",ncut);
	for(int i=1;i<=n;i++)
		if(iscut[i]) printf("%d ",i);
	printf("\n");
	return 0;
}