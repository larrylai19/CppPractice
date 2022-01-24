class LRUCache {
public:
    list<pair<int, int>> cache; // 儲存 key 及 value
    unordered_map<int, list<pair<int, int>>::iterator> hash; // 儲存 key 及對應的 node，方便尋找及刪除
    int Cap;
	
    LRUCache(int capacity) {
        Cap = capacity;
    }
    
    int get(int key) {
        // 先使用 key 尋找 node
        auto it = hash.find(key);
        // 如果找不到
        if(it == hash.end())
            return -1;
        // 將這個 node 移到最前面
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        // 先使用 key 尋找 node
        auto it = hash.find(key);
        // 如果找到
        if(it != hash.end())
        {
            // 將原本的 value 改為新的 value
            it->second->second = value;
            // 將這個 node 移到最前面
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        // 如果 list 已經滿了
        if(cache.size() == Cap)
        {
            // 刪除最後一個 node，同時 hash 裡面也必須刪除
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        // 將新的值插入，同時也在 hash 裡面插入
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