#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;


const int MV=1e5+5;//number of vertices
vector<int> g[MV];

void init()
{
	for(int i=0;i<MV;i++)
		g[i].clear();
}
void add_edge(int fr,int to) //directed
{
	g[fr].push_back(to);
}
bool vis[MV];
int dep[MV];
queue<int> qu;
void bfs(int u)
{
	while(!qu.empty()) qu.pop();
	vis[u]=1;
	dep[u]=0;
	qu.push(u);
	while(!qu.empty())
	{
		u=qu.front(); qu.pop();
		
		//operations for u
		
		for(auto v:g[u])
			if(!vis[v])
			{
				vis[v]=1;
				dep[v]=dep[u]+1;
				qu.push(v);
			}
	}
}

int main()
{
	init();
	memset(vis,0,sizeof(vis));
	int st=0;
	bfs(st);
	return 0;
}