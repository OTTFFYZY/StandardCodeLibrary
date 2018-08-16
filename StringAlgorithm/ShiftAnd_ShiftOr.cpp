#include <iostream>
#include <string.h>
#include <bitset> // if P[] is long, we need bitset
using namespace std;

const int MT=1e6+5;
const int MP=65;
char t[MT]="abcabcab",p[MP]="abcab";

unsigned int b[128]; //ascii
void get_b(char p[],int m)
{
	memset(b,0,sizeof(b));
	unsigned int shift=1;
	for(int i=0;i<m;i++)
	{
		b[p[i]]|=shift;
		shift<<=1;
	}
}
bool is_match[MT];
void shift_and(char t[],int n,char p[],int m)
{
	get_b(p,m);
	memset(is_match,0,sizeof(is_match));
	unsigned int mask=1<<(m-1),d=0;
	for(int i=0;i<n;i++)
	{
		d=(d<<1|1)&b[t[i]];
		if(d&mask) is_match[i-m+1]=1;
	}
}

void get_b21(char p[],int m)
{
	memset(b,~0,sizeof(b));
	unsigned int shift=1;
	for(int i=0;i<m;i++)
	{
		b[p[i]]&=~shift;
		shift<<=1;
	}
}
unsigned int get_b22(char p[],int m)
{
	memset(b,~0,sizeof(b));
	unsigned int shift=1,lim=0;
	for(int i=0;i<m;i++)
	{
		b[p[i]]&=~shift;
		lim|=shift;
		shift<<=1;
	}
	return ~(lim>>1);
}
void shift_or(char t[],int n,char p[],int m)
{
	//get_b21(p,m);
	unsigned int lim=get_b22(p,m);
	memset(is_match,0,sizeof(is_match));
	unsigned int mask=~(1<<(m-1)),d=~0;
	for(int i=0;i<n;i++)
	{
		d=d<<1|b[t[i]];
		//if(~(d|mask)) is_match[i-m+1]=1;
		if(d<lim) is_match[i-m+1]=1;
	}
}

int main()
{
	int n=strlen(t),m=strlen(p);
	shift_and(t,n,p,m);
	for(int i=0;i<n;i++)
		cout<<(int)is_match[i]<<" ";
	cout<<endl<<endl;
	
	shift_or(t,n,p,m);
	for(int i=0;i<n;i++)
		cout<<(int)is_match[i]<<" ";
	cout<<endl<<endl;
	return 0;
}