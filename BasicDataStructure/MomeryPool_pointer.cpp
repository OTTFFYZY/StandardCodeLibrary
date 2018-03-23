#include <stdio.h>

const int M=1e5;

template<class T>
struct MomeryPool
{
	T a[M],*b[M];
	int pa,pb;
	MomeryPool()
	{
		pa=pb=0;
	}
	T* add()
	{
		return pb?b[--pb]:&a[pa++];
	}
	void del(T *x)
	{
		b[pb++]=x;
	}
};

int main()
{
	return 0;
}