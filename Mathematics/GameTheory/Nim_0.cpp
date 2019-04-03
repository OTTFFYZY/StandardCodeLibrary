bool nim(int n)
{
	return n;
}

const int M=1e5+5;
int a[M];
bool nnim(int n)
{
	int sg=0;
	for(int i=0;i<n;i++)
		sg^=a[i];
	return sg;
}