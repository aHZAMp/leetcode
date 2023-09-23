class Solution {
public:
    
     bool possible(string &s1,string &s2)
    {
        if(s1.size()==s2.size())  return false;
        if(s1.size()>s2.size()+1) return false;
         int i=0;
         int j=0;
        while(i<s1.size())
            if(j<s2.size() && s1[i]==s2[j])
                i++,j++;
            else
                i++;
        if(i==s1.size() && j==s2.size())
            return true;
        else
            return false;
    }
    int ways(int ind,int prev,int n,vector<string>&words,vector<vector<int>>&dp)
    {
        if(ind>n)
            return 0;
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];
        int notTake=0+ways(ind+1,prev,n,words,dp);
        int take=0;
        if(prev==0||possible(words[ind-1],words[prev-1]))
        take=1+ways(ind+1,ind,n,words,dp);
        return dp[ind][prev]=max(take,notTake);
    }
    static bool comp(string s1,string s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),comp);
      
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return ways(1,0,n,words,dp);
    }
};