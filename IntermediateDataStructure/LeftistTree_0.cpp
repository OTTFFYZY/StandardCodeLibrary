#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;
struct Leftist
{
	int n;
	int k[M],d[M],l[M],r[M];
	void init()
	{
		n=1;
		k[0]=l[0]=r[0];
		d[0]=-1;
	}
	int merge(int a,int b)
	{
		if(!a||!b) return a+b;
		
		if(k[b]<k[a]) swap(a,b);
		r[a]=merge(r[a],b);
		
		if(d[r[a]]>d[l[a]]) swap(l[a],r[a]);
		//if(!r[a]) d[a]=0;
		//else d[a]=d[r[a]]+1;
		d[a]=d[r[a]]+1; //d[0]=-1;
		
		return a;
	}
	int insert(int t,int x)
	{
		k[n]=x;
		d[n]=l[n]=r[n]=0;
		return merge(t,n++);
	}
	int top(int t)
	{
		return k[t];
	}
	int pop(int t)
	{
		return merge(l[t],r[t]);
	}
};

int main()
{
	return 0;
}