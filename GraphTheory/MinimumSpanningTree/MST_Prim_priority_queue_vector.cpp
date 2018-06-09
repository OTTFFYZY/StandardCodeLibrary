#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF=0x3f3f3f3f;
const int MV=1e5+5;
const int ME=1e5+5;

typedef pair<int,int> PII;
vector<PII> g[MV];

bool inmst[MV];
priority_queue<PII,vector<PII>,greater<PII> > qu;

int prim(int nv)
{
	while(!qu.empty()) qu.pop();
	memset(inmst,0,sizeof(inmst));
	inmst[0]=1;
	for(PII e:g[0])
		qu.push(e);
	int mst=0;
	while(!qu.empty())
	{
		int u=qu.top().second,w=qu.top().first; qu.pop();
		if(inmst[u]) continue;
		mst+=w;
		for(PII e:g[u])
			if(!inmst[e.second]) qu.push(e);
	}
	return mst;
}

int main()
{
	return 0;
}