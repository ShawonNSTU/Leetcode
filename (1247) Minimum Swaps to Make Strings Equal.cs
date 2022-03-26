public class Solution {
    public int MinimumSwap(string s1, string s2) {
        int xCnt = 0, yCnt = 0;
        for(int i = 0; i < s1.Length; ++i) {
            if(s1[i] != s2[i]) {
                if(s1[i] == 'x') ++xCnt;
                else ++yCnt;
            }
        }
        int res = xCnt / 2 + yCnt / 2;
        if(xCnt % 2 == 1 && yCnt % 2 == 1) res += 2;
        else if(xCnt % 2 == 0 && yCnt % 2 == 0) res += 0;
        else res = -1;
        return res;
    }
}