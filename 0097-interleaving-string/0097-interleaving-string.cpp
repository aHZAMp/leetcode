class Solution {
public:
    
    bool ways(int i,int j,int k,string &s1,string &s2,string &s3, vector<vector<vector<int> > >&dp)
    {
        if(i<0&&j<0&&k<0)return true;
        if(i<0&&j<0)return false;
        if(i<0&&j>=0)
        {   if(k==j){
            bool b=true;
            for(int a=0;a<=j;a++)
            {
                if(s2[a]!=s3[a]){
                    b=false;
                    break;}
            }
            return b;
        }
         else
             return false;
        }
        if(i>=0&&j<0)
        {
            if(i==k){
                bool b=true;
            for(int a=0;a<=i;a++)
            {
                if(s1[a]!=s3[a]){
                    b=false;
                    break;}
            }
            return b;
            }
         else
             return false;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(s1[i]==s3[k]&&s2[j]==s3[k])
            return dp[i][j][k]=ways(i-1,j,k-1,s1,s2,s3,dp)||ways(i,j-1,k-1,s1,s2,s3,dp);
        else if(s1[i]==s3[k]&&s2[j]!=s3[k])
            return dp[i][j][k]=ways(i-1,j,k-1,s1,s2,s3,dp);
       else if(s2[j]==s3[k]&&s1[i]!=s3[k])
           return dp[i][j][k]=ways(i,j-1,k-1,s1,s2,s3,dp);
        return dp[i][j][k]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int p=s3.size();
        if(n+m!=p)
            return false;
         vector<vector<vector<int> > > dp(
        n, vector<vector<int> >(m, vector<int>(p,-1)));
        return ways(n-1,m-1,p-1,s1,s2,s3,dp);
    }
};