// Time Complexity: O(MN)
class Solution {
public:
    int binaryToDecimal(string num) {
        int decValue = 0, base = 1, len = num.length();
        for(int i = len - 1; i >= 0; --i) {
            if(num[i] == '1') decValue += base;
            base *= 2;
        }
        return decValue;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            if(!grid[i][0]) {
                for(int j = 0; j < n; ++j) grid[i][j] ^= 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            int one = 0;
            for(int j = 0; j < m; ++j) {
                if(grid[j][i]) ++one;
            }
            if(m - one >= one) {
                for(int j = 0; j < m; ++j) grid[j][i] ^= 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < m; ++i) {
            string num = "";
            for(int j = 0; j < n; ++j) num += grid[i][j] + 48;
            sum += binaryToDecimal(num);
        }
        return sum;
    }
};
