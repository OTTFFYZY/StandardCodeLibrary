
 struct Interval
 {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
bool cmp(const Interval &A,const Interval &B)
{
    return A.start<B.start;
}
vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> ans;
    if(!intervals.size()) return ans;
    sort(intervals.begin(),intervals.end(),cmp);
    int st=intervals[0].start,ed=intervals[0].end;
    for(auto inter:intervals)
    {
        if(inter.start>ed)
        {
            ans.emplace_back(st,ed);
            st=inter.start; ed=inter.end;
        }
        else
            ed=max(ed,inter.end);
    }
    ans.emplace_back(st,ed);
    return ans;
}