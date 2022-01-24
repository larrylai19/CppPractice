// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class TrieNode
{
public:
    TrieNode* child[26];
    bool isWord;
    
    TrieNode() : isWord(false) { for(auto& p : child) p = nullptr; }
    
    ~TrieNode() { for(auto& p : child) delete p; }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }
    
    ~WordDictionary() { delete root; }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = root;
        for(auto c : word)
        {
            if(!p->child[c - 'a']) p->child[c - 'a'] = new TrieNode();
            p = p->child[c - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) { return exist(word, 0, root); }
    
    bool exist(string& word, int pos, TrieNode* p)
    {
        if(!p) return false;
        if(pos == word.size()) return p->isWord;
        auto c = word[pos];
        if(c != '.') return exist(word, ++pos, p->child[c - 'a']);
        for(auto& child : p->child) if(exist(word, (++pos)--, child)) return true;
        return false;
    }

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */