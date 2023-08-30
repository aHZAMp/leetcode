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


class MagicDictionary {
public:
    vector<string>words;
    Trie* obj=new Trie();
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        
        words=dictionary;
        
        for(int i=0;i<words.size();i++)
        {
            obj->insert(words[i]);
        }
    }
    
    bool search(string searchWord) {
        
        // if(obj->search(searchWord))
        //     return false;
        string s=searchWord;
        bool f=false;
        for(int i=0;i<s.size();i++)
        {
            
            char ch=s[i];
            
            for(char c='a';c<='z';c++)
            {
                s[i]=c;
                if(obj->search(s)==true&&s[i]!=ch)
                {
                    f=true;
                    break;
                }
            }
            s[i]=ch;
            if(f)
                break;
        }
        return f;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */