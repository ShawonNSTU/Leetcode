class Solution {
public:
    int minSteps(string s, string t) {
        int cntS[26] = {0}, cntT[26] = {0};
        for(char ch : s) cntS[ch-'a']++;
        for(char ch : t) cntT[ch-'a']++;
        int res = 0;
        for(int i = 0; i < 26; i++) res += max(0, cntT[i] - cntS[i]);
        for(int i = 0; i < 26; i++) res += max(0, cntS[i] - cntT[i]);
        return res;
    }
};