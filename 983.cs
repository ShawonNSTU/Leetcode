// Without Memorization (Brute Force Approach)
public class Solution {
    int minCost = Int32.MaxValue;
    private void DFS(int idx, int currCost, int[] days, int[] costs) {
        if(idx >= days.Length) {
            minCost = Math.Min(minCost, currCost);
            return;
        }
        DFS(idx + 1, currCost + costs[0], days, costs);
        int i, validDay = days[idx] + 6;
        for(i = idx; i < days.Length; ++i) {
            if(days[i] > validDay) break;
        }
        DFS(i, currCost + costs[1], days, costs);
        validDay = days[idx] + 29;
        for(i = idx; i < days.Length; ++i) {
            if(days[i] > validDay) break;
        }
        DFS(i, currCost + costs[2], days, costs);
    }
    public int MincostTickets(int[] days, int[] costs) {
        DFS(0, 0, days, costs);
        return minCost;
    }
}

// With Memorization/Cache (DP Approach)
public class Solution {
    Dictionary<int, int> dict = new Dictionary<int, int>();
    private int DFS(int idx, int currCost, int[] days, int[] costs) {
        if(dict.ContainsKey(idx)) return currCost + dict[idx];
        if(idx >= days.Length) return currCost;
        int a = DFS(idx + 1, currCost + costs[0], days, costs);
        int i, validDay = days[idx] + 6;
        for(i = idx; i < days.Length; ++i) {
            if(days[i] > validDay) break;
        }
        int b = DFS(i, currCost + costs[1], days, costs);
        validDay = days[idx] + 29;
        for(i = idx; i < days.Length; ++i) {
            if(days[i] > validDay) break;
        }
        int c = DFS(i, currCost + costs[2], days, costs);
        int x = Math.Abs(a - currCost), y = Math.Abs(b - currCost), z = Math.Abs(c - currCost);
        dict.Add(idx, Math.Min(x, Math.Min(y, z)));
        return currCost + dict[idx];
    }
    public int MincostTickets(int[] days, int[] costs) {
        return DFS(0, 0, days, costs);
    }
}