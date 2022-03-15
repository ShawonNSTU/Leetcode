class Solution {
public:
    string getValidParentheses(string s, char leadCh) {
        int leadChCnt = 0;
        string str = "";
        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z') str += ch;
            else if(ch == leadCh) {
                ++leadChCnt;
                str += ch;
            }
            else if(leadChCnt) {
                str += ch;
                --leadChCnt;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string minRemoveToMakeValid(string s) {
        string res = getValidParentheses(s, '(');
        return getValidParentheses(res, ')');
    }
};