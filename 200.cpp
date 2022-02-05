class Solution {
    void DFS(vector<vector<char>>& matrix, int x, int y, int r, int c) {
        if(x < 0 || x >= r || y < 0 || y >=c || matrix[x][y] != '1') return ;
        matrix[x][y] = '2';
        DFS(matrix, x-1, y, r, c);
        DFS(matrix, x+1, y, r, c);
        DFS(matrix, x, y-1, r, c);
        DFS(matrix, x, y+1, r, c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if(rows == 0) return 0;
        
        int cols = grid[0].size();
        
        int islandCnt = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    DFS(grid, i, j, rows, cols);
                    ++islandCnt;
                }
            }
        }
        
        return islandCnt;
    }
};