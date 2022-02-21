class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int currNum = nums[0];
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != currNum) {
                if(cnt > 0) --cnt;
                else currNum = nums[i], cnt = 1;
            }
            else ++cnt;
        }
        return currNum;
    }
};