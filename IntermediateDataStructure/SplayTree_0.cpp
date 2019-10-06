#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define son(x,y) tn[(x)].ch[(y)]
#define ls(x) tn[x].ch[0]
#define rs(x) tn[x].ch[1]
#define fa(x) tn[x].fa

const int M=1e5+5;


struct Splay
{
	struct TN
	{
		int val;
		int cnt;
		int sz;
		int fa;
		int ch[2];
		void clear()
		{
			val=cnt=sz=fa=ch[0]=ch[1]=0;
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
		son(old,which)=son(x,which^1);
		fa(son(old,which))=old;
		fa(old)=x; son(x,which^1)=old;
		fa(x)=oldf;
		if(oldf)
			son(oldf,rs(oldf)==old)=x;
		pull(old); pull(x);
	}
	void splay(int x)
	{
		for(int fa;(fa=fa(x));rotate(x))
		{
			if(fa(fa))
				rotate(isrs(x)==isrs(fa)?fa:x);
		}
		root=x;
	}
	
}splay;


int main()
{
	return 0;
}