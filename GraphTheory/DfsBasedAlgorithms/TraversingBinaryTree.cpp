#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int M=1e5+5;
struct TreeNode
{
	int v;
	int l,r;
}tn[M];

void preorder(int u)
{
	if(u==-1) return;
	cout<<tn[u].v<<endl;
	preorder(tn[u].l);
	preorder(tn[u].r);
}

void inorder(int u)
{
	if(u==-1) return;
	inorder(tn[u].l);
	cout<<tn[u].v<<endl;
	inorder(tn[u].r);
}

void postorder(int u)
{
	if(u==-1) return;
	postorder(tn[u].l);
	postorder(tn[u].r);
	cout<<tn[u].v<<endl;
}

int main()
{
	return 0;
}