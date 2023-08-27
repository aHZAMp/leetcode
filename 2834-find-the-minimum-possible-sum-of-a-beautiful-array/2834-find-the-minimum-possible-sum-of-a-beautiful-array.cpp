class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
        long long sum=0;
        set<int>s;int i=1;
        while(s.size()!=n)
        {
             auto it=s.find(target-i);
            if(s.empty()){
                s.insert(i);
                i++;}
           
           else if(it==s.end())
            {
                s.insert(i);
                i++;
            }
            else
            {
                while(it!=s.end())
                {
                    i++;
                    it=s.find(target-i);
                }
                s.insert(i);
                i++;
            }
            
        }
        for(auto it=s.begin();it!=s.end();it++)
        {
            sum+=*it;
        }
        return sum;
    }
};