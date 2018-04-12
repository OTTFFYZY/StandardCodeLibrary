#include <stdio.h>
#include <algorithm>
using namespace std;

int bs(int key,int n,int a[])
{
	int l=0,r=n-1,m;
	while(l<=r)
	{
		m=((r-l)>>1)+l;
		if(a[m]==key) return m;
		else if(a[m]<key) l=m+1;
		else r=m-1;
	}
	return -1;
}

int lowerbound(int key,int n,int a[])
{
	int l=0,r=n-1,m,ans=n;
	while(l<=r)
	{
		m=((r-l)>>1)+l;
		if(a[m]>=key)
		{
			ans=min(m,ans);
			r=m-1;
		}
		else l=m+1;
	}
	return ans==n?-1:ans;
}
int upperbound(int key,int n,int a[])
{
	int l=0,r=n-1,m,ans=n;
	while(l<=r)
	{
		m=((r-l)>>1)+l;
		if(a[m]>key)
		{
			ans=min(m,ans);
			r=m-1;
		}
		else l=m+1;
	}
	return ans==n?-1:ans;
}

bool check1(int m)
{
	return 1; //check something
}
int bs1(int l,int r)
{
	int m,ans=r+1;
	while(l<=r)
	{
		m=((r-l)>>1)+l;
		if(check1(m))
		{
			ans=min(m,ans);
			r=m-1;
		}
		else l=m+1;
	}
	return ans==r+1?-1:ans;
}

const double EPS=1e-8;
bool check2(double m)
{
	return 1; //check something
}
double bs2(double l,double r)
{
	double m,ans=r;
	while(l+EPS<r)
	{
		m=(l+r)/2.0;
		if(check2(m))
		{
			ans=min(m,ans);
			r=m;
		}
		else l=m;
	}
	return ans;
}
double bs2_1(double l,double r)
{
	double m,ans=r;
	int k=50;
	while(k--)
	{
		m=(l+r)/2.0;
		if(check2(m))
		{
			ans=min(m,ans);
			r=m;
		}
		else l=m;
	}
	return ans;
}


int main()
{
	return 0;
}