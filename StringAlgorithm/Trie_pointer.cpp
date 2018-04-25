#include <stdio.h>
#include <string>
#include <string.h>

class Trie {
public:
    /** Initialize your data structure here. */
    
    struct TN
    {
        bool word;
        TN* son[26];
        TN():word(0)
        {
            for(int i=0;i<26;i++) son[i]=NULL;
        }
    };
    TN *root;
    
    Trie() :root(new TN()){
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TN *now=root;
        for(char c:word)
        {
            if(now->son[c-'a']==NULL)
                now->son[c-'a']=new TN();
            now=now->son[c-'a'];
        }
        now->word=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TN *now=root;
        for(char c:word)
        {
            if(now->son[c-'a']==NULL) return 0;
            now=now->son[c-'a'];
        }
        return now->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TN *now=root;
        for(char c:prefix)
        {
            if(now->son[c-'a']==NULL) return 0;
            now=now->son[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
	return 0;
}