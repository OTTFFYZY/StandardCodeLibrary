#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;
const int MC=26;
const char MINC='A';
struct Trie
{
	struct TN
	{
		int v;
		int nxt[MC];
		int& operator[](int x)
		{
			return nxt[x];
		}
	}tn[M];
	int n;
	void clear()
	{
		n=1;
		memset(tn[0],0,sizeof(tn[0]));
	}
	int newnode()
	{
		memset(tn[n],0,sizeof(tn[n]));
		return n++;
	}
	int idx(char c)
	{
		return c-MINC;
	}
	void insert(char *s,int v)
	{
		int l=strlen(s),u=0;
		for(int i=0;i<l;i++)
		{
			int id=idx(s[i]);
			if(!tn[u][id]) tn[u][id]=newnode();
			u=tn[u][id];
		}
		tn[u].v=v;
	}
	int find(char *s)
	{
		int l=strlen(s),u=0;
		for(int i=0;i<l;i++)
		{
			int id=idx(s[i]);
			if(!tn[u][id]) return -1;
			u=tn[u][id];
		}
		return u; // the index of the node
	}
}

int main()
{
	return 0;
}