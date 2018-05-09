#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1e5+5;
char s[M]="abaaba";
char ms[M*2];
int mp[M*2];

void manacher(char s[],int n,char ms[],int mp[])
{
	int l=2;
	ms[0]='$'; ms[1]='#';
	for(int i=0;i<n;i++)
	{
		ms[l++]=s[i];
		ms[l++]='#';
	}
	ms[l]=0;
	int p=0,o=0;
	for(int i=1;i<l;i++)
	{
		int k=p>i?min(mp[2*o-i],p-i):1;
		while(ms[i+k]==ms[i-k]) k++;
		if(i+k>p)
		{
			p=i+k;
			o=i;
		}
		mp[i]=k;
	}
}


int main()
{
	int n=strlen(s);
	manacher(s,n,ms,mp);
	for(int i=0;i<2*n+2;i++)
		cout<<ms[i]<<" ";
	cout<<endl;
	for(int i=0;i<2*n+2;i++)
		cout<<mp[i]<<" ";
	cout<<endl;
	return 0;
}
