class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        vector<int>v;
        set<int>p;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            p.insert(nums[i]);
        }
        
        for(auto i=p.begin();i!=p.end();i++)
        {
            
            auto it=upper_bound(nums.begin(),nums.end(),*i);
            auto a=lower_bound(nums.begin(),nums.end(),*i);
            if((it-a)>n)
                v.push_back(*i);
            
        }
        return v;
        
    }
};
