class Solution {
public:
    int n,n1,n2,k,tans;
    int bs(vector<int>& nu1,vector<int>& nu2)
    {
        n1=nu1.size(),n2=nu2.size();
        int l=-1,r=n1-1;
        int mid,p;
        while(l<=r)
        {
            mid=(l+r)/2; p=k-mid-1;
            if(p<0)
            {
                r=mid-1;
                continue;
            }
            if(p>=n2)
            {
                l=mid+1;
                continue;
            }
            if(mid==-1&&nu2[p]<=nu1[0]
               ||nu1[mid]<=nu2[p]&&(mid==n1-1||nu2[p]<=nu1[mid+1]))
            {
                tans=nu2[p];
                return 1;
            }
            else if(nu2[p]<nu1[mid])
                r=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size(),n2=nums2.size();
        if(!n1) return (nums2[n2/2]+nums2[(n2-1)/2])/2.0;
        if(!n2) return (nums1[n1/2]+nums1[(n1-1)/2])/2.0;
        n=nums1.size()+nums2.size();
        k=n/2;
        double ans=0;
        if(bs(nums1,nums2)) ans=tans;
        else
        {
            bs(nums2,nums1);
            ans=tans;
        }
        k=(n-1)/2;
        if(bs(nums1,nums2)) ans+=tans;
        else
        {
            bs(nums2,nums1);
            ans+=tans;
        }
        return ans/2.0;
    }
};