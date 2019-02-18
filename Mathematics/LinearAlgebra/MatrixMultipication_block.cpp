#include <iostream>
#include <string.h>
using namespace std;

const int M=512;
const int B=8;
template<typename T>
struct Ma // Matrix
{
	T a[M][M];
	int n,m;
	Ma(int n=0,int m=0):n(n),m(m)
	{
		memset(a,0,sizeof(a));
	}
	T* operator[](const int n)
	{
		return a[n];
	}
	Ma operator*(const Ma &B) const
	{
		Ma ans(n,B.m);
		int kk,jj,i,j,k;
		T sum=0;
		for(kk=0;kk<m;kk+=B)
			for(jj=0;jj<B.m;jj+=B)
				for(i=0;i<n;i++)
					for(j=jj;j<jj+B;j++)
					{
						sum=ans[i][j];
						for(k=kk;k<kk+B;k++)
							sum+=a[i][k]*B[k][j];
						ans[i][j]=sum;
					}
		return ans;
	}
};

int main()
{
	return 0;
}