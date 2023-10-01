class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         long maxi=LONG_MIN;
        int n=nums.size();
        vector<int>pref(n),suff(n);
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            m=max(m,nums[i]);
            pref[i]=m;
        }
        m=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            m=max(m,nums[i]);
            suff[i]=m;
        }
       
        for(int i=1;i<n-1;i++)
        {
            maxi=max(maxi,long(pref[i-1]-nums[i])*suff[i+1]);
        }
        if(maxi<0)
            return 0;
        else
        return maxi;
        
    }
};