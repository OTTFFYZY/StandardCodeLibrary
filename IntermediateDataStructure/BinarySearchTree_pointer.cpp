#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct BST
{
	struct TN
	{
		TN *l,*r,*p;
		int v,si,cnt;
	};
	TN *root;
	BST():root(NULL){}
	void preTran(TN *u)
	{
		if(u==NULL) cout<<"#"<<endl;
		cout<<u->val<<" "<<u->si<<" "<<u->cnt<<endl;
		preTran(u->l);
		preTran(u->r);
	}
	TN* getMax(TN *u) // u!=NULL
	{
		while(u->r!=NULL) u=u->r;
		return u;
	}
	TN* getMin(TN *u) // u!=NULL
	{
		while(u->l!=NULL) u=u->l;
		return u;
	}
	TN* prev(TN *u)
	{
		if(u->l!=NULL)
			return getMax(u->l);
		TN *fa=u->p;
		while(p!=NULL&&p->r!=u)
		{
			u=p;
			p=p->p;
		}
		return p;
	}
	TN* succ(TN *u)
	{
		if(u->r!=NULL)
			return getMin(u->l);
		TN *fa=u->p;
		while(p!=NULL&&p->l!=u)
		{
			u=p;
			p=p->p;
		}
		return p;
	}
	void insert(TN *&u,TN *fa,int v)
	{
		if(u==NULL)
		{
			u=new TN();
			u->p=fa;
			u->v=v; u->cnt=1; u->si=1;
			return;
		}
		if(u->v==v)
		{
			u->si++;
			u->cnt++;
			return;
		}
		u->si++;
		if(v<u->v)
			insert(u->l,u,v);
		else
			insert(u->r,u,v);
	}
	TN* find(TN *u,int v)
	{
		if(u==NULL) return NULL;
		if(u->v==v) return u;
		if(v<u->v) find(u->l);
		else find(u->r);
	}
	TN* kth(TN *u,int k)
	{
		if(k>u->si) return NULL;
		int lsi=u->left==NULL?0:u->left->si;
		if(k<=lsi)
			return kth(u->left,k);
		else if(k>lsi+u->cnt)
			return kth(u->right,k-lsi-u->cnt);
		else
			return u;
	}
	int rank(TN *u,int v)
	{
		if(u==NULL) return 1;
		if(u->v==v) return 1;
		if(v<u->v)
			return rank(u->l,v);
		else
			return rank(u->r,v)+
				   (u->left==NULL?0:u->left->si)+u->cnt;
	}
};

int main()
{
	return 0;
}