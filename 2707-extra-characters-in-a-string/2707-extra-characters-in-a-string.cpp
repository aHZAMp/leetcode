
struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node*node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setend()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
        
};
class Trie
{
    
    Node* root;
  public:
    Trie()
    {
        root =new Node();
    }
    void insert(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->containskey(s[i]))
                node->put(s[i],new Node());
            node=node->get(s[i]);
        }
        node->setend();
    }
    bool search(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->containskey(s[i]))
                return false;
            node=node->get(s[i]);
        }
        return node->isend();
    }
};


class Solution {
public:
    
    int ways(int ind,int n,string &s,Trie* obj,vector<int>&dp)
    {
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        string t="";
        int mini=INT_MAX;
        
        for(int i=ind;i<n;i++)
        {
            t=t+s[i];
            int count=t.size();
            if(obj->search(t)){
                count=0;
                //t="";
                // if(ways(i+1,n,s,obj,dp))
                //     return dp[ind]=true;
           // res|=ways(i+1,n,s,obj,dp);
            }
            count+=ways(i+1,n,s,obj,dp);
            mini=min(mini,count);
        }
        return dp[ind]=mini;;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        
        Trie* obj=new Trie();
        for(int i=0;i<dictionary.size();i++)
        {
            obj->insert(dictionary[i]);
        }
       
        
      int n=s.size();
        vector<int>dp(n,-1);
        return ways(0,n,s,obj,dp);
    }
};