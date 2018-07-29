#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <random>
#include <math.h>
using namespace std;

int randn(int l,int r) // generate random number in range [l,r]
{
	return rand()*rand()%(r-l+1)+l;
}
double randd(int l,int r,int eps) // generate random number in range [l/10^eps,r/10^eps]
{
	return (rand()*rand()%(r-l+1)+l)/pow(10.0,eps);
}
double randd(int l,int r,double eps) // generate random number in range [l*eps,r*eps]
{
	return (rand()*rand()%(r-l+1)+l)*eps;
}

int main()
{
	cout<<RAND_MAX<<endl;
	srand(time(0));
	for(int i=0;i<10;i++)
		cout<<rand()<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<randn(1,50)<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<randd(100,200,3)<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<randd(100,2000,0.00001)<<" ";
	cout<<endl;
}