#include <bits/stdc++.h>
using namespace std;

const int MP=75;
const int MN=150;
const int MT=1e6+5;

const int AC_SIGMA=26,AC_N=MP*MN;
struct TN
{
	TN *go[AC_SIGMA],*fail,*fa;
	int sz; // number of word cover by this node
	int cnt; // number of times this node matches
};
struct Trie
{
	TN pool[AC_N],*cur,*root,*q[AC_N];
	int tail;
	TN *newnode() 
	{
		TN *p=cur++;
		memset(p->go,0,sizeof(p->go)); p->fail=p->fa=NULL; p->cnt=p->sz=0;
		return p;
	}
	void init() { cur=pool; root=newnode(); }
	TN *append(TN *p,int w)
	{
		if (!p->go[w]) 
			p->go[w]=newnode(),p->go[w]->fa=p;
		return p=p->go[w];
	}
	void build() // trie graph
	{
		tail=1;
		q[0]=root;
		for(int i=0;i<tail;i++) 
			for(int j=0;j<AC_SIGMA;j++) 
			{
				if(!q[i]->go[j]) continue;
				TN *v=q[i]->go[j],*p=v->fa->fail;
				while(p&&!p->go[j]) p=p->fail;
				if(p) v->fail=p->go[j]; 
				else v->fail=root;
				q[tail++]=q[i]->go[j];
			}
		for(int i=0;i<tail;i++) 
			if(q[i]->fail) q[i]->sz+=q[i]->fail->sz;
		for(int i=0;i<tail;i++) 
			for(int j=0;j<AC_SIGMA;j++)  
			{
				if(q[i]->go[j]) continue;
				TN *p=q[i]->fail;
				if(!p) q[i]->go[j]=root;
				else q[i]->go[j]=p->go[j];
			}
	}
	void cal()
	{
		for(int i=tail-1;i>0;i--) 
			if (q[i]->fail) q[i]->fail->cnt+=q[i]->cnt;
	}
}trie;


char p[MN][MP];
TN* pos[MN];
char t[MT];

int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		trie.init();
		for(int i=0;i<n;i++)
		{
			scanf("%s",p[i]);
			TN *u=trie.root;
			for(char *c=p[i];*c;c++)
				u=trie.append(u,*c-'a');
			pos[i]=u;
		}
		trie.build();
		scanf("%s",t);
		TN *u=trie.root;
		for(char *c=t;*c;c++)
		{
			u=trie.append(u,*c-'a');
			u->cnt++;
		}
		trie.cal();
		int mx=0;
		for(int i=0;i<n;i++)
			mx=max(mx,pos[i]->cnt);
		printf("%d\n",mx);
		for(int i=0;i<n;i++)
			if(pos[i]->cnt==mx) printf("%s\n",p[i]);
	}
	return 0;
}