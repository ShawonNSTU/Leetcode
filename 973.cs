// Set and Hashtable
public class Solution {
    public int[][] KClosest(int[][] points, int k) {
        SortedSet<int> distSet = new SortedSet<int>();
        Hashtable tb = new Hashtable();
        for(int i = 0; i < points.Length; ++i) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distSet.Add(d);
            if(!tb.ContainsKey(d)) tb.Add(d, new List<int>());
            ((List<int>)tb[d]).Add(i);
        }
        int[][] res = new int[k][];
        int cnt = 0;
        foreach(int d in distSet) {
            List<int> l = (List<int>)tb[d];
            foreach(int idx in l) {
                if(cnt < k) {
                    res[cnt] = points[idx];
                    ++cnt;
                }
                else return res;
            }
        }
        return res;
    }
}

// Sorting
public class Solution {
    public static int Compare(KeyValuePair<int, int> a, KeyValuePair<int, int> b) {
        return a.Key.CompareTo(b.Key);
    }
    public int[][] KClosest(int[][] points, int k) {
        int n = points.Length;
        KeyValuePair<int, int>[] dist = new KeyValuePair<int, int>[n];
        for(int i = 0; i < n; ++i) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            dist[i] = new KeyValuePair<int, int>(d, i);
        }
        Array.Sort(dist, Compare);
        int[][] res = new int[k][];
        for(int i = 0; i < k; ++i) {
            res[i] = points[dist[i].Value];
        }
        return res;
    }
}

// Priority Queue
public class Solution {
    public int[][] KClosest(int[][] points, int k) {
        PriorityQueue<KeyValuePair<int, int>, int> pq = new PriorityQueue<KeyValuePair<int, int>, int>();
        for(int i = 0; i < points.Length; ++i) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.Enqueue(new KeyValuePair<int, int>(d, i), d);
        }
        int[][] res = new int[k][];
        for(int i = 0; i < k; ++i) {
            res[i] = points[pq.Dequeue().Value];
        }
        return res;
    }
}