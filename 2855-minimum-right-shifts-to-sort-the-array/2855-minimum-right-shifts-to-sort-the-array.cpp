class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int p=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                p=i;
                break;
            }
        }
        if(p==0)
            return 0;
        int maxi=nums[p-1];
        for(int i=p;i<nums.size();i++)
        {
            if(nums[i]>maxi)
                return -1;
           
        }
        for(int i=p;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
                return -1;
        }
            
        return nums.size()-p;
    }
};