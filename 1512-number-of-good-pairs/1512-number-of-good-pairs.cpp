class Solution {
public:
    int count(vector<int>nums,int n)
    {
        
        
        sort(nums.begin(),nums.end());
       
        auto it=upper_bound(nums.begin(),nums.end(),n);
        auto a=lower_bound(nums.begin(),nums.end(),n);
        return it-a;
    }
    int numIdenticalPairs(vector<int>& nums) {
        
        set<int>p;int n,s=0;
         for(int i=0;i<nums.size();i++)
        {
            p.insert(nums[i]);
        }
        for(auto it=p.begin(); it!=p.end();it++)
        {
            n=count(nums,*it);
            s=s+n*(n-1)/2;
        }
        return s;
    }
};