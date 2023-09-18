class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
       multimap<int,int>M;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                 c++;                    
            }
            M.insert(make_pair(c,i));
        }
        vector<int>ans;
        for(auto it=M.begin();it!=M.end();it++)
        {
            if(k==0)
                break;
            ans.push_back(it->second);
            k--;
        }
        return ans;
    }
};