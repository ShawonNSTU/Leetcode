class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length(), l = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i) {
            while(s[l] != s[i] && l > 0) l = dp[l-1];
            if(s[l] == s[i]) {
                dp[i] = l + 1;
                ++l;
            }
        }
        return s.substr(0, dp[n-1]);
    }
};

/*
    a c a c a b a c a c a b a c a c  a  c
    0 0 1 2 3 0 1 2 3 4 5 6 7 8 9 10 11 4
*/