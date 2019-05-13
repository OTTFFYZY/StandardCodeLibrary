
int rank[maxn],height[maxn];
void getHeight(int *s,int *sa,int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	return;
}