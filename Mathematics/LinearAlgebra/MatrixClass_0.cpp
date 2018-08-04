#include <iostream>
#include <string.h>
using namespace std;

const int M=305;
template<typename T>
struct Ma // Matrix
{
	T a[M][M];
	int n,m;
	Ma(int n=0,int m=0):n(n),m(m)
	{
		memset(a,0,sizeof(a));
	}
	void uni()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			a[i][i]=1;
	}
	void clear(int _n,int _m)
	{
		n=_n; m=_m;
		memset(a,0,sizeof(a));
	}
	T* operator[](const int n)
	{
		return a[n];
	}
	Ma operator=(const Ma &B)
	{
		n=B.n; m=B.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=B[i][j];
		return *this;
	}
	Ma operator+(const Ma &B) const
	{
		Ma ans=B;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[i][j]+=a[i][j];
		return ans;
	}
	Ma operator-(const Ma &B) const
	{
		Ma ans=*this;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[i][j]-=B[i][j];
		return ans;
	}
	Ma operator*(T x) const
	{
		Ma ans=*this;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[i][j]=a[i][j]*x;
		return ans;
	}
	Ma operator*(const Ma &B) const
	{
		Ma ans(n,B.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<B.m;j++)
				for(int k=0;k<m;k++)
					ans[i][j]+=a[i][k]*B[k][j];
		return ans;
	}
	Ma operator^(int nn) const
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
	void show()
	{
		#ifdef Debug
			cout<<"Matrix:"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
		#endif
	}
	Ma trans() // transpose
	{
		Ma ans(m,n);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ans[j][i]=a[i][j];
		return ans;
	}
};
Ma<int> A(5);

int main()
{
	A.uni();
	cout<<A[0][0]<<endl;
	return 0;
}