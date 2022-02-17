class Solution {
    
    vector<vector<int>> res;
    vector<int> v;
    int n, T;
    
    void dfs(int idx, int currTotal, vector<int>& currList) {
        if(currTotal == T) {
            res.push_back(currList);
            return;
        }
        if(idx >= n || currTotal > T) return;
        currList.push_back(v[idx]);
        dfs(idx + 1, currTotal + v[idx], currList);
        currList.pop_back();
        while(idx + 1 < n && v[idx + 1] == v[idx]) ++idx;
        dfs(idx + 1, currTotal, currList);
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currList;
        v = candidates, n = v.size(), T = target;
        dfs(0, 0, currList);
        return res;
    }
};