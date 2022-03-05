class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev1 = nums[0], prev2 = 0;
        if(n > 1) prev2 = max(prev1, nums[1]);
        for(int i = 2; i < n; ++i) {
            int temp = prev2;
            prev2 = max(prev1 + nums[i], prev2);
            prev1 = temp;
        }
        return max(prev1, prev2);
    }
};