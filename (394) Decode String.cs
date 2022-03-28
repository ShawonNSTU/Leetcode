public class Solution {
    private bool IsDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    private string Reverse(string str) {
        char[] charArr = str.ToCharArray();
        Array.Reverse(charArr);
        return new string(charArr);
    }
    private int RepeatCnt(ref Stack<char> st) {
        int p = 0, cnt = 0;
        while(st.Count > 0 && IsDigit(st.Peek())) {
            cnt += (st.Pop() - '0') * (int) Math.Pow(10, p++);
        }
        return cnt;
    }
    public string DecodeString(string s) {
        Stack<char> st = new Stack<char>();
        foreach(char ch in s) {
            if(ch == ']') {
                var eStr = new StringBuilder();
                while(st.Peek() != '[') eStr.Append(st.Pop());
                st.Pop();
                string dStr = String.Concat(Enumerable.Repeat(Reverse(eStr.ToString()), RepeatCnt(ref st)));
                foreach(char c in dStr) st.Push(c);
            }
            else st.Push(ch);
        }
        var sb = new StringBuilder();
        while(st.Count > 0) sb.Append(st.Pop());
        return Reverse(sb.ToString());
    }
}