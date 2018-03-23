#include <stdio.h>

template<class T>
struct MomeryPool
{
	T *a,**b; int pa,pb;
	MomeryPool(int MAX)
	{
		a=new T[MAX];
		b=new T*[MAX];
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
	int idx(T *x)
	{
		return x-a;
	}
};
MomeryPool<int> mp(5);

int main()
{
	return 0;
}