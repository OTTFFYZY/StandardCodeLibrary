#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define Debug
const int M=305;
const double EPS=1e-8;
template<typename T>
struct Ma // Matrix
{
	T a[M][M];
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
	T* operator[](const int n)
	{
		return a[n];
	}
	// gauss elimination
	// sum(a[i][j])=a[i][m] (0<=j<m)
	// a[n][i] are solutions
	int gauss()
	{
		int r,c,mr,i,j;
		for(r=0,c=0;r<n&&c<m;r++,c++) // trianglarization
		{
			mr=r;
			for(i=r+1;i<n;i++)
				if(fabs(a[i][c])>fabs(a[mr][c])) mr=i;
			if(fabs(a[mr][c])<EPS)
			{
				r--; continue;
			}
			for(i=c;i<=m;i++) swap(a[r][i],a[mr][i]);
			for(i=r+1;i<n;i++)
			{
				T t=a[i][c]/a[r][c];
				for(j=c;j<=m;j++)
					a[i][j]-=t*a[r][j];
			}
		}
		for(i=r;i<n;i++)
			if(fabs(a[i][m])>EPS) return -1; // no solution
		if(r<m) return m-r; // m-r free variables multiple solutions
		for(i=m-1;i>=0;i--) // only m equations are meaningful
		{
			T t=a[i][m];
			for(j=i+1;j<m;j++)
				t-=a[n][j]*a[i][j];
			a[n][i]=t/a[i][i];
		}
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
Ma<double> A;

int main()
{
	A.clear(3,3);
	A[0][0]=1; A[0][1]=2; A[0][2]=3; A[0][3]=5;
	A[1][0]=1; A[1][1]=2; A[1][2]=1; A[1][3]=8;
	A[2][0]=1; A[2][1]=1; A[2][2]=1; A[2][3]=6;
	A.gauss();
	A.show(1);
	return 0;
}