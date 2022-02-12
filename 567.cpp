class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        
        int countS1[26] = {0}, countS2[26] = {0};
        for(int i = 0; i < len1; i++) {
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';
            countS1[idx1]++, countS2[idx2]++;
        }
        
        int matchCnt = 0;
        for(int i = 0; i < 26; i++) {
            if(countS1[i] == countS2[i]) ++matchCnt;
        }
        
        int l = 0;
        for(int i = len1; i < len2; i++) {
            
            if(matchCnt == 26) return true;
            
            int idx1 = s2[i] - 'a';
            countS2[idx1]++;
            if(countS1[idx1] == countS2[idx1]) matchCnt++;
            else if(countS1[idx1] + 1 == countS2[idx1]) --matchCnt;
            
            int idx2 = s2[l] - 'a';
            countS2[idx2]--;
            if(countS1[idx2] == countS2[idx2]) matchCnt++;
            else if(countS1[idx2] - 1 == countS2[idx2]) --matchCnt;
            
            ++l;
        }
        
        return matchCnt == 26;
    }
};