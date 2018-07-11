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

int cc[MV]; // connected component
set<int> nvis,tmp;
queue<int> qu;
int bfs_cg()
{
	nvis.clear(); tmp.clear();
	for(int i=0;i<nv;i++)
		nvis.insert(i);
	while(!qu.empty()) qu.pop();

	int cnt=0;
	for(int i=0;i<nv;i++)
	{
		if(cc[i]!=-1) continue;
		cc[i]=cnt++; nvis.erase(i); qu.push(i);
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
				cc[v]=cc[u];
				qu.push(v);
			}
			nvis.swap(tmp); tmp.clear();
		}
	}
	return cnt;
}

int main()
{
	return 0;
}
