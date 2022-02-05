class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int id = nums[i] % n;
            nums[id] += n;
        }
        int max = 0;
        int currNum = 0;
        for(int i = 0; i < n; i++) {
            if(max < nums[i]) {
                max = nums[i];
                currNum = i;
            }
            nums[i] %= n;
        }
        
        return currNum;
    }
};