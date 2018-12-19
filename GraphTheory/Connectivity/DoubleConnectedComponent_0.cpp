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
int col[MV],ncol;

stack<int> stu,stv;

int dfs(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	int ch=0; //number of children
	for(int v:g[u])
	{
		if(!dfn[v])
		{
			stu.push(u); stv.push(v);
			ch++;
			lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=dfn[u])
			{
				iscut[u]=1;
				while(1)
				{
					int nu=stu.top(); stu.pop();
					int nv=stv.top(); stv.pop();
					col[nu]=col[nv]=ncol;
					if(nu==u&&nv==v) break;
				}
				ncol++;
			}
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
		{
			stu.push(u); stv.push(v);
			lowu=min(lowu,dfn[v]);
		}
	}
	if(fa==-1&&ch==1) iscut[u]=0;
	return lowu;
}

void find_dcc() // Double Connected Component
{
	memset(iscut,0,sizeof(iscut));
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	ncol=0;
	for(int i=0;i<nv;i++)
		dfs(nv,-1);
}

int main()
{
	return 0;
}