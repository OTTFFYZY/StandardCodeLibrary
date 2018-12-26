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
int sccno[MV],nscc;

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
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		while(1)
		{
			inst[st[stp]]=0;
			sccno[st[stp]]=nscc;
			if(st[stp--]==u) break;
		}
		nscc++;
	}
}

void scc_tarjan()
{
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	memset(inst,0,sizeof(inst));
	stp=0;
	nscc=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) tarjan(i);
}

int main()
{
	return 0;
}