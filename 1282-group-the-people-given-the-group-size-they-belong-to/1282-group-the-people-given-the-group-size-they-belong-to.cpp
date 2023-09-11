class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
       vector<vector<int>>ans;
        int n=groupSizes.size();
        vector<int>vis(n,0);
        for(int i=0;i<groupSizes.size();i++)
        {
            vector<int>v;
            int k=0;int j=0;
           int p=groupSizes[i];
                while(k<n&&j<groupSizes[i])
                {
                    if(!vis[k]&&p==groupSizes[k])
                    {
                        v.push_back(k);
                        vis[k]=1;
                        j++;
                    }
                    k++;
                        
                }
            if(v.size()>0)
            ans.push_back(v);
            }
        return ans;
        }
        
    
};