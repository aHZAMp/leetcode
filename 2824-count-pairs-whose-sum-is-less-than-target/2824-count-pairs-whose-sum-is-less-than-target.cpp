class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        int c=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]+nums[j]<target)
        //             c++;
        //     }
        // }
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]<target)
            {
                c++;
                c+=j-1-i;
                i++;
            }
            else
            {
                j--;
            }
        }
        return c;
    }
};