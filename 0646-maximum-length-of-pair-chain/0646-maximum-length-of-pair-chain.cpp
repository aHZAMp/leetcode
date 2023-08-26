class Solution {
public:
    
    
    int ways(int ind,int n,int prev,vector<vector<int>>&pairs,vector<vector<int>>&dp)
    {    
        if(ind==n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int len=0+ways(ind+1,n,prev,pairs,dp);//not Take
        if(prev==-1||pairs[ind][0]>pairs[prev][1])     //take
        len=max(len,1+ways(ind+1,n,ind,pairs,dp));
        return dp[ind][prev+1]=len;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                 int len=0+dp[ind+1][prev+1];//not Take
        if(prev==-1||pairs[ind][0]>pairs[prev][1])     //take
        len=max(len,1+dp[ind+1][ind+1]);
        dp[ind][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};