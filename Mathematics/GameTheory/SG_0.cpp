#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;
int sg[M],s[M];
vector<int> g[M];
int n;

void getsg(int u)
{
	if(sg[u]!=-1) return sg[u];
	memset(s,0,sizeof(s));
	for(int v:g[x])
		s[getsg(v)]=1;
	for(int i=0;i<=n;i++)
		if(!s[i]) return sg[u]=i;
}

void sg_table()
{
	for(int i=0;i<n;i++)
		cout<<i<<" "<<getsg(i)<<endl;
}

int main()
{
	return 0;
}