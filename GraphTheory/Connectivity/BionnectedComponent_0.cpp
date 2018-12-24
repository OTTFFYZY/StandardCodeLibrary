#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MV=1005;
const int ME=1e6+5;

vector<int> g[MV];
int nv,ne;
int dfn[MV],ndfn;
bool iscut[MV];
int bccno[MV],nbcc;
vector<int> bcc[MV];
stack<int> stu,stv;

void init()
{
	memset(og,0,sizeof(og));
	for(int i=0;i<nv;i++)
		g[i].clear();
}

void add_edge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}


int dfs(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	int ch=0; //number of children
	for(int v:g[u])
	{
		if(v==fa) continue;
		if(!dfn[v])
		{
			stu.push(u); stv.push(v);
			lowv=dfs(v,u);
			ch++;
			lowu=min(lowu,lowv);
			if(lowv>=dfn[u])
			{
				iscut[u]=1;
				while(1)
				{
					int nu=stu.top(); stu.pop();
					int nv=stv.top(); stv.pop();
					if(bccno[nu]!=nbcc)
					{
						bcc[nbcc].push_back(nu);
						bccno[nu]=nbcc;
					}
					if(bccno[nv]!=nbcc)
					{
						bcc[nbcc].push_back(nv);
						bccno[nv]=nbcc;
					}
					if(nu==u&&nv==v) break;
				}
				nbcc++;
			}
		}
		else if(dfn[v]<dfn[u])
		{
			stu.push(u); stv.push(v);
			lowu=min(lowu,dfn[v]);
		}
	}
	if(fa==-1&&ch==1) iscut[u]=0;
	return lowu;
}
void find_bcc() // Biconnected Component
{
	memset(iscut,0,sizeof(iscut));
	memset(dfn,0,sizeof(dfn)); ndfn=0;
	memset(bccno,-1,sizeof(bccno)); nbcc=0;
	for(int i=0;i<nv;i++)
		bcc[i].clear();
	for(int i=0;i<nv;i++)
		if(!dfn[i]) dfs(i,-1);
}