class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        
        int j = n - 1;
        for(int i = 0; i < n/2; i++) {
            swap(nums[i], nums[j]);
            --j;
        }
        
        j = k - 1;
        for(int i = 0; i < k/2; i++) {
            swap(nums[i], nums[j]);
            --j;
        }
        
        j = n - 1;
        for(int i = k; i < (k+n)/2; i++) {
            swap(nums[i], nums[j]);
            --j;
        }
    }
};