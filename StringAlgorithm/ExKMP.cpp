#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1e5+5;
char p[M]="abcab";
char t[M]="abcabcabcab";

int nxt[M],ex[M];
void get_nxt(char p[],int m,int nxt[])
{
	nxt[0]=m;
	int j=-1,a,l;
	for(int i=1;i<m;i++,j--)
	{
		if(j==-1||i+nxt[i-a]>=l)
		{
			if(j==-1) j=0,l=i;
			for(;l<m&&j<m&&p[l]==p[j];l++,j++);
			nxt[i]=j; a=i;
		}
		else nxt[i]=nxt[i-a];
	}
}
void exkmp(char t[],int n,char p[],int m,int nxt[],int ex[])
{
	int j=-1,a,l;
	for(int i=0;i<n;i++,j--)
	{
		if(j==-1||i+nxt[i-a]>=l)
		{
			if(j==-1) j=0,l=i;
			for(;l<n&&j<m&&t[l]==p[j];l++,j++);
			ex[i]=j; a=i;
		}
		else ex[i]=nxt[i-a];
	}
}


int main()
{
	int m=strlen(p),n=strlen(t);
	get_nxt(p,m,nxt);
	for(int i=0;i<m+1;i++)
		cout<<nxt[i]<<" ";
	cout<<endl;
	exkmp(t,n,p,m,nxt,ex);
	for(int i=0;i<n;i++)
		cout<<ex[i]<<" ";
	cout<<endl;
	return 0;
}
