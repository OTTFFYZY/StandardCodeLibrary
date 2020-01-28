#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define son(x,y) tn[(x)].ch[(y)]
#define ls(x) tn[(x)].ch[0]
#define rs(x) tn[(x)].ch[1]
#define fa(x) tn[(x)].fa

const int M=1e5+5;

struct Splay
{
	struct TN
	{
		int val;   // val of node
		int cnt;   // 
		int sz;    // size of subtree
		int fa;    // father
		int ch[2]; // children 0 left 1 right
		void clear()
		{
			val=cnt=sz=fa=ch[0]=ch[1]=0;
		}
		void newnode(int v)
		{
			val=v;
			sz=cnt=1;
			fa=ch[0]=ch[1]=0;
		}
	}tn[M];
	int root;
	int nn;
	void init()
	{
		root=0;
		nn=0;
	}
	int isrs(int x) // is right son
	{
		return ls(fa(x))==x;
	}
	void pull(int x)
	{
		if(!x) return;
		tn[x].sz=tn[x].cnt;
		tn[x].sz+=tn[ls(x)].sz+tn[rs(x)].sz;
	}
	void rotate(int x)
	{
		int old=fa(x),oldf=fa(old),which=isrs(x);
		// 1
		son(old,which)=son(x,which^1);
		fa(son(old,which))=old;
		// 2
		fa(old)=x; 
		son(x,which^1)=old;
		//3
		fa(x)=oldf;
		if(oldf)
			son(oldf,rs(oldf)==old)=x;
		pull(old); pull(x);
	}
	void splay(int x)
	{
		for(int nfa;(nfa=fa(x));rotate(x))
		{
			if(fa(nfa))
				rotate(isrs(x)==isrs(nfa)?nfa:x);
		}
		root=x;
	}
	void insert(int v)
	{
		if(root==0) // empty tree
		{
			tn[++nn].newnode(v);
			root=nn;
			return;
		}
		int u=root,fa=0;
		while(true)
		{
			if(tn[u].val==v)
			{
				tn[u].cnt++;
				pull(u);
				pull(fa);
				splay(u);
				return;
			}
			fa=u;
			u=tn[u].ch[tn[u].val<v];
			if(u==0)
			{
				tn[++nn].newnode(v);
				tn[nn].fa=fa;
				tn[fa].ch[tn[fa].val<v]=nn;
				pull(fa);
				splay(nn);
				return;
			}
		}
	}
	void find(int v)
	{
		int u=root;
		while(true)
		{
			// v not exist in the splay
			if(u==0 || v==tn[u].val)
			{
				splay(u);
				break;
			}
			if(v<tn[u].val)
				u=ls(u);
			else
				u=rs(u);
		}
	}
	int rank(int v)
	{
		find(v);
		return tn[root].val==v ? tn[ls(root)].sz+1 : -1;
	}
	int kth(int k)
	{
		int u=root;
		while(u)
		{
			if(ls(u)&&k<=tn[ls(u)].sz)
				u=ls(u);
			else if(k<=tn[ls(u)].sz+tn[u].cnt)
			{
				splay(u);
				return tn[root].val;
			}
			else
			{
				k-=tn[ls(u)].sz+tn[u].cnt;
				u=rs(u);
			}
		}
		return -1;
	}
	int pre() // find predecesor for root
	{
		int u=ls(u);
		while(rs(u)) u=rs(u);
		return u;
	}
	int suc() // find successor for root
	{
		int u=rs(u);
		while(ls(u)) u=ls(u);
		return u;
	}
	void remove(int v)
	{
		find(v); // check tn[root].val = v
		if(tn[root].cnt>1)
		{
			tn[root].cnt--;
			pull(root);
			return;
		}
		// tn[root].cnt==1;
		if(!ls(root)||!rs(root))
		{
			root=ls(root)^rs(root);
			fa(root)=0;
			return;
		}
		int lg=pre(); // left bigest
		int u=root;
		splay(lg);
		fa(rs(u))=root;
		rs(root)=rs(u);
		pull(root);
	}
}splay;


int main()
{
	return 0;
}