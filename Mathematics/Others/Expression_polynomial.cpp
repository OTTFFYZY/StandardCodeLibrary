class Solution {
public:
    map<string,int> stov;
    
    struct Exp
    {
        map<multiset<string>,int> ma;
        Exp(int v=0)
        {
            ma.clear();
            multiset<string> tmp;
            //tmp.insert("");
            ma[tmp]=v;
        }
        Exp(string s)
        {
            //cout<<s<<endl;
            ma.clear();
            multiset<string> tmp;
            if(isdigit(s[0]))
            {
                //tmp.insert("");
                ma[tmp]=stoi(s);
            }
            else
            {
                tmp.insert(s);
                ma[tmp]=1;
            }
        }
        Exp operator+(const Exp &B)const
        {
            Exp ans=*this;
            for(auto p:B.ma)
            {
                ans.ma[p.first]+=p.second;
                if(!ans.ma[p.first])
                    ans.ma.erase(p.first);
            }
            return ans;
        }
        Exp operator-(const Exp &B)const
        {
            Exp ans=*this;
            for(auto p:B.ma)
            {
                ans.ma[p.first]-=p.second;
                if(!ans.ma[p.first])
                    ans.ma.erase(p.first);
            }
            return ans;
        }
        Exp operator*(const Exp &B)const
        {
            Exp ans;
            for(auto i:ma)
            {
                for(auto j:B.ma)
                {
                    int v=i.second*j.second;
                    //cout<<v<<endl;
                    if(!v) continue;
                    multiset<string> tmp;
                    for(auto ii:i.first) tmp.insert(ii);
                    for(auto jj:j.first) tmp.insert(jj);
                    ans.ma[tmp]+=v;
                    if(!ans.ma[tmp])
                        ans.ma.erase(tmp);
                }
            }
            return ans;
        }
        void show()
        {
            cout<<"show exp ";
            cout<<ma.size()<<" ";
            for(auto p:ma)
            {
                cout<<p.second;
                for(string s:p.first)
                    cout<<"*"<<s;
                cout<<endl;
            }
        }
    };
    
    stack<Exp> ste;
    stack<char> stc;
    stack<char> stp;
    
    struct Node
    {
        int v;
        vector<string> vec;
        Node(){}
        Node(int v,multiset<string> se):v(v)
        {
            for(string s:se)
                if(s!="") vec.push_back(s);
        }
        bool operator<(const Node &B)const
        {
            return vec.size()==B.vec.size()?vec<B.vec
                                           :vec.size()>B.vec.size();
        }
        string tostring()
        {
            string s;
            s+=to_string(v);
            for(string ns:vec)
            {
                s+="*";
                s+=ns;
            }
            return s;
        }
    };
    
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for(int i=0;i<evalvars.size();i++)
            stov[evalvars[i]]=evalints[i];
        
        string ns;
        int prio=0,np;
        for(char c:expression)
        {
            if(c==' ') continue;
            if(c=='(')
            {
                prio+=2;
                continue;
            }
            if(c==')')
            {
                prio-=2;
                continue;
            }
            if(c=='*'||c=='+'||c=='-')
            {
                if(stov.count(ns))
                    ste.emplace(stov[ns]);
                else
                    ste.emplace(ns); 
                ns="";
                if(c=='*')
                    np=prio+2;
                else
                    np=prio+1;
                while(!stp.empty()&&stp.top()>=np)
                {
                    Exp a=ste.top(); ste.pop();
                    Exp b=ste.top(); ste.pop();
                    char nc=stc.top(); stc.pop();
                    stp.pop();
                    if(nc=='*')
                        ste.push(a*b);
                    else if(nc=='+')
                        ste.push(a+b);
                    else
                        ste.push(b-a);
                }
                stp.push(np);
                stc.push(c);
            }
            else
                ns+=c;
        }
        if(stov.count(ns))
            ste.emplace(stov[ns]);
        else
            ste.emplace(ns);
        while(!stp.empty())
        {
            Exp a=ste.top(); ste.pop();
            Exp b=ste.top(); ste.pop();
            char nc=stc.top(); stc.pop();
            stp.pop();
            if(nc=='*')
                ste.push(b*a);
            else if(nc=='+')
                ste.push(a+b);
            else
                ste.push(b-a);
        }
        vector<Node> nans;
        vector<string> ans;
        Exp e=ste.top();
        for(auto p:e.ma)
            if(p.second) nans.emplace_back(p.second,p.first);
        sort(nans.begin(),nans.end());
        for(Node n:nans)
            ans.push_back(n.tostring());
        return ans;
    }
};