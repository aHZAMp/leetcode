class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int m;
        sort(nums.begin(),nums.end());
      
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i]^nums[i+1])==0){
                m=nums[i];
                break;}
        }
        return m;
    }
};