#include <stdio.h>

const int M=1e5;

struct ListNode
{
	int v;
	int nxt;
	ListNode(){}
	ListNode(int _v,int _nxt):v(_v),nxt(_nxt){}
}ln[M];
int nn=0;

struct LinkList
{
	int head;
	void init()
	{
		head=nn;
		ln[nn++].nxt=-1;
	}
	int find(int v)
	{
		for(int i=ln[head].nxt;i!=-1;i=ln[i].nxt)
			if(ln[i].v==v) return i;
		return -1;
	}
	int add(int v,int id)//在下标为id的节点后面插入v
	{
		ln[nn]=ListNode(v,ln[id].nxt);
		ln[id].nxt=nn++;
	}
	int find_pre(int v)
	{
		int pre=head;
		for(int i=ln[head].nxt;i!=-1;i=ln[i].nxt)
		{
			if(ln[i].v==v) return pre;
			pre=i;
		}
		return -2;
	}
	int del(int id)
	{
		int idp=find_pre(ln[id].v);
		ln[idp].nxt=ln[id].nxt;
	}
};
int main()
{
	return 0;
}