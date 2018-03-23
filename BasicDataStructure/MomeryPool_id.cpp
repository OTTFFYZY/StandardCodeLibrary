#include <stdio.h>

const int M=1e5;

struct IdPool
{
	int b[M];
	int pa,pb;
	MomeryPool(){pa=pb=0;}
	int add()
	{
		return pb?b[--pb]:pa++;
	}
	void del(int id)
	{
		b[pb++]=id;
	}
};

int main()
{
	return 0;
}