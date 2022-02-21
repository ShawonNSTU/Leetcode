class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int row = floor(mid / m);
            int col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};