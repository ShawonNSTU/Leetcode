class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int match = 0;
        for(string s : words) {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                if(i < pref.size() && s[i] == pref[i]) ++cnt;
                else break;
            }
            if(cnt == pref.size()) ++match;
        }
        return match;
    }
};