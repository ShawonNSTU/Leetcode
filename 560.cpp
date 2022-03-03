class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0, res = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        for(int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            int diff = prefixSum - k;
            auto it = ump.find(diff);
            if(it != ump.end()) res += it->second;
            ump[prefixSum]++;
        }
        return res;
    }
};