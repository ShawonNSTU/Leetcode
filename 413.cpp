class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int prev = 0, res = 0;
        for(int i = 2; i < nums.size(); ++i) {
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) ++prev, res += prev;
            else prev = 0;
        }
        return res;
    }
};