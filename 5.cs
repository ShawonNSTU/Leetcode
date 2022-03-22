public class Solution {
    private string getPalindrome(string s, bool isEvenLength) {
        int l = 0, r = 0, maxCnt = 0;
        for(int i = 0; i < s.Length; ++i) {
            int j = i - 1, k = i + 1;
            int cnt = 0;
            if(isEvenLength) k = i;
            while(j >= 0 && k < s.Length && s[j] == s[k]) {
                ++cnt; --j; ++k;
            }
            if(maxCnt < cnt) {
                maxCnt = cnt;
                l = j + 1; r = k - 1;
            }
        }
        return s.Substring(l, r - l + 1);
    }
    public string LongestPalindrome(string s) {
        string oddL = getPalindrome(s, false);
        string evenL = getPalindrome(s, true);
        return oddL.Length > evenL.Length ? oddL : evenL;
    }
}