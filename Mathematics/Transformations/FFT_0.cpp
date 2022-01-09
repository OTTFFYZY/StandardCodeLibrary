#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

typedef long long LL;

namespace FFT {
	const int M=1<<21;
	const double PI=acos(-1.0);
	struct Complex
	{
		double rl,im;
		Complex(double rl=0.0,double im=0.0):rl(rl),im(im) {}
		Complex operator+(Complex B) { return Complex(rl+B.rl,im+B.im); }
		Complex operator-(Complex B) { return Complex(rl-B.rl,im-B.im); }
		Complex operator*(Complex B) 
		{ return Complex(rl*B.rl-im*B.im,rl*B.im+im*B.rl); }
	};
	int rev[M],l;
	void fft(Complex *A,int n,int op)
	{
		for(int i=1;i<n;i++)		 
			if(i<rev[i]) swap(A[i],A[rev[i]]);
		for(int i=1;i<n;i<<=1)
		{
			Complex W=Complex(cos(PI/i),op*sin(PI/i));
			for(int p=i<<1,j=0;j<n;j+=p)
			{
				Complex w=Complex(1,0);
				for(int k=0;k<i;k++,w=w*W)
				{
					Complex tmp=w*A[j+k+i];
					A[j+k+i]=A[i+k]-tmp; A[j+k]=A[i+k]+tmp;
				}
			}
		}
		if(op==-1) { for(int i=0;i<n;i++) A[i].rl/=n; }
	}
	int mul(Complex *A,int n,Complex *B,int m,Complex *C)
	{
		m+=n; 
		l=0;
		for(n=1;n<=m;n<<=1) l++;
		l--;
		for(int i=0;i<n;i++) 
			rev[i]=(rev[i>>1]>>1)|((i&1)<<l);
		fft(A,n,1); fft(B,n,1);
		for(int i=0;i<n;i++) C[i]=A[i]*B[i];
		fft(C,n,-1);
		return m;
	}
}
using namespace FFT;

Complex A[M],B[M];

char s[M];

int main()
{
	scanf("%s",s);
	int n=strlen(s)-1;
	for(int i=0;i<=n;i++) A[i].rl=s[n-i]-'0';
	scanf("%s",s);
	int m=strlen(s)-1;
	for(int i=0;i<=m;i++) B[i].rl=s[m-i]-'0';
	m=mul(A,n,B,m,A);
	int sum=0;
	int p=M-2;
	int i=0;
	//cout<<m<<endl;
	while(i<=m||sum)
	{
		if(i<=m) sum+=((int)(A[i].rl+0.5));
		//cout<<A[i].rl<<" "<<sum<<endl;
		s[--p]=sum%10+'0';
		sum/=10;
		i++;
	}
	//cout<<endl;
	printf("%s\n",s+p);
	return 0;
}