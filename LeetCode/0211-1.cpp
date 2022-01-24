// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class node
{
public:
    node* child[26];
    bool isWord;
    
    node():isWord(false)
    {
        for(auto& p : child)
            p = nullptr;
    }
    
    ~node()
    {
        for(auto& p : child)
            delete p;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto ptr = root;
        for(auto c : word)
        {
            int index = c - 'a';
            if(!ptr->child[index])
                ptr->child[index] = new node();
            ptr = ptr->child[index];
        }
        ptr->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return exist(word, 0, root);
    }
    
    bool exist(string& word, int pos, node* ptr)
    {
        if(!ptr)
            return false;
        if(pos == word.size())
            return ptr->isWord;
        auto c = word[pos];
        if(c != '.')
            return exist(word, ++pos, ptr->child[c - 'a']);
        for(auto& child : ptr->child)
            if(exist(word, pos + 1, child))
                return true;
        return false;
    }

private:
    node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */