#include <iostream>
#include <stdio.h>
using namespace std;

const int M=1e5+5;

struct PTrie
{
	static const int MC=26;
	static const char BASE='a';
	struct TN
	{
		int word;
		int ch[MC];
		void clear()
		{
			word=0;
			memset(ch,-1,sizeof(ch));
		}
	}tn[M];
	int root[M];
	int nn;
	void init()
	{
		nn=0;
		tn[0].clear();
	}
	int insert(char *s,int o)
	{
		int nr=++nn;
		tn[nr]=tn[o];
		int no=nr;
		int f=0;
		for(;*s;s++)
		{
			int c=*s-BASE;
			tn[no].ch[c]=++nn;
			tn[nn].clear();
			if(f||tn[o].ch[c]==-1)
			{
				f=1;
				
				no=tn[no].ch[c];
			}
			else
			{
				no=tn[no].ch[c];
				o=tn[o].ch[c];
				tn[no]=tn[o];
			}
		}
		tn[nn].word=1;
		return nr;
	}
	int find(char *s,int o)
	{
		for(;*s;s++)
		{
			int c=*s-BASE;
			if(tn[o].ch[c]==-1) return 0;
			o=tn[u].ch[c];
		}
		return tn[o].word==1;
	}
};

int main()
{
	return 0;
}
