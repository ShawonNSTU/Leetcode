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