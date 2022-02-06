class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m == 1 || n == 1) return 1;
        
        int arr[m][n];
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            arr[m-1][i] = 1;
        }
        
        for(int i = 0; i < m-1; i++) {
            arr[i][n-1] = 1;
        }
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(!arr[i][j]) {
                    arr[i][j] += (arr[i][j+1] + arr[i+1][j]);
                }
            }
        }
        
        return arr[0][0];
    }
};