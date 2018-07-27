#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <random>
using namespace std;

int randn(int a,int b) // generate random number in range [a,b]
{
	return rand()*rand()%(b-a+1)+a;
}

int main()
{
	cout<<RAND_MAX<<endl;
	srand(time(0));
	for(int i=0;i<10;i++)
		cout<<rand()<<endl;
	for(int i=0;i<10;i++)
		cout<<randn(1,50)<<endl;
}