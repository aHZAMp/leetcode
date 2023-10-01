
class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
                a=a+s[i];
            else
            {
                v.push_back(a);
                a="";
            }
        }
        v.push_back(a);
        string res="";
        for(int i=0;i<v.size();i++)
        {
            reverse(v[i].begin(),v[i].end());
            res+=v[i]+" ";
        }
        int n=res.size();
        res.resize(n-1);
        return res;
    }
};