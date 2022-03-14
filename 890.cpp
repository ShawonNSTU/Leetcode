class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string str : words) {
            unordered_map<char, char> ump1, ump2;
            bool flag = true;
            for(int i = 0; i < str.length() && flag; ++i) {
                if(!ump1[str[i]]) {
                    if(!ump2[pattern[i]]) {
                        ump1[str[i]] = pattern[i];
                        ump2[pattern[i]] = str[i];
                    }
                    else flag = false;
                }
                else if(ump1[str[i]] != pattern[i]) flag = false;
            }
            if(flag) res.push_back(str);
        }
        return res;
    }
};