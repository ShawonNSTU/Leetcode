class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        unordered_map<long long, int> ump[n];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - (long long)nums[j];
                auto it = ump[j].find(diff);
                if(it != ump[j].end()) {
                    cnt += it->second;
                    ump[i][diff] += it->second;
                }
                ump[i][diff]++;
            }
        }
        return cnt;
    }
};