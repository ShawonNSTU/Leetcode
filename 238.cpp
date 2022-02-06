class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n);
        
        int prefix = 1;
        res[0] = prefix;
        
        for(int i = 1; i < n; i++) {
            res[i] = nums[i-1] * prefix;
            prefix *= nums[i-1];
        }
        
        int postfix = 1;
        for(int i = n-1; i >= 0; i--) {
            res[i] = res[i] * postfix;
            postfix *= nums[i];
        }
        
        return res;
    }
};