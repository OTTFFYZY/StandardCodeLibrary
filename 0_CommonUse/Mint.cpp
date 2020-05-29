const int MO=20130427;

struct Mint
{
	int x;
	Mint(int x=0):x(x){}
	Mint operator=(int x_) { x=x_; return *this; }
	void norm() { x=(x%MO+MO)%MO; }
	Mint operator+(const Mint &B) const { int ans=x+B.x; if(ans>=MO) ans-=MO; return Mint(ans); }
	Mint operator-(const Mint &B) const { int ans=x-B.x; if(ans<0) ans+=MO; return Mint(ans); }
	Mint operator*(const Mint &B) const { int ans=1LL*x*B.x%MO; return Mint(ans); }
	Mint operator+=(const Mint &B) { x+=B.x; if(x>=MO) x-=MO; return *this; }
	Mint operator-=(const Mint &B) { x-=B.x; if(x<0) x+=MO; return *this; }
	Mint operator*=(const Mint &B) { x=1LL*x*B.x%MO; return *this; }
	Mint operator^(int n) const 
	{
		Mint a=*this,ans(1);
		while(n) { if(n&1) ans*=a; a*=a; n>>=1; }
		return ans;
	}
	bool operator==(int b) const { return x==b; }
	bool operator!=(int b) const { return x!=b; }
	bool operator==(const Mint &B) const { return x==B.x; }
	bool operator!=(const Mint &B) const { return x!=B.x; }
	int toi() { return x; }

	void read() { scanf("%d",&x); }
	void print() { printf("%d",x); }
	friend istream &operator<<(istream& in, Mint &B) { in>>B.x; return in; }
	friend ostream &operator<<(ostream& out, const Mint &B) { out<<B.x; return out; }
};