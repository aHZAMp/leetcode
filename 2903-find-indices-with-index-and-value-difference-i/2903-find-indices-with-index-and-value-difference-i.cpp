class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        
        vector<int>ans;
        bool f=false;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(abs(i-j)>=indexDifference&&abs(nums[i]-nums[j])>=valueDifference)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                   
                } 
            }
           
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};