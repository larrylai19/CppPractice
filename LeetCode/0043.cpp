class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> product(num1.size() + num2.size());
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                product[i + j] += n1 * n2;
            }
        }
        
        for (int i = 0; i < product.size() - 1; ++i) {
            product[i + 1] += product[i] / 10;
            product[i] %= 10;
        }
        
        string ret;
        for (int i = product.size() - 1; i >= 0; --i) ret += char(product[i] + '0');
        
        if (ret[0] == '0') ret.erase(ret.begin());
        
        return ret;
    }
};