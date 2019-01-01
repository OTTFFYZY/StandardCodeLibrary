#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef long long LL;

const int M=10005;
const int MB=4;
const int BASE=10000;
char sbi[M];
struct BigInt
{
	int n,sgn;
	int a[M/MB]; //10^4=10000
	BigInt():n(0),sgn(1)
	{
		memset(a,0,sizeof(a));
	}
	BigInt(LL i)
	{
		n=0; sgn=1;
		memset(a,0,sizeof(a));
		if(i<0)
		{
			sgn=-1; i=-i; //error LLMIN
		}
		while(i)
		{
			a[n++]=i%BASE;
			i/=BASE;
		}
	}
	BigInt(char s[])
	{
		n=0; sgn=1;
		memset(a,0,sizeof(a));
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
		trim();
	}
	void trim()
	{
		while(n>1&&!a[n-1]) n--;
	}
	BigInt operator=(const BigInt &B)
	{
		n=B.n; sgn=B.sgn;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			a[i]=B.a[i];
		return *this;
	}
	bool operator==(const BigInt &B) const
	{
		if(n!=B.n||sgn!=B.sgn) return 0;
		for(int i=0;i<n;i++)
			if(a[i]!=B.a[i]) return 0;
		return 1;
	}
	bool operator<(const BigInt &B) const 

	{
		if(sgn!=B.sgn) return sgn<B.sgn;
		if(n!=B.n) return n*sgn<B.n*sgn;
		for(int i=n-1;i>=0;i--)
			if(a[i]!=B.a[i]) 
				return a[i]*sgn<B.a[i]*sgn;
		return 0;
	}
	bool operator>(const BigInt &B) const
	{
		return B<*this;
	}
	bool operator<=(const BigInt &B) const
	{
		return !(*this>B);
	}
	bool operator>=(const BigInt &B) const
	{
		return !(*this<B);
	}
	
	bool operator<(int v) const
	{
		return *this<BigInt(v);
	}
	BigInt operator-() const
	{
		BigInt ans=*this;
		ans.sgn*=-1;
		return ans;
	}
	BigInt abs() const
	{
		BigInt ans=*this;
		ans.sgn=1;
		return ans;
	}
	BigInt operator+(const BigInt &B) const
	{
		if(sgn!=B.sgn)
			return *this-(-B);
		BigInt ans=B;
		int i=0,x=0;
		for(;i<max(n,B.n)||x;i++)
		{
			ans.a[i]+=a[i]+x;
			x=(ans.a[i]>=BASE);
			if(x) ans.a[i]-=BASE;
		}
		ans.n=i;
		return ans;
	}
	BigInt operator-(const BigInt &B) const
	{
		if(sgn!=B.sgn)
			return *this+(-B);
		if(abs()<B.abs()) 
			return -(B-*this);
		BigInt ans=*this;
		for(int i=0,x=0;i<n||x;i++)
		{
			ans.a[i]-=x+B.a[i];
			x=(ans.a[i]<0);
			if(x) ans.a[i]+=BASE;
		}
		ans.trim();
		return ans;
	}
	BigInt operator*(const BigInt &B) const
	{
		BigInt ans;
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
		ans.trim();
		return ans;
	}
	BigInt operator+=(const BigInt &B)
	{
		return *this=*this+B;
	}
	BigInt operator-=(const BigInt &B)
	{
		return *this=*this-B;
	}
	BigInt operator*=(const BigInt &B)
	{
		return *this=*this*B;
	}

	pair<BigInt,BigInt> divmod(const BigInt &B) const
	{
		int norm=BASE/(B.a[B.n-1]+1);
		BigInt a=(this->abs())*norm;
		BigInt b=(B.abs())*norm;
		BigInt q,r;
		q.n=a.n;
		int s1,s2,d;
		for(int i=a.n-1;i>=0;i--)
		{
			r*=BASE;
			r+=a.a[i];
			s1=r.n<b.n ? 0 : r.a[b.n];
			s2=r.n<b.n-1 ? 0 : r.a[b.n-1];
			d=((LL)BASE*s1+s2)/b.a[b.n-1];
			r-=b*d;
			while(r<0)
			{
				r+=b; d--;
			}
			q.a[i]=d;
		}
		q.sgn=sgn*B.sgn;
		r.sgn=sgn;
		q.trim(); r.trim();
		return make_pair(q,r/norm);
	}
	BigInt operator/(const BigInt &B) const
	{
		return divmod(B).first;
	}
	BigInt operator/=(int v)
	{
		if(v<0)
		{
			sgn=-sgn; v=-v;
		}
		for(int i=n-1,r=0;i>=0;i--)
		{
			LL cur=a[i]+(LL)r*BASE;
			a[i]=cur/v;
			r=cur%v;
		}
		trim();
		return *this;
	}
	BigInt operator/(int v) const
	{
		BigInt ans=*this;
		ans/=v;
		return ans;
	}
	BigInt operator%(const BigInt &B) const
	{
		return divmod(B).second;
	}
	int operator%(int v) const
	{
		if(v<0)
			v=-v;
		int m=0;
		for(int i=n-1;i>=0;i--)
			m=(a[i]+m*(LL)BASE)%v;
		return m*sgn;
	}

	void read()
	{
		scanf("%s",sbi);
		*this=BigInt(sbi);
	}
	void print()
	{
		printf("%d",a[n-1]*sgn);
		for(int i=n-2;i>=0;i--)
			printf("%04d",a[i]); // MB=4
		//printf("\n");
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
	/*
	BigInt a1(s1),a2(s2),a3(s3),a4(s4),a5(s5),a6(s6);
	a1.print();
	a2.print();
	a3.print(); 
	a4.print(); 
	a5.print(); 
	a6.print(); 
	*/

	srand(time(0));
	for(int i=0;i<10;i++)
	{
		LL a=(rand()%2?1:-1)*((LL)rand()*rand());
		LL b=(rand()%2?1:-1)*((LL)rand());
		cout<<a<<" "<<b<<endl;
		cout<<a+b<<" "<<a-b<<" "<<a*b<<" "<<a/b<<" "<<a%b<<endl;
		BigInt A(a),B(b);
		A.print(); cout<<" "; B.print(); cout<<endl;
		(A+B).print(); cout<<" ";
		(A-B).print(); cout<<" ";
		(A*B).print(); cout<<" ";
		(A/B).print(); cout<<" ";
		(A%B).print(); cout<<endl<<endl;
	}

	return 0;
}