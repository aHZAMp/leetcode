class Solution {
public:
    
    bool ways(int i,int j,int k,string &s1,string &s2,string &s3)
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
        
        if(s1[i]==s3[k]&&s2[j]==s3[k])
            return ways(i-1,j,k-1,s1,s2,s3)||ways(i,j-1,k-1,s1,s2,s3);
        else if(s1[i]==s3[k]&&s2[j]!=s3[k])
            return ways(i-1,j,k-1,s1,s2,s3);
       else if(s2[j]==s3[k]&&s1[i]!=s3[k])
           return ways(i,j-1,k-1,s1,s2,s3);
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int p=s3.size();
        if(n+m!=p)
            return false;
        return ways(n-1,m-1,p-1,s1,s2,s3);
    }
};