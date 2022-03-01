class Solution {
public:
    vector<int> countBits(int n) {
        int bitCnt[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            int num = i, ans = 0;
            while(num) {
                ans += bitCnt[num&15];
                num >>= 4;
            }
            res.push_back(ans);
        }
        return res;
    }
};

// Java DP Approach
class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        int top = 1;
        for(int i = 1; i <= n; i++) {
            if(top * 2 == i) top = i;
            ans[i] = 1 + ans[i-top];
        }
        return ans;
    }
}
