int block(int n)
{
	for(int i=1;i<=n;)
	{
		l = i;
		r = n/(n/i);
		
		// do something
		
		i=r+1;
	}
}