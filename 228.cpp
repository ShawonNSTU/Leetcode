class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(!n) return res;
        int l = nums[0], r = nums[0];
        for(int i = 1; i < n; i++) {
            if(r + 1 == nums[i]) ++r;
            else {
                if(l == r) res.push_back(to_string(l));
                else res.push_back(to_string(l) + "->" + to_string(r));
                l = r = nums[i];
            }
        }
        if(l == r) res.push_back(to_string(l));
        else res.push_back(to_string(l) + "->" + to_string(r));
        return res;
    }
};