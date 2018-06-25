const int M=1e8;
int bitmap[M/32+32];
int pri[M/32];

void getpri()
{
    for(int i=3;i*i<M;i+=2)
        if(bitmap[i/32]&(1<<(i/2
