class Solution {
public:
    typedef long long LL;
    const LL MO=1e9+7;
    struct Event
    {
        int y,l,r,k;
        Event(int y=0,int l=0,int r=0,int k=0)
            :y(y),l(l),r(r),k(k){}
        bool operator<(const Event &B) const
        {
            return y==B.y?k>B.k:y<B.y;
        }
    };
    struct TN
    {
        int l,r;
        int add,cover;
        TN *ls,*rs;
        TN(int l=0,int r=0)
            :l(l),r(r),add(0),cover(0),ls(NULL),rs(NULL){}
        TN* lson()
        {
            if(ls!=NULL) return ls;
            else return ls=new TN(l,(l+r)/2);
        }
        TN* rson()
        {
            if(rs!=NULL) return rs;
            else return rs=new TN((l+r)/2+1,r);
        }
        void update(int ul,int ur,int v)
        {
            //cout<<l<<" "<<r<<" "<<ul<<" "<<ur<<endl;
            if(ul>ur) return;
            if(l==ul&&r==ur)
                add+=v;
            else
            {
                int mid=(l+r)/2;
                if(ul<=mid) lson()->update(ul,min(ur,mid),v);
                if(ur>mid) rson()->update(max(mid+1,ul),ur,v);
            }
            //cout<<add<<endl;
            if(add) cover=r-l+1;
            else cover=lson()->cover+rson()->cover;
            //cout<<l<<" "<<r<<" cover "<<cover<<endl;
        }
    }*root;
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        if(!rectangles.size()) return 0;
        vector<Event> event;
        for(auto rec:rectangles)
        {
            event.emplace_back(rec[1],rec[0],rec[2]-1,1);
            event.emplace_back(rec[3],rec[0],rec[2]-1,-1);
        }
        sort(event.begin(),event.end());
        LL ans=0,py=event[0].y;
        root=new TN(0,1e9);
        for(auto ev:event)
        {
            ans=(ans+(ev.y-py)*root->cover%MO)%MO;
            py=ev.y;
            //cout<<"!! "<<root->cover<<" "<<ans<<endl;
            root->update(ev.l,ev.r,ev.k);
        }
        return ans;
    }
};