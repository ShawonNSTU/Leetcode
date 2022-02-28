// Time Complexity: O(n), as unordered_set takes O(1) in average!

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i]-1) == s.end()) {
                int seq = nums[i] + 1;
                while(s.find(seq) != s.end()) ++seq;
                len = max(len, seq - nums[i]);
            }
        }
        return len;
    }
};