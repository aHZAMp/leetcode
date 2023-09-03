class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        
        long long maxi=0;
        int i=0,j=0;
        long long sum=0;
        map<int,int>M;
        while(j<nums.size())
        {
            sum+=nums[j];
            M[nums[j]]++;
            if(j-i+1!=k)
                j++;
            else if(j-i+1==k)
            {
                if(M.size()>=m){
                    maxi=max(maxi,sum);
                sum=sum-nums[i];
                auto it=M.find(nums[i]);
                it->second--;
                if(it->second==0)
                    M.erase(it);
                    i++;j++;
                }
                else
                {
                     sum=sum-nums[i];
                auto it=M.find(nums[i]);
                it->second--;
                if(it->second==0)
                    M.erase(it);
                    i++;j++;
                }
                
            }
        }
        return maxi;
        
    }
};