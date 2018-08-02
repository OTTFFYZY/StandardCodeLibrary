#include <iostream>
#include <string.h>
using namespace std;

const int MM=25;
const int MO=1e9+7;
typedef long long LL;
struct Ma // Matrix
{
	LL a[MM][MM];
	int n,m;
	Ma(int n=0,int m=0):n(n),m(m)
	{
		memset(a,0,sizeof(a));
	}
	void clear(int _n,int _m)
	{
		n=_n; m=_m;
		memset(a,0,sizeof(a));
	}
	void uni()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			a[i][i]=1;
	}
	Ma operator=(const Ma &B)
	{
		n=B.n; m=B.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=B.a[i][j];
		return *this;
	}
	Ma operator*(const Ma &B) const
	{
		Ma ans(n,B.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<B.m;j++)
				for(int k=0;k<m;k++)
				{
					ans.a[i][j]+=a[i][k]*B.a[k][j]%MO;
					ans.a[i][j]%=MO;
				}
		return ans;
	}
	Ma operator^(LL nn) const
	{
		Ma ans(n,n),x=*this;
		ans.uni();
		while(nn)
		{
			if(nn&1) ans=ans*x;
			x=x*x;
			nn>>=1;
		}
		return ans;
	}
};

// f[m]=a[0]*f[0]+a[1]*f[1]+a[2]*f[2]+...+a[m-1]*f[m-1]
int a[MM],f[MM],m;
Ma Ans,A,B; // Ans = B^n * A
LL getv(LL n)
{
	if(n<m) return f[n];
	A.clear(1,m);
	for(int i=0;i<m;i++)
		A.a[i][0]=f[m-1-i];
	B.clear(m,m);
	for(int i=0;i<m;i++)
		B.a[0][i]=a[m-1-i];
	for(int i=1;i<m;i++)
		B.a[i][i-1]=1;
	Ans=(B^(n-m+1))*A;
	return Ans.a[0][0];
}

int main()
{
	m=2; f[0]=1; f[1]=1; a[0]=1; a[1]=1;
	// 1 1 2 3 5 8 13
	// 0 1 2 3 4 5 6
	cout<<getv(5)<<endl;
	return 0;
}