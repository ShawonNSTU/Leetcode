class Solution {
public:
    bool isValid(int r, int c, int n) {
        return r < n && c >= 0 && c < n;
    }
    int DFS(int r, int c, int n, int currSum, vector<vector<int>>& matrix, vector<vector<int>>& cache) {
        if(cache[r][c] != INT_MAX) return currSum + cache[r][c];
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        if(isValid(r+1, c-1, n)) x = DFS(r+1, c-1, n, currSum + matrix[r][c], matrix, cache);
        if(isValid(r+1, c, n)) y = DFS(r+1, c, n, currSum + matrix[r][c], matrix, cache);
        if(isValid(r+1, c+1, n)) z = DFS(r+1, c+1, n, currSum + matrix[r][c], matrix, cache);
        int minSum = min(x, min(y, z));
        if(minSum == INT_MAX) cache[r][c] = matrix[r][c];
        else cache[r][c] = minSum - currSum;
        return currSum + cache[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(100, vector<int>(100, INT_MAX));
        int n = matrix.size(), res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            res = min(res, DFS(0, i, n, 0, matrix, cache));
        }
        return res;
    }
};