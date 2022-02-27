class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1, hi = 1e14;
        while(lo < hi) {
            long long mid = (lo + hi) >> 1;
            long long tripCnt = 0;
            for(int t : time) {
                tripCnt += mid/t;
                if(tripCnt > totalTrips) break;
            }
            if(tripCnt >= totalTrips) hi = mid;
            else lo = mid + 1;
        }
        return hi;
    }
};