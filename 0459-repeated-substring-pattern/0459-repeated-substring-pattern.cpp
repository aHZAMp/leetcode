class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         
        int n=s.size();
        if(n==1)
            return false;
        vector<int>fact;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                fact.push_back(i);
        }
        bool b=false;
        char c=s[0];
        string S="";
        for(int i=0;i<n;i++)
            S+=c;
        if(S==s)
            return true;
    
        for(int i=1;i<fact.size()-1;i++)
        {
           string st=s.substr(0,fact[i]);
            int a=n/fact[i];
            string str="";
            
            for(int j=0;j<a;j++)
                str+=st;
            //cout<<str<<endl;
            if(str==s)
            {
                b=true;
                break;
                
            }
        
        }
        if(b)return true;
        else
            return false;
        
    }
};