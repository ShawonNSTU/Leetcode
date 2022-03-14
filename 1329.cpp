// Naive Approach
class Solution {
public:
    int m, n;
    // The number of diagonals in M×N matrix is M+N−1
    void sortMatrixDiagonal(int s, int e, vector<vector<int>> &mat, bool flag) {
        for(int i = s; i < e; ++i) {
            int r, c, idx = 0;
            if(flag) r = i, c = 0;
            else r = 0, c = i;
            vector<int> currDiagonal;
            while(r < m && c < n) {
                currDiagonal.push_back(mat[r][c]);
                ++r, ++c;
            }
            sort(currDiagonal.begin(), currDiagonal.end());
            if(flag) r = i, c = 0;
            else r = 0, c = i;
            while(r < m && c < n) {
                mat[r][c] = currDiagonal[idx++];
                ++r, ++c;
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        sortMatrixDiagonal(0, m, mat, true);
        sortMatrixDiagonal(1, n, mat, false);
        return mat;
    }
};

// Greedy Approach
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> ump;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ump[i-j].push(mat[i][j]);
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = ump[i-j].top();
                ump[i-j].pop();
            }
        }
        return mat;
    }
};