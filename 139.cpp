class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        vector<bool>v(n+1);
        v[n] = true;
        
        for(int i = n-1; i >= 0; i--) {
            for(string str : wordDict) {
                int len = str.length();
                if(i + len <= n && s.substr(i, len) == str) {
                    v[i] = v[i+len];
                }
                if(v[i]) break;
            }
        }
        
        return v[0];
    }
};