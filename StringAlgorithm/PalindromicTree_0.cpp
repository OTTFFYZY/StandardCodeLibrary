#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;
const int MB=26;

struct PalindromicTree
{
	struct TN // a node -> an unique palindrome
	{
		int nxt[MB]; // index of the next node
		int fail;    // index of shorter palindrome with same suffix
		int len;     // length of the palindrome
		int cnt;     // number of occurrence (call getcnt)
		int num;     // length of fail chain
	}tn[M];
	char s[M]; // string
	int last;  // index of node of the last parlindrome
	int nn;    // number of nodes
	int n;     // length of the string
	int newnode(int l)
	{
		memset(tn[nn],0,sizeof(TN));
		tn[nn].len=l;
		return nn++;
	}
	void init()
	{
		n=nn=last=0;
		s[0]=-1; // non-existent value
		newnode(0);
		newnode(-1);
		tn[0].fail=1;
	}
	int getfail(int x)
	{
		while(s[n-tn[x].len-1]!=s[n])
			x=tn[x].fail;
		return x;
	}
	void add(int c)
	{
		c-='a';
		s[++n]=c;
		int cur=getfail(last);
		if(!tn[cur].nxt[c]) // new palindrome
		{
			int now=newnode(tn[cur].len+2);
			tn[now].fail=tn[getfail(tn[cur].fail)].nxt[c];
			tn[cur].nxt[c]=now;
			tn[now].num=tn[tn[now].fail].num+1;
		}
		last=tn[cur].nxt[c];
		tn[last].cnt++;
	}
	void getcnt()
	{
		for(int i=nn-1;i>=0;i--)
			tn[tn[i].fail].cnt+=tn[i].cnt;
	}
};

int main()
{
	return 0;
}