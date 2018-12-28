#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
vector<int> g[MV];
int nv;
int dfn[MV],ndfn;
bool iscut[MV];

int dfs(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	int ch=0; //number of children
	for(int v:g[u])
	{
		if(!dfn[v])
		{
			ch++;
			lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=dfn[u]) iscut[u]=1;
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
			lowu=min(lowu,dfn[v]);
	}
	if(fa==-1&&ch==1) iscut[u]=0;
	return lowu;
}
void find_cut_vertex()
{
	memset(iscut,0,sizeof(iscut));
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) dfs(i,-1);
}


int main()
{
	return 0;
}