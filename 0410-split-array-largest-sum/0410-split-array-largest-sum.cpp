class Solution {
public:
    bool ispossible(int mid,vector<int>&nums,int k)
    {
        int sum=0,count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=mid)
            sum+=nums[i];
            else{
                count++;
                sum=nums[i];
        }}
        if(count>k)
            return false;
        else
            return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(mid,nums,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};