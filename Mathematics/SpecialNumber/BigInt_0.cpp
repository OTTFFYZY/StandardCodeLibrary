#include <iostream>
#include <stdio.h>
#include <string.h>

typedef long long LL;

const int M=10005;
const int MB=4;
const int BASE=10000;
struct BN
{
	int n,sgn;
	int a[M/MB]; //10^4=10000
	BN():n(1),sgn(1)
	{
		memset(a,0,sizeof(a));
	}
	BN(LL i)
	{
		n=0; sgn=1;
		if(i<0)
		{
			sgn=-1; i=-i;
		}
		while(i)
		{
			a[n++]=i%BASE;
			i/=BASE;
		}
	}
	BN(char s[])
	{
		n=0; sgn=1;
		int l=strlen(s);
		int k=0,nu=0,t=1;
		for(int i=l-1;i>=0;i--)
		{
			if(k==MB)
			{
				a[n++]=nu;
				k=nu=0;
				t=1;
			}
			nu=nu+(s[i]-'0')*t;
			t*=10;
			k++;
		}
		a[n++]=nu;
		rem_zero();
	}
	void rem_zero()
	{
		while(n>1&&!a[n-1]) n--;
	}
	BN operator=(const BN &B)
	{
		n=B.n; sgn=B.sgn;
		for(int i=0;i<n;i++)
			a[i]=B.a[i];
	}
	bool operator==(const BN &B) const
	{
		if(n!=B.n||sgn!=B.sgn) return 0;
		for(int i=0;i<n;i++)
			if(a[i]!=B.a[i]) return 0;
		return 1;
	}
	bool operator<(const BN &B) const 
	{
		if(sgn!=B.sgn) return sgn<B.sgn;
		if(n!=B.n) return sgn>0 ? n<B.n : n>B.n;
		for(int i=n-1;i>=0;i--)
			if(a[i]!=B.a[i]) 
				return sgn>0 ? a[i]<B.a[i] : a[i]>B.a[i];
		return 0;
	}
	BN operator-() const
	{
		BN ans=*this;
		ans.sgn*=-1;
		return ans;
	}
	BN abs() const
	{
		BN ans=*this;
		ans.sgn=1;
		return ans;
	}
	BN operator+(const BN &B) const
	{
		if(sgn!=B.sgn)
			return *this-(-B);
	}
	BN operator*(const BN &B) const
	{
		BN ans;
		ans.n=n+B.n;
		ans.sgn=sgn*B.sgn;
		int x;
		for(int i=0;i<n;i++)
		{
			x=0;
			for(int j=0;j<B.n;j++)
			{
				x=a[i]*B.a[j]+x+ans.a[i+j];
				ans.a[i+j]=x%BASE;
				x/=BASE;
			}
			ans.a[i+B.n]=x;
		}
		ans.rem_zero();
		return ans;
	}
	void print()
	{
		printf("%d",a[n-1]*sgn);
		for(int i=n-2;i>=0;i--)
			printf("%04d",a[i]); // MB=4
		printf("\n");
	}
};

char s1[]="0";
char s2[]="01";
char s3[]="123";
char s4[]="1234";
char s5[]="12345";
char s6[]="123456789012";

int main()
{
	BN a1(s1),a2(s2),a3(s3),a4(s4),a5(s5),a6(s6);
	a1.print();
	a2.print();
	a3.print(); 
	a4.print(); 
	a5.print(); 
	a6.print(); 

	return 0;
}