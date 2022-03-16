class Solution {
public:
    bool isValid(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++, --j;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        bool flag = false;
        while(i <= j) {
            if(s[i] == s[j]) ++i, --j;
            else if(!flag) {
                if(s[i+1] == s[j] && s[i] == s[j-1]) return isValid(i+2, j-1, s) | isValid(i+1, j-2, s);
                else if(s[i+1] == s[j]) i += 2, --j, flag = true;
                else if(s[i] == s[j-1]) ++i, j -= 2, flag = true;
                else return false;
            }
            else return false;
        }
        return true;
    }
};