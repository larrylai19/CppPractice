class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int Cap;
    LRUCache(int capacity) {
        Cap = capacity;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        if(cache.size() == Cap)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        hash[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */