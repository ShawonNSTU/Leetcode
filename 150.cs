public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> st = new Stack<int>();
        string[] operators = {"+", "-", "*", "/"};
        foreach(string str in tokens) {
            if(!operators.Contains(str)) st.Push(int.Parse(str));
            else {
                int s = st.Pop();
                int t = st.Pop();
                if(str == operators[0]) st.Push(t + s);
                else if(str == operators[1]) st.Push(t - s);
                else if(str == operators[2]) st.Push(t * s);
                else st.Push(t / s);
            }
        }
        return st.Pop();
    }
}