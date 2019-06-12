#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

const int M=1e4;
const int ML=1005;
const int MB=26;
string a[M];
int n;

int id[M];
int cnt[MB],tmp[M];
vector<int> len[ML];
void radix_sort()
{
	for(int i=0;i<ML;i++)
		len[i].clear();
	int maxl=0;
	for(int i=0;i<n;i++)
	{
		maxl=max(maxl,(int)a[i].length());
		len[a[i].length()].push_back(i);
	}
	int m=0;
	for(int i=maxl-1;i>=0;i--)
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<m;j++)
			cnt[a[id[j]][i]-'a']++;
		int k=0;
		for(int j:len[i+1])
		{
			cnt[a[j][i]-'a']++;
			tmp[k++]=j;
		}
		for(int i=0;i<m;i++)
			tmp[k++]=id[i];
		m=k;
		for(int j=1;j<MB;j++)
			cnt[j]+=cnt[j-1];
		for(int j=m-1;j>=0;j--)
			id[--cnt[a[tmp[j]][i]-'a']]=tmp[j];
	}
}

int main()
{
	n = 6;
	a[0] = "abcde";
	a[1] = "acbs";
	a[2] = "bcade";
	a[3] = "abdac";
	a[4] = "a";
	a[5] = "abcdefaf";
	radix_sort();
	for(int i=0;i<n;i++)
		cout<<a[id[i]]<<endl;
	return 0;
}