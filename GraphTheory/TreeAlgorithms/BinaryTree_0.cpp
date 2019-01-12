#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;

struct TN
{
	int v,ls,rs;
	TN(int v=0,int ls=0,int rs=0)
		:v(v),ls(ls),rs(rs){}
};
struct BT
{
	TN tn[M];
	int root;
	void clear()
	{
		root=1;
		tn[1]=TN();
	}
	void add_edge(int u,int v,int lr)
	{
		if(lr) tn[u].rs=v;
		else tn[u].ls=v;
	}
	void preorder(int u)
	{
		if(!u) continue;
		cout<<tn[u].v<<" ";
		preorder(u.ls);
		preorder(u.rs);
	}
	void inorder()
};