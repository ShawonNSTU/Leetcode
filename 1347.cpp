class Solution {
public:
    int minSteps(string s, string t) {
        int cntS[26] = {0}, cntT[26] = {0}, step = 0;
        for(char ch : s) cntS[ch-'a']++;
        for(char ch : t) cntT[ch-'a']++;
        for(int i = 0; i < 26; ++i) {
            if(cntS[i] > cntT[i]) step += cntS[i] - cntT[i];
        }
        return step;
    }
};