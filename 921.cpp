class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(char ch : s) {
            if(ch == '(') st.push(ch);
            else if(st.empty() || st.top() != '(') ++cnt;
            else st.pop();
        }
        return cnt + st.size();
    }
};