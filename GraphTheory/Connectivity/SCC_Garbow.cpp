#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MV=1e5+5;
vector<int> g[MV];
int nv;

int dfn[MV],ndfn;
stack<int> sta,stb;
int sccno[MV],nscc;

void dfs(int u)
{
	sta.push(u); stb.push(u);
	dfn[u]=++ndfn;
	for(int v:g[u])
	{
		if(!dfn[v]) dfs(v);
		else if(sccno[v]==-1)
			while(dfn[stb.top()]>dfn[v]) stb.pop();
	}
	if(stb.top()==u)
	{
		while(1)
		{
			int nu=sta.top(); sta.pop();
			sccno[nu]=nscc;
			if(nu==u) break;
		}
		nscc++;
		stb.pop();
	}
}

void scc_garbow()
{
	memset(dfn,0,sizeof(dfn)); ndfn=0;
	memset(sccno,-1,sizeof(sccno)); nscc=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) dfs(i);
}

int main()
{
	return 0;
}