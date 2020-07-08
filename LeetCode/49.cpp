class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<pair<string, int>> temp;
        string stemp;

        for (int i = 0; i < strs.size(); ++i)
        {
            stemp = strs[i];
            sort(stemp.begin(), stemp.end());
            temp.push_back(make_pair(stemp, i));
        }

        sort(temp.begin(), temp.end());

        stemp = temp[0].first;
        vector<string> vtemp;

        for (int i = 0; i < temp.size(); ++i)
        {
            if (stemp == temp[i].first)
                vtemp.push_back(strs[temp[i].second]);
            else
            {
                res.push_back(vtemp);
                vtemp.clear();
                stemp = temp[i].first;
                vtemp.push_back(strs[temp[i].second]);
            }
        }
        res.push_back(vtemp);

        return res;
    }
};