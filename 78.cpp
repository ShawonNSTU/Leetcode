class Solution {
    
    int n;
    vector<int> subset, arr;
    vector<vector<int>> res;
    
    void DFS(int idx) {
        if(idx == n) {
            res.push_back(subset);
            return;
        }
        subset.push_back(arr[idx]);
        DFS(idx + 1);
        subset.pop_back();
        DFS(idx + 1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        DFS(0);
        return res;
    }
};