class Solution {
public:
    
    static bool comp(vector<int>&v1,vector<int>&v2)
    {
        return v1[0]<v2[0];
    }
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>>v;
        for(int i=0;i<ranges.size();i++)
        {
             vector<int>vec{i-ranges[i],i+ranges[i]};
            v.push_back(vec);
        }
        sort(v.begin(),v.end(),comp);
        
        int count=0,start=0,end=0,i=0;
        while(end<n)
        {
            for(;i<v.size()&&v[i][0]<=start;i++)
            {
               
                    end=max(end,v[i][1]);
                   // farReach=i;
                
            }
            if(start==end)return -1;
            start=end;
            count++;
        }
        return count;
    }
};
