class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) { m[key] = val; }
    
    int sum(string prefix)
    {
        int _sum{};
        for(auto& [key, val] : m) if(!(key.find(prefix))) _sum += val;
        return _sum;
    }
    
private:
    unordered_map<string, int> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */