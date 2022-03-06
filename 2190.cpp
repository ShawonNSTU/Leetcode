class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int cnt[1001] = {0};
        for(int i = 0; i < nums.size(); ++i) {
            if(i - 1 >= 0 && nums[i-1] == key) cnt[nums[i]]++;
        }
        int res, currMax = 0;
        for(int i = 0; i < 1001; i++) {
            if(currMax <= cnt[i]) {
                res = i;
                currMax = cnt[i];
            }
        }
        return res;
    }
};