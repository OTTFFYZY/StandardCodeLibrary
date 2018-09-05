const int M=1e5+5;
char s[M];
int smp(char s[],int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		int tmp=s[(i+k)%n]-s[(j+k)%n];
		if(!tmp) k++;
		else
		{
			if(tmp>0) i+=k+1;
			else j+=k+1;
			if(i==j) j++;
			k=0;
		}
	}
	return min(i,j);
}