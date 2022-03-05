class Solution {
public:
    int getTotalMoney(int idx1, int idx2, vector<int>& nums) {
        int prev1 = nums[idx1], prev2 = 0;
        if(idx2 > idx1 + 1) prev2 = max(prev1, nums[idx1+1]);
        for(int i = idx1+2; i < idx2; ++i) {
            int temp = prev2;
            prev2 = max(prev1 + nums[i], prev2);
            prev1 = temp;
        }
        return max(prev1, prev2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else return max(getTotalMoney(0, n-1, nums), getTotalMoney(1, n, nums));
    }
};