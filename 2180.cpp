class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i = 1; i <= num; i++) {
            int N = i;
            int sum = 0;
            while(N != 0) {
                int r = N % 10;
                sum += r;
                N = N / 10;
            }
            if(sum % 2 == 0) ++cnt;
        }
        return cnt;
    }
};