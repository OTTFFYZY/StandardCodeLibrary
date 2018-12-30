#include <stdio.h>

const int M=1e5+5;

struct DListNode
{
	int v;
	int pre,nxt;
	DListNode(int v=0,int pre=0,int nxt=0)
		:v(v),pre(pre),nxt(nxt){}
};

struct DLinkList
{
	int head,tail,nn;
	DListNode ln[M];
	void init()
	{
		head=0; tail=1;
		ln[0]=DListNode(0,-1,1);
		ln[1]=DListNode(0,0,-1);
		nn=2;
	}
	void link(int x,int y)
	{
		ln[x].nxt=y; ln[y].pre=x;
	}
	int find(int v)
	{
		for(int i=ln[head].nxt;i!=tail;i=ln[i].nxt)
			if(ln[i].v==v) return i;
		return -1;
	}
	void ins(int v,int p) //insert after ln[p]
	{
		ln[nn]=DListNode(v);
		link(nn,ln[p].nxt);
		link(p,nn++);
	}
	void del(int p) // remove ln[p]
	{
		link(ln[p].pre,ln[p].nxt);
	}
};
int main()
{
	return 0;
}