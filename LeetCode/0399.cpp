class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int n = equations.size();
        vector<double> ret;
        unordered_map<string, unordered_map<string, double>> _m;
        for(int i{}; i < n; ++i)
            _m[equations[i][0]][equations[i][1]] = values[i], _m[equations[i][1]][equations[i][0]] = 1 / values[i];
        for(auto& que : queries)
        {
            string& x = que[0], y = que[1];
            if(!_m.count(x) || !_m.count(y)) { ret.emplace_back(-1.0); continue; }
            unordered_set<string> visited;
            ret.emplace_back(divide(x, y, _m, visited));
        }
        return ret;
    }
    
private:
    double divide(const string& A, const string& B, unordered_map<string, unordered_map<string, double>>& _m, unordered_set<string>& visited)
    {
        if(A == B) return 1.0;
        visited.insert(A);
        for(auto& [key, val] : _m[A])
        {
            if(visited.count(key)) continue;
            double d = divide(key, B, _m, visited);
            if(d > 0) return d * _m[A][key];
        }
        return -1.0;
    }
    
};