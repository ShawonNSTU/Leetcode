// Time Complexity: O(N*N)
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> maxCnt(n, 0), minCnt(n, 0);
        for(int i = n-1; i >= 0; --i) {
            int cnt1 = 0, cnt2 = 0;
            for(int j = i - 1; j >= 0; --j) {
                if(rating[j] > rating[i]) ++cnt1;
                else ++cnt2;
            }
            maxCnt[i] = cnt1, minCnt[i] = cnt2;
        }
        int res = 0;
        for(int i = n-1; i >= 0; --i) {
            for(int j = i - 1; j >= 0; --j) {
                if(rating[j] > rating[i]) res += maxCnt[j];
                else res += minCnt[j];
            }
        }
        return res;
    }
};