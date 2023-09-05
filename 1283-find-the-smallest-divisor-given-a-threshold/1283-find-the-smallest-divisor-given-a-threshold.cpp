class Solution {
public:
    
    bool ispossible(int mid,vector<int>&nums,int threshold)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil((double)nums[i]/(double)mid);
        }
       // cout<<sum<<endl;
        if(sum<=threshold)
            return true;
        else
            return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //cout<<mid<<"->"<<endl;
            if(ispossible(mid,nums,threshold))
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