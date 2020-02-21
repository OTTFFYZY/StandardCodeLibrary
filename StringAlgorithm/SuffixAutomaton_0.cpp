#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=1e6+5;
const char BASE='a';
const int MB=26;

struct SAM // Suffix Automaton
{
	struct Node
	{
		int len;
		int nxt[MB],link;
		void clear(int l=0)
		{
			len=0;
			link=0;
			memset(nxt,0,sizeof(nxt));
		}
	}node[M*2];
	int rt,nn,lst;
	void init()
	{
		rt=nn=lst=1;
		node[nn].clear();
	}
	void extend(int c)
	{
		int p=lst;
		int np=lst=++nn;
		for(;p&&!node[p].nxt[c];p=node[p].link)
			node[p].nxt[c]=np;
		if(!p)
		{
			node[np].link=rt;
			return;
		}
		int q=node[p].nxt[c];
		if(node[p].len+1==node[q].len)
		{
			node[np].link=q;
			return;
		}
		int nq=++nn;
		node[nq]=node[q];
		node[nq].len=node[p].len+1;
		node[np].link=node[q].link=nq;
		for(;p&&node[p].nxt[c]==q;p=node[p].link)
			node[p].nxt[c]=nq;
	}
}sam;

int main()
{
	return 0;
}