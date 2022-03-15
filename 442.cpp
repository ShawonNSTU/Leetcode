class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            while(true) {
                if(i + 1 == nums[i]) break;
                else if(nums[nums[i]-1] == nums[i]) {
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                else if(nums[nums[i]-1] == 0) {
                    nums[nums[i]-1] = nums[i];
                    nums[i] = 0;
                    break;
                }
                else swap(nums[nums[i]-1], nums[i]);
            }
        }
        return res;
    }
};