#include <iostream>
using namespace std;

const int M=1e5+5;

struct SAM // Suffix Automaton
{
	struct State
	{
		int len;
		State *nxt[MB],*link;
		void clear(int l=0)
		{
			len=0;
			link=NULL;
			memset(nxt,NULL,sizeof(nxt));
		}
	}state[M*2];
	State *root,*pn,*last;
	void init()
	{
		root=pn=last=state;
		pn->clear();
	}
	void extend(int c)
	{
		State *p=last;
		State *np=last=++pn;
		for(;p!=NULL&&p->nxt[c]==NULL;p=p->link)
			p->nxt[c]=np;
		if(p==NULL)
		{
			np->link=root;
			return;
		}
		State *q=p->nxt[c];
		if(p->len+1==q->len)
		{
			np->link=q;
			return;
		}
		State *nq=++pn;
		memcpy(nq,q,sizeof(State));
		nq->len=p->len+1;
		np->link=q->link=nq;
		for(;p!=NULL&&p->nxt[c]==q;p=p->link)
			p->nxt[c]=nq;
	}
};

int main()
{
	return 0;
}