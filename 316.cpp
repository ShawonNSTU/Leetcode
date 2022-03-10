class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> vis(26, 0), lastPos(26, 0);
        for(int i = n-1; i >= 0; --i) {
            int c = s[i] - 'a';
            if(!lastPos[c]) lastPos[c] = i;
        }
        string res = "";
        for(int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if(!vis[c]) {
                while(res.length() > 0 && res.back() - 'a' > c && lastPos[res.back() - 'a'] > i) {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += c + 'a';
                vis[c] = 1;
            }
        }
        return res;
    }
};