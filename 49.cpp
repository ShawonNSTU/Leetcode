class Solution {
public:
    string getSortedString(string s) {
        int cnt[26] = {0};
        for(char ch : s) cnt[ch-'a']++;
        string str;
        for(int i = 0; i < 26; i++) {
            str += string(cnt[i], i + 'a');
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(string s : strs) {
            ump[getSortedString(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto p : ump) {
            res.push_back(p.second);
        }
        return res;
    }
};