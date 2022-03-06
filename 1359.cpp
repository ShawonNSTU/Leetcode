// Bottom-Up Approach
class Solution {
public:
    int countOrders(int n) {
        long ans = 1, MOD = 1e9 + 7;
        for(int i = 1; i <= n; ++i) {
            long currPossible = (i * (i + i - 1)) % MOD;
            ans = (ans * currPossible) % MOD;
        }
        return ans;
    }
};

// Top-Down Approach
class Solution {
public:
    long MOD = 1e9 + 7;
    int countOrders(int n) {
        if(n == 1) return 1;
        long currPossible = (n * (2 * n - 1)) % MOD;
        return (currPossible * countOrders(n-1)) % MOD;
    }
};