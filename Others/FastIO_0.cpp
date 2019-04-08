#define OPT __attribute__((optimize("O2")))

template <class T>
OPT void read(T &x)
{
    char c; bool op=0;
    while(c=getchar(),c<'0'||'9'<c)
    	if(c=='-') op=1;
    x=c-'0';
    while(c=getchar(),'0'<=c&&c<='9')
    	x=x*10+c-'0';
    if(op) x=-x;
}
template <class T>
OPT void write(T x)
{
    if(x<0) x=-x;
    if(x>10) write(x/10);
    putchar('0'+x%10);
}