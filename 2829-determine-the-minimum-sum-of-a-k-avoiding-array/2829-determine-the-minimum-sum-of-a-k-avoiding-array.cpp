class Solution {
public:
    int minimumSum(int n, int k) {
     
        int sum=0;
        set<int>s;int a=1;
        
        for(int i=1;i<=n;i++)
        {
            if(s.empty()){
                s.insert(a);
                sum+=a;
                a++;
            }
            else{
                if(s.find(k-a)==s.end())
                {
                    s.insert(a);
                    sum+=a;
                    a++;
                }
                else{
                    while(s.find(k-a)!=s.end())
                        a++;
                    s.insert(a);
                    sum+=a;
                    a++;
                }
           
           
            
        }}
        return sum;
    }
};