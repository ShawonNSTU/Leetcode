class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double arr[100][100] = {0.0};
        arr[0][0] = poured;
        for(int i = 0; i < query_row; ++i) {
            for(int j = 0; j < i + 1; ++j) {
                double flow = (arr[i][j] - 1) / 2.0;
                if(flow > 0) {
                    arr[i+1][j] += flow;
                    arr[i+1][j+1] += flow;
                }
            }
        }
        return min(1.0, arr[query_row][query_glass]);
    }
};