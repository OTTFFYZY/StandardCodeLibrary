#include <iostream>
#include <string.h>
#include <bitset>
#include <math.h>
using namespace std;

#define Debug
const int M=305;
const double EPS=1e-8;
struct Ma // Matrix
{
	bitset<M> a[M];
	int n,m;
	Ma(int n=0,int m=0):n(n),m(m)
	{
		for(int i=0;i<n;i++)
			a[i].reset();
	}
	void clear(int _n,int _m)
	{
		n=_n; m=_m;
		for(int i=0;i<n;i++)
			a[i].reset();
	}
	bitset<M>& operator[](const int n)
	{
		return a[n];
	}
	// gauss elimination
	// xor_sum(a[i][j])=a[i][m] (0<=j<m)
	// a[n][i] are solutions
	int gauss()
	{
		int r,c,mr,i,j;
		for(r=0,c=0;r<n&&c<m;r++,c++) // trianglarization
		{
			mr=r;
			while(mr<n&&!a[mr][c]) mr++;
			if(!a[mr][c])
			{
				r--; continue;
			}
			swap(a[r],a[mr]);
			for(i=0;i<n;i++)
				if(i!=r&&a[i][c]) a[i]^=a[r];
		}
		for(i=r;i<n;i++)
			if(a[i][m]) return -1; // no solution
		if(r<m) return m-r; // m-r free variables multiple solutions
		for(i=0;i<m;i++) // only m equations are meaningful
			a[n][i]=a[i][m];
		return 0; // 1 solution
	}
	void show(int aug=0) //printed augmented matrix
	{
		#ifdef Debug
			cout<<"Matrix:"<<endl;
			for(int i=0;i<n+aug;i++)
			{
				for(int j=0;j<m+aug;j++)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
		#endif
	}
};
Ma A(3,3);

int main()
{
	A.clear(3,3);
	A[0][0]=1; A[0][1]=1; A[0][2]=1; A[0][3]=1;
	A[1][0]=1; A[1][1]=0; A[1][2]=1; A[1][3]=0;
	A[2][0]=0; A[2][1]=0; A[2][2]=1; A[2][3]=1;
	A.gauss();
	A.show(1);
	return 0;
}