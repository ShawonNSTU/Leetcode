class Solution {
    
    vector<vector<int>> res;
    int cnt, T;
    
    void dfs(int val, int currTotal, int k, vector<int>& currList) {
        if(currTotal == T && k == cnt) {
            res.push_back(currList);
            return;
        }
        if(val >= 10 || currTotal > T || k > cnt) return;
        currList.push_back(val);
        dfs(val + 1, currTotal + val, k + 1, currList);
        currList.pop_back();
        dfs(val + 1, currTotal, k, currList);
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currList;
        cnt = k, T = n;
        dfs(1, 0, 0, currList);
        return res;
    }
};