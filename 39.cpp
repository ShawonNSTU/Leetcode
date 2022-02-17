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
        dfs(idx, currTotal + v[idx], currList);
        currList.pop_back();
        dfs(idx + 1, currTotal, currList);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currList;
        v = candidates, n = v.size(), T = target;
        dfs(0, 0, currList);
        return res;
    }
};