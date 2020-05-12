#include <bits/stdc++.h>
using namespace std;

const int M=1e6+5;

const int AC_SIGMA=26,AC_N=M;
struct TN
{
	TN *go[AC_SIGMA],*fail,*fa;
	int sz;
	int cnt;
};
struct Trie
{
	TN pool[AC_N],*cur,*root,*q[AC_N];
	int tail;
	TN *newnode() 
	{
		TN *p=cur++;
		memset(p->go,0,sizeof(p->go)); p->fail=p->fa=NULL; p->cnt=0;
		return p;
	}
	void init() { cur=pool; root=newnode(); }
	TN *append(TN *p,int w)
	{
		if (!p->go[w]) 
			p->go[w]=newnode(),p->go[w]->fa=p;
		return p=p->go[w];
	}
	void build()
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
	}
	void cal()
	{
		for(int i=tail-1;i>0;i--) 
			if (q[i]->fail) q[i]->fail->cnt+=q[i]->cnt;
	}
}trie;


char p[M];
TN* pos[M];
char t[M];

int main()
{
	int n;
	scanf("%d",&n);
	trie.init();
	for(int i=0;i<n;i++)
	{
		scanf("%s",p);
		TN *u=trie.root;
		for(char *c=p;*c;c++)
			u=trie.append(u,*c-'a');
		pos[i]=u;
	}
	trie.build();
	scanf("%s",t);
	TN *u=trie.root;
	for(char *c=t;*c;c++)
	{
		while(u&&!u->go[*c-'a']) u=u->fail;
		if(u) u=u->go[*c-'a'];
		else u=trie.root;
		u->cnt++;
	}
	trie.cal();
	int ans=0;
	for(int i=0;i<n;i++)
		if(pos[i]->cnt) ans++;
	printf("%d\n",ans);
	return 0;
}