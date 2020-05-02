#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct TN
{
	int word;
	TN *nxt,*p[26];
	//char c;
	TN():word(0),nxt(NULL)
	{
		for(int i=0;i<26;i++)
			p[i]=NULL;
	}
	void clear()
	{
		word=0; nxt=NULL;
		for(int i=0;i<26;i++)
			p[i]=NULL;
	}
};
const int M=1e5+5;
struct Pool
{
	TN a[M];
	int na;
	void clear()
	{
		na=0;
	}
	TN *NEW()
	{
		a[na].clear();
		return &a[na++];
	}
}pool;

struct Trie
{
	TN *root;
	void clear()
	{
		pool.clear();
		root=pool.NEW();
		//root->c='*';
	}
	void insert(char s[])
	{
		TN *u=root;
		for(int i=0,c;s[i];i++)
		{
			c=s[i]-'a';
			if(u->p[c]==NULL)
				u->p[c]=pool.NEW();
			u=u->p[c];
			//u->c=s[i];
		}
		u->word++;
	}
	void build()
	{
		queue<TN*> qu;
		qu.push(root);
		while(!qu.empty())
		{
			TN *u=qu.front(); qu.pop();
			for(int i=0;i<26;i++)
			{
				if(u->p[i]==NULL) continue;
				if(u==root) u->p[i]->nxt=root;
				else
				{
					TN *tmp=u->nxt;
					while(tmp)
					{
						if(tmp->p[i])
						{
							u->p[i]->nxt=tmp->p[i];
							u->p[i]->word+=tmp->p[i]->word;
							break;
						}
						tmp=tmp->nxt;
					}
					if(!tmp) u->p[i]->nxt=root;
				}
				qu.push(u->p[i]);
			}
		}
	}
	int query(char s[])
	{
		TN *u=root;
		int cnt=0;
		for(int i=0,c;s[i];i++)
		{
			//cout<<"s[i] "<<s[i]<<" c "<<u->c<<endl;
			c=s[i]-'a';
			while(!u->p[c]&&u!=root)
				u=u->nxt;
			u=u->p[c];
			if(!u) u=root;
			//if(u->word) cout<<" "<<i<<" "<<u->word<<endl;
			cnt+=u->word;
		}
		return cnt;
	}
}trie;

char p[10][20]=
{
	"abcac","abcb","bcac","bac","cba","cac"
};
char t[10][50]=
{
	"abcabcb","abcac","babcbabcabcbabcabcba"
//   0123456   01234   01234567890123456789
};

int main()
{
	trie.clear();
	for(int i=0;i<6;i++)
		trie.insert(p[i]);
	//cout<<"insert ok! "<<pool.na<<endl;
	trie.build();
	/*
	for(int i=0;i<pool.na;i++)
	{
		cout<<i<<" "<<pool.a[i].c<<" ";
		if(pool.a[i].nxt) cout<<(pool.a[i].nxt-pool.a)<<endl;
		else cout<<"*"<<endl;
	}
	cout<<"build ok!"<<endl;
	*/
	for(int i=0;i<3;i++)
		cout<<trie.query(t[i])<<endl;
	return 0;
}