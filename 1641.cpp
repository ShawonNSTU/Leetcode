class Solution {
public:
    struct Vowel {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
    };
    int countVowelStrings(int n) {
        Vowel dp[n];
        for(int i = 1; i < n; ++i) {
            int total = dp[i-1].a + dp[i-1].e + dp[i-1].i + dp[i-1].o + dp[i-1].u;
            dp[i].a = total;
            dp[i].e = total - dp[i-1].a;
            dp[i].i = total - dp[i-1].a - dp[i-1].e;
            dp[i].o = total - dp[i-1].a - dp[i-1].e - dp[i-1].i;
            dp[i].u = total - dp[i-1].a - dp[i-1].e - dp[i-1].i - dp[i-1].o;
        }
        return dp[n-1].a + dp[n-1].e + dp[n-1].i + dp[n-1].o + dp[n-1].u;
    }
};