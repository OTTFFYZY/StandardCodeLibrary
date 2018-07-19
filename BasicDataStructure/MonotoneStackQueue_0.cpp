#include <iostream>

const int M=1e5+5;
int st[M],stp; //monotone stack i<j st[i]<st[j]
void init_st()
{
	stp=0;
}
void push(int x)
{
	while(stp&&st[stp]>=x) --stp;
	st[++stp]=x;
}
int top()
{
	return st[stp];
}
void pop()
{
	--stp;
}


int qu[M],qup,quq; //monotone queue i<j qu[i]<qu[j]
void init_qu()
{
	qup=quq=0;
}
void push(int x)
{
	while(quq>qup&&qu[quq-1]>=x) --quq;
	qu[quq++]=x;
}
int front()
{
	return qu[qup];
}
void pop()
{
	++qup;
}