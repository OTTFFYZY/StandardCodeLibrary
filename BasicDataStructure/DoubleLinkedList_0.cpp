#include <stdio.h>

const int M=1e5;

struct DListNode
{
	int v;
	int pre,nxt;
	DListNode(){}
	DListNode(int _v,int _pre,int _nxt):v(_v),pre(_pre),nxt(_nxt){}
}ln[M];
int nn=0;

struct LinkList
{
	int head,tail;
	void init()
	{
		head=nn;
		ln[nn]=DListNode(0,-1,++nn);
		tail=nn;
		ln[nn].DListNode(0,nn-1,-1);
		nn++;
	}
	int find(int v)
	{
		for(int i=ln[head].nxt;i!=tail;i=ln[i].nxt)
			if(ln[i].v==v) return i;
		return -1;
	}
	int add(int v,int id)//在下标为id的节点后面插入v
	{
		ln[nn]=DListNode(v,id,ln[id].nxt);
		ln[ln[id].nxt].pre=nn;
		ln[id].nxt=nn++;
	}
	int del(int id)
	{
		ln[ln[id].pre].nxt=ln[id].nxt;
		ln[ln[id].nxt].pre=ln[id].pre;
	}
};
int main()
{
	return 0;
}