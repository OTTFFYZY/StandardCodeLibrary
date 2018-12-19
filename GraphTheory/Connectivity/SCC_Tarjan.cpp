#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MV=1e5+5;
vector<int> g[MV];
int nv,ne;

int dfn[MV],low[MV],ndfn;
int st[MV],inst[MV],stp;
int col[MV],ncol;

void tarjan(int u)
{
	dfn[u]=low[u]=++ndfn;
	inst[u]=1;
	st[++stp]=u;
	for(int v:g[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(inst[v])
			low[u]=min(low[u],low[v]);
	}
	if(low[u]==u)
	{
		while(1)
		{
			inst[st[stp]]=0;
			col[st[stp]]=ncol;
			if(st[stp--]==u) break;
		}
		ncol++;
	}
}

void scc_tarjan()
{
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	memset(inst,0,sizeof(inst));
	stp=0;
	ncol=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) tarjan(i);
}

int main()
{
	return 0;
}