class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            intervals[i][1] *= -1;
        }
        
        sort(intervals.begin(), intervals.end());
        int prevR = intervals[0][1] * -1;
        int cnt = 0;
        
        for(int i = 1; i < n; i++) {
            int currR = intervals[i][1] * -1;
            if(currR <= prevR) ++cnt;
            else prevR = currR;
        }
        
        return n - cnt;
    }
};