#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int M=1000;
int st[M];
vector<int> g[M];

bool win(int u)
{
	if(st[u]!=-1) return st[u];
	st[u]=0;
	for(int v:g[u])
		if(!getst(v))
		{
			st[u]=1;
			break;
		}
	return st[u];
}