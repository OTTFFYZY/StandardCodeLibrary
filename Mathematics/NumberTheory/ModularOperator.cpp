#include <iostream>
using namespace std;

typedef long long LL;

const int MOD=1e9+7;
template<typename T>
struct Num
{
	T a;
	Num(T a=0):a(a){}
	Num mod()
	{
		a%=MOD;
		a=(a+MOD)%MOD;
		return *this;
	}
	Num operator+(const Num &B) const
	{
		return (a+B.a)%MOD;
	}
	Num operator-(const Num &B) const
	{
		return (a-B.a+MOD)%MOD;
	}
	Num operator*(const Num &B) const
	{
		//return (a*b)%MOD; if a,b is small
		Num ans=0,tmp=*this;
		T b=B.a;
		while(b)
		{
			if(b&1) ans=ans+tmp;
			tmp=tmp+tmp;
			b>>=1;
		}
		return ans;
	}
	Num operator^(const Num &B) const
	{
		Num ans=1,tmp=*this;
		T b=B.a;
		while(b)
		{
			if(b&1) ans=ans*tmp;
			tmp=tmp*tmp;
			b>>=1;
		}
		return ans;
	}
	// if MOD is a prime B.a>0
	Num operator/(const Num &B) const
	{
		return (*this)*(B^(MOD-2));
	}
};

int main()
{
	return 0;
}