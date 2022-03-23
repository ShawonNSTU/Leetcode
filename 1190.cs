// Brute Force (N^2)
public class Solution {
    public string ReverseParentheses(string s) {
        Stack<char> st = new Stack<char>();
        foreach(char ch in s) {
            if(ch != ')') st.Push(ch);
            else {
                Queue<char> q = new Queue<char>();
                while(st.Peek() != '(') q.Enqueue(st.Pop());
                st.Pop();
                while(q.Count > 0) st.Push(q.Dequeue());
            }
        }
        var sb = new StringBuilder();
        foreach(char ch in st) sb.Append(ch);
        char[] charArray = sb.ToString().ToCharArray();
        Array.Reverse(charArray);
        return new String(charArray);
    }
}