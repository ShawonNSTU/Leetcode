class Solution {
    
    int getRank(vector<vector<int>>& matrix, int n, int val) {
        
        int i = n - 1, j = 0;
        int rank = 0;
        
        while(i >= 0 && j < n) {
            if(matrix[i][j] > val) --i;
            else {
                rank = rank + i + 1;
                ++j;
            }
        }
        
        return rank;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = getRank(matrix, n, mid);
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        
        return hi;
    }
};