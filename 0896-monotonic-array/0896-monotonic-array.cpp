class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
            return true;
       vector<int>test=nums;
        reverse(test.begin(),test.end());
        multiset<int>s;
        for(auto it:nums)
        {
            s.insert(it);
        }
        vector<int>v(s.begin(),s.end());
        
        if(v==nums)
            return true;
        if(v==test)
            return true;
    
            return false;
         
        
    }
};