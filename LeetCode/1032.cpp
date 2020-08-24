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
    TrieNode() : isWord(false) { for(auto& ptr : child) ptr = nullptr; }
    
    ~TrieNode() { for(auto& ptr : child) delete ptr; }
    
    void build(string& str, int idx)
    {
        if(idx == -1) { isWord = true; return; }
        if(!child[str[idx] - 'a']) child[str[idx] - 'a'] = new TrieNode();
        child[str[idx] - 'a']->build(str, --idx);
    }
    
    bool search(string& str, int idx)
    {
        if(idx == -1 || isWord) return isWord;
        return child[str[idx] - 'a'] ? child[str[idx] - 'a']->search(str, --idx) : false;
    }
    
private:
    TrieNode* child[26];
    bool isWord;
};
    
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(auto& word : words) root->build(word, word.size() - 1);
    }
    
    ~StreamChecker() { delete root; }
    
    bool query(char letter) { return root->search(curstr += letter, curstr.size() - 1); }

private:
    TrieNode* root;
    string curstr;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */