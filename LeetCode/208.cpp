class node
{
public:
    node *child[26];
    bool isWord;
    node():isWord(false)
    {
        for(auto& p : child)
            p = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto ptr = root;
        for(auto c : word)
        {
            int index = c - 'a';
            if(!ptr->child[index])
                return false;
            ptr = ptr->child[index];
        }
        return ptr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto ptr = root;
        for(auto c : prefix)
        {
            int index = c - 'a';
            if(!ptr->child[index])
                return false;
            ptr = ptr->child[index];
        }
        return true;
    }
private:
    node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */