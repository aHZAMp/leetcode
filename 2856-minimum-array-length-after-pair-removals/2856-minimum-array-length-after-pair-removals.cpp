class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        
        int len=0;
        int n=nums.size();
        int N=n;
      
        int i=0,j=N/2;
        while(i<N/2&&j<N)
        {
            if(nums[j]>nums[i])
            {
                n=n-2;
                i++;
                j++;
            }
           else
                j++;
        }
        if(n==N)
            return N;
        else
            return n;
    }
};