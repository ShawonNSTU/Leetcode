class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int prevL = intervals[0][0], prevR = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > prevR) {
                res.push_back(vector<int>{prevL, prevR});
                prevL = intervals[i][0];
            }
            prevR = max(prevR, intervals[i][1]);
        }
        res.push_back(vector<int>{prevL, prevR});
        return res;
    }
};