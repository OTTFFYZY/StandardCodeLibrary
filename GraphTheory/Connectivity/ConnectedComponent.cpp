#include <stdio.h>
#include <vector>
using namespace std;

const int M=1e5+5;//maximum number of vertex
vector<int> g[M];
int nv;//number of vertex

void init()
{
	for(int i=0;i<M;i++)
		g[i].clear();
}
void add_edge(int a,int b) //undirected
{
	g[a].push_back(b);
	g[b].push_back(a);
}

int cnt=0;
int cc[M];

void dfs(int u)
{
	cc[u]=cnt;
	for(int v:g[u]) if(!cc[v]) dfs(v);
}
void get_cc()
{
	cnt=0;
	memset(cc,0,sizeof(cc));
	for(int i=0;i<nv;i++)
		if(!cc[i])
		{
			++cnt;
			dfs(i);
		}
}

int main()
{
	return 0;
}