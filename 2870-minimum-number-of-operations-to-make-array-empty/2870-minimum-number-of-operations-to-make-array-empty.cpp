class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int c=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==1)
                return -1;
            c+=(it->second+2)/3;
        }
        return c;
    }
};