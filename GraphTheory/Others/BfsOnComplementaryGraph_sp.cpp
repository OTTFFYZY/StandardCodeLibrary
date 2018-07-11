#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MV=1e5+5;
vector<int> cg[MV]; //complementary graph
int nv,ne;

int d[MV];
set<int> nvis,tmp;
queue<int> qu;
void bfs_cg(int st)
{
	nvis.clear(); tmp.clear();
	memset(d,-1,sizeof(d));
	for(int i=0;i<nv;i++)
		nvis.insert(i);
	while(!qu.empty()) qu.pop();
	d[st]=0; nvis.erase(st); qu.push(st);
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		for(int v:cg[u])
			if(nvis.count(v))
			{
				nvis.erase(v);
				tmp.insert(v);
			}
		for(int v:nvis)
		{
			d[v]=d[u]+1;
			qu.push(v);
		}
		nvis.swap(tmp); tmp.clear();
	}
}

int main()
{
	return 0;
}
