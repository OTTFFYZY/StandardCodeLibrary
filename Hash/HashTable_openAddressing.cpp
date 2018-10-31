#include <iostream>
#include <stdio.h>
#include <string.h>

const int MH=1226959;

struct Hash
{
	int head[MH],nxt[MH],v[MH];
	int nn;
	int hash(int n)
	{
		return n%MH;
	}
	void init()
	{
		memset(head,-1,sizeof(head));
		nn=0;
	}
	bool find(int x)
	{
		int h=hash(x);
		for(int e=head[h];e!=-1;e=nxt[e])
			if(v[e]==x) return 1;
		return 0;
	}
	bool insert(int x)
	{
		if(find(x)) return 0;
		int h=hash(x);
		v[nn]=x;
		nxt[nn]=head[h];
		head[h]=nn++;
		return 1;
	}
	void remove(int x)
	{
		int prev=-1;
		int h=hash(x),e;
		for(e=head[h];e!=-1;e=nxt[e])
		{
			if(v[e]==x) break;
			prev=e;
		}
		if(e==-1) return;
		if(prev==-1)
			head[h]=nxt[e];
		else
			nxt[prev]=nxt[e];
	}
};

int main()
{

	return 0;
}