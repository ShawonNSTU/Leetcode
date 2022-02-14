class Solution {
public:
    int numSplits(string s) {
        
        int n = s.length();
        int pArr[26] = {0}, sArr[26] = {0};
        int prefix[n], suffix[n];
        int cnt1 = 0, cnt2 = 0;
        
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(!pArr[idx]) {
                ++cnt1, pArr[idx] = 1;
            }
            prefix[i] = cnt1;
        }
        
        for(int i = n-1; i >= 0; i--) {
            int idx = s[i] - 'a';
            if(!sArr[idx]) {
                ++cnt2, sArr[idx] = 1;
            }
            suffix[i] = cnt2;
        }
        
        int goodWay = 0;
        for(int i = 1; i < n; i++) {
            if(prefix[i-1] == suffix[i]) ++goodWay;
        }
        
        return goodWay;
    }
};