public class Solution {
    public string GetSmallestString(int n, int k) {
        int currSum = n, cnt = 0;
        var sb = new StringBuilder();
        while(currSum != k) {
            ++cnt; --currSum;
            int x = k - currSum;
            if(x > 26) {
                sb.Append('z');
                currSum += 26;
            }
            else {
                sb.Append(Convert.ToChar(97 + x - 1));
                currSum += x;
            }
        }
        for(int i = cnt; i < n; ++i) sb.Append('a');
        char[] charArray = sb.ToString().ToCharArray();
        Array.Reverse(charArray);
        return new string(charArray);
    }
}