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
	int* operator[](const int n)
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
	Ma operator*(const Ma &B) const
	{
		Ma ans(n,B.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<B.m;j++)
			{
				if(!a[i][k]) continue;
				for(int k=0;k<m;k++)
					if(B[k][j]) ans[i][j]+=a[i][k]*B[k][j];
			}
		return ans;
	}
};

int main()
{
	
	return 0;
}