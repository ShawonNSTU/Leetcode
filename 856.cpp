class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') st.push(0);
            else {
                int inner = st.top();
                st.pop();
                int outer = st.top();
                st.pop();
                st.push(outer + max(2*inner, 1));
            }
        }
        return st.top();
    }
};

/*

(()) = 2
()(()(())) = 7

*/