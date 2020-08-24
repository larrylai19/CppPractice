 class TrieNode
{
public:
    TrieNode() : isWord(false) { for(auto& ptr : child) ptr = nullptr; }
    
    ~TrieNode() { for(auto& ptr : child) delete ptr; }
    
    void build(string& str, int idx)
    {
        if(idx == str.size()) { isWord = true; return; }
        if(!child[str[idx] - 'a']) child[str[idx] - 'a'] = new TrieNode();
        child[str[idx] - 'a']->build(str, ++idx);
    }
    
    bool search(string& str, int idx)
    {
        if(idx == str.size()) return isWord;
        return child[str[idx] - 'a'] ? child[str[idx] - 'a']->search(str, ++idx) : false;
    }
    
    bool prefix(string& str, int idx)
    {
        if(idx == str.size()) return true;
        return child[str[idx] - 'a'] ? child[str[idx] - 'a']->prefix(str, ++idx) : false;
    }
    
private:
    TrieNode* child[26];
    bool isWord;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    
    ~Trie() { delete root; }
    
    /** Inserts a word into the trie. */
    void insert(string word) { root->build(word, 0); }
    
    /** Returns if the word is in the trie. */
    bool search(string word) { return root->search(word, 0); }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { return root->prefix(prefix, 0); }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */