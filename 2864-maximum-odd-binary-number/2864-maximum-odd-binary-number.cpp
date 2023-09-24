class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int c1=0,c0=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                c1++;
            else
                c0++;
        }
        string S="";
        for(int i=1;i<=c1-1;i++)
        {
            S+='1';
        }
         for(int i=1;i<=c0;i++)
        {
            S+='0';
        }
        S+='1';
        return S;
        
    }
};