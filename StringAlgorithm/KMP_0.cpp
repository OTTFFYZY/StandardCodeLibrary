#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1e5+5;
char p[M]="abcab";
char t[M]="abcabcabcab";

int nxt[M];
void get_nxt(char p[],int m,int nxt[])
{
	int i=0,j=nxt[0]=-1;
	while(i<m)
	{
		while(j!=-1&&p[i]!=p[j])
			j=nxt[j];
		nxt[++i]=++j;
	}
	//nxt[m]=0;
}
int mp(char t[],int n,char p[],int m,int nxt[])
{
	int i=0,j=0,cnt=0;
	while(i<n)
	{
		while(j!=-1&&t[i]!=p[j])
			j=nxt[j];
		++i;++j;
		if(j==m) cnt++;
	}
	return cnt;
}

void get_nxt2(char p[],int m,int nxt[])
{
	int i=0,j=nxt[0]=-1;
	while(i<m)
	{
		while(j!=-1&&p[i]!=p[j])
			j=nxt[j];
		i++;j++;
		if(p[i]==p[j])
			nxt[i]=nxt[j];
		else nxt[i]=j;
	}
	//nxt[m]=0;
}
int kmp(char t[],int n,char p[],int m,int nxt[])
{
	int i=0,j=0,cnt=0;
	while(i<n)
	{
		while(j!=-1&&t[i]!=p[j])
			j=nxt[j];
		++i;++j;
		if(j==m) cnt++;
	}
	return cnt;
}

int main()
{
	int m=strlen(p),n=strlen(t);
	get_nxt(p,m,nxt);
	cout<<mp(t,n,p,m,nxt)<<endl;
	get_nxt2(p,m,nxt);
	cout<<kmp(t,n,p,m,nxt)<<endl;
	return 0;
}
