class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string st="";
        for(int i=0;i<words.size();i++)
        {
            st+=words[i][0];
        }
        if(st==s)
            return true;
        else
            return false;
    }
};