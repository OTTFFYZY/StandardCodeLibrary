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
	Ma trianlgle() //upper trianglarization n=m
	{
		for(int i=0;i<n;i++)
		{
			int r=i;
			for(int j=i+1;j<n;j++)
				if(fabs(a[j][i])>fabs(a[r][i])) r=j;
			for(int j=i;j<n;j++) swap(a[i][j],a[r][j]);
			if(fabs(a[i][i])<EPS) continue;
		    //if(a[i][i]==0) continue;
			for(int j=i+1;j<n;j++)
			{
				T t=a[j][i]/a[i][i];
				for(int k=i;k<n;k++)
					a[j][k]-=t*a[i][k];
			}
		}
		return *this;
	}
	T det() //determinant
	{
		trianlgle();
		T ans=1;
		for(int i=0;i<n;i++)
			ans*=a[i][i];
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
};
Ma<double> A(3,3);

int main()
{
	A[0][0]=1; A[0][1]=2; A[0][2]=3;
	A[1][0]=1; A[1][1]=2; A[1][2]=1;
	A[2][0]=1; A[2][1]=1; A[2][2]=1;
	A.trianlgle();
	A.show();
	cout<<"Determinant: |A| = "<<A.det()<<endl;
	return 0;
}