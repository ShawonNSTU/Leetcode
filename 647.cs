public class Solution {
    private int GetPalindromeCount(string s, bool isEvenLength) {
        int cnt = 0;
        for(int i = 0; i < s.Length; ++i) {
            int j = i - 1, k = i + 1;
            if(isEvenLength) k = i;
            while(j >= 0 && k < s.Length && s[j] == s[k]) {
                ++cnt; --j; ++k;
            }
        }
        return cnt;
    }
    public int CountSubstrings(string s) {
        return s.Length + GetPalindromeCount(s, false) + GetPalindromeCount(s, true);
    }
}