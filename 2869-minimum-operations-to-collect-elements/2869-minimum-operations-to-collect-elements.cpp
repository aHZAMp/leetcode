class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    
         set<int>s;
        int c=0,count=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
           if(nums[i]>=1&&nums[i]<=k)
           {
               s.insert(nums[i]);
               c++;
               count++;
               if(s.size()==k)
                  break;
           }
            else
            count++;
        }
        return count;
        
         
        
        
    }
};