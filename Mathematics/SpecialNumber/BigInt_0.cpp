const int M=10005;
const int BASE=10000;
struct BN
{
	int n;
	int a[M/4]; //10^4=10000
	BN():n(1)
	{
		memset(a,0,sizeof(a));
	}
	BN(int i)
	{
		n=0;
		while(i)
		{
			a[n++]=i%BASE;
			i/=BASE;
		}
	}
	BN operator*(const BN &B) const
	{
		BN ans;
		ans.n=n+B.n;
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
		while(ans.n>1&&!ans.a[ans.n-1])
			ans.n--;
		return ans;
	}
	void print()
	{
		printf("%d",a[n-1]);
		for(int i=n-2;i>=0;i--)
			printf("%04d",a[i]);
		printf("\n");
	}
};