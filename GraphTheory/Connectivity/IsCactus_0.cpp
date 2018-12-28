#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MV=20005;

vector<int> g[MV];
int nv,ne;

void init()
{
	for(int i=0;i<nv;i++)
		g[i].clear();
}

void add_edge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

int dfn[MV],ndfn;
int bccno[MV],bccv[MV],bcce[MV],nbcc;
stack<int> stu,stv;

int dfs(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	for(int v:g[u])
	{
		if(v==fa) continue;
		if(!dfn[v])
		{
			stu.push(u); stv.push(v);
			lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=dfn[u])
			{
				while(1)
				{
					int nu=stu.top(); stu.pop();
					int nv=stv.top(); stv.pop();
					bcce[nbcc]++;
					if(bccno[nu]!=nbcc)
					{
						bccno[nu]=nbcc;
						bccv[nbcc]++;
					}
					if(bccno[nv]!=nbcc)
					{
						bccno[nv]=nbcc;
						bccv[nbcc]++;
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
	return lowu;
}

bool is_cactus()
{

	memset(dfn,0,sizeof(dfn)); ndfn=0;
	memset(bccno,-1,sizeof(bccno)); nbcc=0;
	memset(bccv,0,sizeof(bccv));
	memset(bcce,0,sizeof(bcce));
	int cnt=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i])
		{
			//cout<<i<<endl;
			dfs(i,-1);
			cnt++;
			if(cnt>1) return 0;
		}
	for(int i=0;i<nbcc;i++)
	{
		//cout<<" "<<i<<" "<<bccv[i]<<" "<<bcce[i]<<endl;
		if(bccv[i]<=2) continue;
		if(bccv[i]!=bcce[i]) return 0;
	}
	return 1;
}

int main()
{
	return 0;
}