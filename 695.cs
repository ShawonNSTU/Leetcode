public class Solution {
    bool[,] vis = new bool[50, 50];
    int cnt;
    private void DFS(int r, int c, int m, int n, int[][] grid) {
        if(r < 0 || c < 0 || r == m || c == n || vis[r, c] == true || grid[r][c] == 0) return;
        vis[r, c] = true;
        ++cnt;
        DFS(r, c+1, m, n, grid);
        DFS(r, c-1, m, n, grid);
        DFS(r+1, c, m, n, grid);
        DFS(r-1, c, m, n, grid);
    }
    public int MaxAreaOfIsland(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int maxArea = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(vis[i,j] == false) {
                    cnt = 0;
                    DFS(i, j, m, n, grid);
                    maxArea = Math.Max(maxArea, cnt);
                }
            }
        }
        return maxArea;
    }
}