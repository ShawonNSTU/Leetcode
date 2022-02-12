class Solution {
public:
    string minWindow(string s, string t) {
        
        int len1 = s.length();
        int len2 = t.length();
        if(len1 < len2) return "";
        
        int countS[130] = {0}, countT[130] = {0};
        int distinctCnt = 0;
        
        for(int i = 0; i < len2; i++) {
            char ch = t[i];
            if(!countT[ch]) distinctCnt++;
            countT[ch]++;
        }
        
        int l = 0, matchCnt = 0, minLen = 100005;
        int need = distinctCnt;
        int l1, l2;
        
        for(int r = 0; r < len1; r++) {
            
            char ch = s[r];
            countS[ch]++;
            if(countT[ch] == countS[ch]) matchCnt++;
            
            if(matchCnt == need) {
                while(true) {
                    if(minLen > r - l + 1) {
                        minLen = r - l + 1;
                        l1 = l, l2 = r;
                    }
                    int leftCh = s[l];
                    countS[leftCh]--;
                    if(countT[leftCh] > countS[leftCh]) matchCnt--;
                    l++;
                    if(matchCnt != need) break;
                }
            }
        }
        
        return (minLen != 0 && minLen != 100005) ? s.substr(l1, l2-l1+1) : "";
    }
};