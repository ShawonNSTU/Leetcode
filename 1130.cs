public class Solution {
    Dictionary<KeyValuePair<int, int>, KeyValuePair<int, int>> dict = new Dictionary<KeyValuePair<int, int>, KeyValuePair<int, int>>();
    private KeyValuePair<int, int> DFS(int start, int end, int[] arr) {
        if(start == end) return new KeyValuePair<int, int>(arr[start], 0);
        if(dict.ContainsKey(new KeyValuePair<int, int>(start, end))) return dict[new KeyValuePair<int, int>(start, end)];
        int currSum = Int32.MaxValue;
        int currMax = 50;
        for(int i = start; i < end; ++i) {
            KeyValuePair<int, int> l = DFS(start, i, arr);
            KeyValuePair<int, int> r = DFS(i + 1, end, arr);
            currSum = Math.Min(currSum, l.Value + r.Value + l.Key * r.Key);
            currMax = Math.Max(l.Key, r.Key);
        }
        KeyValuePair<int, int> currRes = new KeyValuePair<int, int>(currMax, currSum);
        dict.Add(new KeyValuePair<int, int>(start, end), currRes);
        return currRes;
    }
    public int MctFromLeafValues(int[] arr) {
        return DFS(0, arr.Length - 1, arr).Value;
    }
}