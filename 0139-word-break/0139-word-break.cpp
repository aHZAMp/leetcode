struct Node{

    Node* links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {


  

public:

    /** Initialize your data structure here. */
    Node* root;
    Trie() {
       root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
         Node* node=root;
         for(int i=0;i<word.size();i++)
         {
             if(!node->containsKey(word[i]))
                node->put(word[i], new Node());

              node=node->get(word[i]);  
         }     
          node->setEnd();


    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
          Node* node=root;
          for(int i=0;i<word.size();i++)
          {
              if(!node->containsKey(word[i]))
                  return false;
               node=node->get(word[i]);   
          }
          return node->isEnd();
    }
};

class Solution {
public:
      
    
    bool ways(int ind,int n,string &s,Trie* obj,vector<int>&dp)
    {
        if(ind==n)
            return true;
        if(dp[ind]!=-1)
            return dp[ind];
        string t="";bool res=false;
        for(int i=ind;i<n;i++)
        {
            t=t+s[i];
            if(obj->search(t)){
                //t="";
                if(ways(i+1,n,s,obj,dp))
                    return dp[ind]=true;
           // res|=ways(i+1,n,s,obj,dp);
            }
        }
        return dp[ind]=false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie* obj=new Trie();
        for(int i=0;i<wordDict.size();i++)
        {
            obj->insert(wordDict[i]);
        }
        int n=s.size();
        vector<int>dp(n+1,-1);
        return ways(0,s.size(),s,obj,dp);
    }
};