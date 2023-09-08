class Solution {
public:
    
    void ways(int row,int currRow,vector<vector<int>>&ans,int n)
    {
        if(row==n)
            return;
        
        for(int i=1;i<currRow-1;i++)
        {
            ans[row][i]=ans[row-1][i-1]+ans[row-1][i];
        }
        ways(row+1,currRow+1,ans,n);
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int>v(i,0);
            if(i==1)
                v[0]=1;
            else{
                v[0]=1;
                v[i-1]=1;
            }
            ans.push_back(v);
        }
        if(numRows==1||numRows==2)
            return ans;
        
        ways(2,3,ans,numRows);
        return ans;
        
    }
};