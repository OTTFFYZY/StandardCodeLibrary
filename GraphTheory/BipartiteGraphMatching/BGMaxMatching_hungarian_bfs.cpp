#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MV=1e3+5;
vector<int> g[MV];
int nvl; //vertex in the left side

int pre[MV],vis[MV],match[MV];
//vis    in alternating path
//match  result

queue<int> qu;
int hungarian()
{
	int ans=0;
	memset(match,-1,sizeof(match));
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<nvl;i++)
	{
		if(match[i]!=-1) continue;
		while(!qu.empty()) qu.pop();
		pre[i]=-1; qu.push(i);
		bool f=0;
		while(!qu.empty()&&!f)
		{
			int u=qu.front(); qu.pop();
			for(int v:g[u])
			{
				if(vis[v]!=i)
				{
					vis[v]=i;
					qu.push(match[v]);
					if(match[v]>=0) pre[v]=i;
					else
					{
						f=1;
						int d=u,e=v;
						while(d!=-1)
						{
							int t=match[d];
							match[d]=e; match[e]=d;
							d=pre[d];
							e=t;
						}
					}
				}
			}
		}
		if(match[i]!=-1) ans++;
	}
	return ans;
}

int main()
{
	return 0;
}