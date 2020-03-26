#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=12;

char g[M+2][M+2];
int n,m;

map<int,LL> dp[2];

int sta[M+2]; // 0 empty 1 left 2 right
void show()
{
	for(int i=0;i<=m;i++)
		cout<<sta[i]<<" ";
	cout<<endl;
}
void remark(int j,int d)
{
	int cnt=0;
	for(int k=j;0<=k&&k<=m;k+=d)
	{
		if(sta[k]==1) cnt++;
		else if(sta[k]==2) cnt--;
		if(!cnt)
		{
			sta[k]=sta[j];
			break;
		}
	}
}
void decode(int st)
{
	for(int i=0;i<=m;i++)
		sta[i]=(st>>(i<<1))&3;
}
int encode()
{
	//cout<<"to :"; show();
	int st=0;
	for(int i=0;i<=m;i++)
		st|=(sta[i]<<(i<<1));
	return st;
}

LL plugdp()
{
	int edx=-1,edy=-1;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
			if(g[i][j]=='.')
			{
				edx=i; edy=j;
				break;
			}
		if(edx!=-1) break;
	}
	//cout<<edx<<" "<<edy<<endl;
	if(edx==-1) return 0;
	dp[1][0]=1;
	int mask=1<<(2*(m+1));
	for(int i=1;i<=n;i++)
	{
		swap(dp[0],dp[1]);
		dp[1].clear();
		for(auto p:dp[0])
		{
			//decode(p.first);
			//show();
			if((p.first<<2) < mask) dp[1][p.first<<2]=p.second;
		}
		for(int j=1;j<=m;j++)
		{
			//cout<<"i j "<<i<<" "<<j<<endl;
			swap(dp[0],dp[1]);
			dp[1].clear();
			for(auto p:dp[0])
			{
				int st=p.first;
				LL w=p.second;
				decode(st);
				//show(); cout<<w<<endl;
				int left=sta[j-1],up=sta[j];
				if(g[i][j]=='*') // block
				{
					if(!left&&!up) // only no plug can transfer
					{
						dp[1][st]+=w;
					}
				}
				else // empty 
				{
					if(!left&&!up)
					{
						if(i==n||j==m) continue;
						sta[j-1]=1; sta[j]=2;
						dp[1][encode()]+=w;
					}
					else if(!left)
					{
						if(j!=m)
							dp[1][encode()]+=w;
						if(i!=n)
						{
							swap(sta[j-1],sta[j]);
							dp[1][encode()]+=w;
						}
					}
					else if(!up)
					{
						if(i!=n)
							dp[1][encode()]+=w;
						if(j!=m)
						{
							swap(sta[j-1],sta[j]);
							dp[1][encode()]+=w;
						}
					}
					else if(left==1&&up==1 || left==2&&up==2)
					{
						remark(j+1-left,left==1?1:-1);
						sta[j-1]=sta[j]=0;
						dp[1][encode()]+=w;
					}
					else if(left==2&&up==1)
					{
						sta[j-1]=sta[j]=0;
						dp[1][encode()]+=w;
					}
					else // left==1&&up==2 loop
					{
						if(i==edx&&j==edy)
						{
							sta[j-1]=sta[j]=0;
							dp[1][encode()]+=w;
						}
					}
				}
			}
			//cout<<endl;
			if(i==edx&&j==edy) break;
		}
		if(i==edx) break;
	}
	return dp[1][0];
}

int main()
{
	// 11 12   14746957510647992
	// 12 12 1076226888605605706
	// LL    9223372036854775807
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	printf("%lld\n",plugdp());
	return 0;
}