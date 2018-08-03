#include <iostream>
#include <string.h>
using namespace std;

struct Ma // Circulant Matrix
{
	LL a[MM];
	int n;
	Ma(int n=0):n(n)
	{
		memset(a,0,sizeof(a));
	}
	void clear(int _n)
	{
		n=_n;
		memset(a,0,sizeof(a));
	}
	void uni()
	{
		memset(a,0,sizeof(a));
		a[0]=1;
	}
	LL& operator[](int i)
	{
		return a[i];
	}
	Ma operator=(const Ma &B)
	{
		n=B.n;
		for(int i=0;i<n;i++)
			a[i]=B.a[i];
		return *this;
	}
	Ma operator*(const Ma &B) const
	{
		Ma ans(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				ans[i]+=a[j]*B.a[(i-j+n)%n]%MO;
				ans[i]%=MO;
			}
		return ans;
	}
	Ma operator^(LL nn) const
	{
		Ma ans(n),x=*this;
		ans.uni();
		while(nn)
		{
			if(nn&1) ans=ans*x;
			x=x*x;
			nn>>=1;
		}
		return ans;
	}
	LL getv(int i,int j) // value of a(i,j)
	{
		return a[(j-i+n)%n];
	}
	void show()
	{
	    for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
	}
};

int main()
{
	
	return 0;
}