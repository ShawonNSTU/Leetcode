class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, idx = 0, r = nums.size() - 1;
        while(idx <= r) {
            if(nums[idx] == 0) {
                nums[idx] = nums[l];
                nums[l] = 0;
                ++l;
                ++idx;
            }
            else if(nums[idx] == 2) {
                nums[idx] = nums[r];
                nums[r] = 2;
                --r;
            }
            else {
                ++idx;
            }
        }
    }
};