class Solution {
public:
    string reorganizeString(string s) {
        
        map<char,int>m;
       int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it=m.begin();it!=m.end();it++)
        {
            q.push({it->second,it->first});
        }
        
       string ans="";
        while(q.size()>1)
        {
            int top1=q.top().first;
            char c1=q.top().second;
            q.pop();
             int top2=q.top().first;
            char c2=q.top().second;
            q.pop();
            ans+=c1;
            ans+=c2;
            top1--;
            top2--;
            if(top1>0)
                q.push({top1,c1});
            if(top2>0)
                q.push({top2,c2});
        }
        if(!q.empty())
        {
            if(q.top().first>1)
                ans="";
            else
                ans+=q.top().second;
        }
      return ans;
    }
};