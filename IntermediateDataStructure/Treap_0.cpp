#include <iostream>
#include <algorithm>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int M=1e5+5;
const int INF=0x3f3f3f3f;
#define ls tn[o].ch[0]
#define rs tn[o].ch[1]

struct TN
{
	int ch[2],rnd;
	int v,size,cnt;
};
struct Treap
{
	TN tn[M];
	int n;
	int rand()
	{
		static int seed=23333;
		return seed=(int)((((seed^998244353)+1926081711)
					*1989060411)%1000000007);
	}
	void update(int o)
	{
		tn[o].size=tn[ls].size+tn[rs].size+tn[o].cnt;
	}
	void rot(int &o,int lr) // lr: 0 l, 1 r
	{
		int t=tn[o].ch[lr^1]; 
		tn[o].ch[lr^1]=tn[t].ch[lr];
		tn[t].ch[lr]=o;
		tn[t].size=tn[o].size;
		update(o);
		o=t;
	}
	void ins(int &o,int v)
	{
		if(!o)
		{
			o=++n;
			ls=rs=0;
			tn[o].rnd=rand();
			tn[o].size=tn[o].cnt=1;
			tn[o].v=v;
			return;
		}
		tn[o].size++;
		if(tn[o].v==v)
		{
			tn[o].cnt++;
			return;
		}
		if(v<tn[o].v)
		{
			ins(ls,v);
			if(tn[ls].rnd<tn[o].rnd) rot(o,0);
		}
		else
		{
			ins(rs,v);
			if(tn[rs].rnd<tn[o].rnd) rot(o,1);
		}
	}
	void del(int &o,int v)
	{
		//if(!o) return;
		tn[o].size--;
		if(tn[o].v==v)
		{
			if(tn[o].cnt>1) tn[o].cnt--;
			else
			{
				if(!ls||!rs) o=ls+rs;
				else 
				{
					if(tn[ls].rnd<tn[rs].rnd) rot(o,1);
					else rot(o,0);
					del(o,v);
				}
			}
			return;
		}
		if(v<tn[o].v) del(ls,v);
		else del(rs,v);
	}
	int rank(int o,int v)
	{
		if(!o) return 0;
		if(tn[o].v==v) return tn[ls].size+1;
		if(v<tn[o].v) return rank(ls,v);
		else return rank(rs,v)+tn[ls].size+tn[o].cnt;
	}
	int kth(int o,int k)
	{
		if(k<=tn[ls].size) return kth(ls,k);
		k-=tn[ls].size;
		if(k<=tn[o].cnt) return tn[o].v;
		else return kth(rs,k-tn[o].cnt);
	}
	int pre(int o,int v)
	{
		if(!o) return -INF;
		if(v<=tn[o].v) return pre(ls,v);
		else return max(pre(rs,v),tn[o].v);
	}
	int suc(int o,int v)
	{
		if(!o) return INF;
		if(v<tn[o].v) return min(suc(ls,v),tn[o].v);
		else return suc(rs,v);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}