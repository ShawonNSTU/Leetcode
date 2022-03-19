public class FreqStack {
    
    Dictionary<int, Stack<int>> dict;
    Dictionary<int, int> freq;
    int currMaxFreq;
    
    public FreqStack() {
        dict = new Dictionary<int, Stack<int>>();
        freq = new Dictionary<int, int>();
        currMaxFreq = 0;
    }
    
    public void Push(int val) {
        if(!freq.ContainsKey(val)) freq.Add(val, 0);
        freq[val]++;
        if(!dict.ContainsKey(freq[val])) dict.Add(freq[val], new Stack<int>());
        dict[freq[val]].Push(val);
        currMaxFreq = Math.Max(currMaxFreq, freq[val]);
    }
    
    public int Pop() {
        if(dict[currMaxFreq].Count == 0) --currMaxFreq;
        int r = dict[currMaxFreq].Pop();
        freq[r]--;
        return r;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.Push(val);
 * int param_2 = obj.Pop();
 */