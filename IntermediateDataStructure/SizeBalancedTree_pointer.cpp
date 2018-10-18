struct TN
{
    TN *ch[2];
    int v;
    int size;
    TN():v(0),size(0){ch[0]=ch[1]=NULL;}
};
struct SBT
{
    TN *root,*zero;
    SBT():root(NULL){}
    void init()
    {
        root=zero=new TN();
        zero->ch[0]=zero->ch[1]=zero;
    }
    void rot(TN *&t,int lr) //l 0 r 1
    {
        TN *k=t->ch[lr^1];
        t->ch[lr^1]=k->ch[lr];
        k->ch[lr]=t;
        k->size=t->size;
        t->size=t->ch[0]->size+t->ch[1]->size+1;
        t=k;
    }
    void maintain(TN *&t,int lr)
    {
        if(!t||!t->ch[0]||!t->ch[1]) return;
        if(t->ch[lr]->ch[lr]!=NULL&&t->ch[lr]->ch[lr]->size > t->ch[lr^1]->size)
            rot(t,lr^1);
        else if(t->ch[lr]->ch[lr^1]!=NULL&&t->ch[lr]->ch[lr^1]->size > t->ch[lr^1]->size)
        {
            rot(t->ch[lr],lr);
            rot(t,lr^1);
        }
        else return;
        maintain(t->ch[0],0);
        maintain(t->ch[1],1);
        maintain(t,0);
        maintain(t,1);
    }
    void insert(TN *&t,int v)
    {
        if(t==zero)
        {
            t=new TN();
            t->ch[0]=t->ch[1]=zero;
            t->size=1; t->v=v;
        }
        else
        {
            t->size++;
            if(v<t->v)
                insert(t->ch[0],v);
            else
                insert(t->ch[1],v);
            maintain(t,v>=t->v);
        }
    }
    void show(TN *t)
    {
        if(!t)
        {
            cout<<"null"<<endl;
            return;
        }
        cout<<t->v<<" "<<t->size<<endl;
        show(t->ch[0]);
        show(t->ch[1]);
    }
    int kth(TN *t,int k)
    {
        //cout<<t->v<<" "<<t->size<<endl;
        int r=(t->ch[0]==NULL?0:t->ch[0]->size)+1;
        if(r==k)
            return t->v;
        if(k<r)
            return kth(t->ch[0],k);
        else
            return kth(t->ch[1],k-r);
    }
}sbt;