class Solution {
public:
    
    int ways(vector<int>&nums,int target,vector<int>&dp)
    {
       if(target<0)
           return 0;
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
      for(int i=0;i<nums.size();i++)
      {
          ans+=ways(nums,target-nums[i],dp);
      }
        return dp[target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
          vector<int>dp(1001,-1);
           return ways(nums,target,dp);
            
            
        
    }
};

