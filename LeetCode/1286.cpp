class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) : orgin(characters), length(combinationLength), first(true) {
        cur = characters.substr(0, combinationLength);
        last = characters.substr(characters.size() - combinationLength);
    }
    
    string next() {
        if(first) { first = false; return cur; }
        int pos = cur.size() - 1;
        while(cur[pos] == last[pos]) --pos;
        int opos = 0;
        while(cur[pos] != orgin[opos]) ++opos;
        for(int i = pos; i < cur.size(); ++i)
            cur[i] = orgin[opos + i + 1 - pos];
        return cur;
    }
    
    bool hasNext() { return cur != last; }

private:
    string orgin;
    string cur;
    string last;
    int length;
    bool first;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */