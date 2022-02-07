class Solution {
    
    string w;
    vector<vector<char>> matrix;
    int rows, cols;
    bool flag[6][6];
    
    bool DFS(int r, int c, int i) {
        if(i == w.length()) return true;
        if(r < 0 || c < 0 || r >= rows || c >= cols || matrix[r][c] != w[i] || flag[r][c]) {
            return false;
        }
        flag[r][c] = true;
        bool res = DFS(r+1, c, i+1) || DFS(r-1, c, i+1) || DFS(r, c+1, i+1) || DFS(r, c-1, i+1);
        flag[r][c] = false;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        matrix = board;
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(DFS(i, j, 0)) return true;
            }
        }
        return false;
    }
};