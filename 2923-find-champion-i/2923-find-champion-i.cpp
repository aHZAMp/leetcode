class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        
       map<int,int>m;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    m[i]++;
            }
        }
        int maxi=INT_MIN,ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>maxi){
                maxi=it->second;
            ans=it->first;}
        }
        return ans;
        
    }
};