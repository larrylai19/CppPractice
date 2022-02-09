// ref: https://leetcode.wang/leetCode-30-Substring-with-Concatenation-of-All-Words.html
// ref: https://www.cnblogs.com/grandyang/p/4521224.html

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        
        vector<int> ret;
        int sLen = s.length();
        int wordNum = words.size();
        int wordLen = words[0].length();
        
        unordered_map<string, int> allWords;
        for (const auto& w : words) ++allWords[w];
        
        for (int i = 0; i < wordLen; ++i) {
            int cnt = 0;
            int left = i;
            unordered_map<string, int> currWords;
            
            for (int j = i; j <= sLen - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (allWords.count(word)) {
                    ++currWords[word];
                    
                    if (currWords[word] > allWords[word]) {
                        while (currWords[word] > allWords[word]) {
                            string deleteWord = s.substr(left, wordLen);
                            --currWords[deleteWord];
                            if (currWords[deleteWord] < allWords[deleteWord]) --cnt;
                            left += wordLen;
                        }
                    }
                    else ++cnt;
                    
                    if (cnt == wordNum) {
                        ret.push_back(left);
                        --currWords[s.substr(left, wordLen)];
                        --cnt;
                        left += wordLen;
                    }
                } else {
                    currWords.clear();
                    left = j + wordLen;
                    cnt = 0;
                }
            }
        }
        
        return ret;
    }
};