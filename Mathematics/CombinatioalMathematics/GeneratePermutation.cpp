#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int M=10;
int p[M],vis[M];

void dfs(int n,int m,int cur)  // P(n,m)
{
	if(cur==m)
	{
		for(int i=0;i<m;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[cur]=i;
			dfs(n,m,cur+1);
			vis[i]=0;
		}
	}
}

int num[M];   // num[i]   the number of i
void dfs2(int n,int m,int cur)  //have same element
{
	if(cur==m)
	{
		for(int i=0;i<m;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]<num[i])
		{
			vis[i]++;
			p[cur]=i;
			dfs2(n,m,cur+1);
			vis[i]--;
		}
	}
}

int main()
{
	memset(vis,0,sizeof(vis));
	dfs(5,5,0);
	dfs(5,3,0);

	cout<<endl<<endl;

	num[0]=2;num[1]=3;num[2]=1;
	dfs2(3,6,0);

	return 0;
}