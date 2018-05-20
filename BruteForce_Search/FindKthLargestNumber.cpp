int findKthLargest(vector<int>& nums, int k)
{
    int n=nums.size(),key,r=n-1,i=0;
    while(i<n)
    {
        //cout<<i<<" "<<r<<endl;
        key=nums[i];
        int j=i+1,p=i+1;
        while(j<=r)
        {
            if(nums[j]>=key)
            {
                swap(nums[p],nums[j]);
                p++;
            }
            j++;
        }
        if(p-i==k) return nums[i];
        else if(p-i<k)
        {
            k-=p-i;
            i=p;
        }
        else i++,r=p-1;
    }
}