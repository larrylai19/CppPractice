// fast IO
static auto __ = []() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!hs.count(key))
            hs.insert(key);
    }
    
    void remove(int key) {
        if(hs.count(key))
            hs.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hs.count(key);
    }
private:
    unordered_set<int> hs;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */