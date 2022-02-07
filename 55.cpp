class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return true;
        
        int goal = n - 1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] + i >= goal) {
                goal = i;
            }
        }
        
        if(!goal) return true;
        else return false;
    }
};