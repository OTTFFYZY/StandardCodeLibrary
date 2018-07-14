int next_permutation(int *begin,int *end)
{
    int *i=begin,*j,*k;
    if (i==end||i+1==end) return 0;   // 0 or 1 element, no next permutation
    for (i=end-1;i!=begin;)
    {
        j=i--;    // find last increasing pair (i,j)
        if(!(*i<*j)) continue;
        // find last k which not less than i,
        for(k=end;!(*i<*(--k));) ;
        iter_swap(i,k);
        // now the range [j,end) is in descending order
        reverse(j,end);
        return 1;
    }
    // current is in descending order
    reverse(begin,end);
    return 0;
}