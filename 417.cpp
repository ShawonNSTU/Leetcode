class Solution {
public:
    void DFS(int r, int c, vector<vector<bool>> &vis, vector<vector<int>>& heights, int prevHeight) {
        if(r < 0 || c < 0 || r == vis.size() || c == vis[0].size() || prevHeight > heights[r][c] || vis[r][c]) return;
        vis[r][c] = true;
        DFS(r, c+1, vis, heights, heights[r][c]);
        DFS(r, c-1, vis, heights, heights[r][c]);
        DFS(r+1, c, vis, heights, heights[r][c]);
        DFS(r-1, c, vis, heights, heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacificVis(m, vector<bool>(n, 0)), atlanticVis(m, vector<bool>(n, 0));
        vector<vector<int>> res;
        for(int i = 0; i < m; ++i) {
            DFS(i, 0, pacificVis, heights, heights[i][0]);
            DFS(i, n-1, atlanticVis, heights, heights[i][n-1]);
        }
        for(int i = 0; i < n; ++i) {
            DFS(0, i, pacificVis, heights, heights[0][i]);
            DFS(m-1, i, atlanticVis, heights, heights[m-1][i]);
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pacificVis[i][j] && atlanticVis[i][j]) res.push_back(vector<int>{i, j});
            }
        }
        return res;
    }
};