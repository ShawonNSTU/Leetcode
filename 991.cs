// Forward Traverse (Source -> Target)
// TLE
public class Solution {
    private int BFS(int s, int target) {
        int currLevel = 0;
        Queue<long> q = new Queue<long>();
        q.Enqueue(s);
        while(q.Count > 0) {
            ++currLevel;
            int qSize = q.Count;
            for(int i = 0; i < qSize; ++i) {
                long u = q.Dequeue();
                if(u * 2 == target || u - 1 == target) return currLevel;
                q.Enqueue(u*2);
                q.Enqueue(u-1);
            }
        }
        return -1;
    }
    public int BrokenCalc(int startValue, int target) {
        return BFS(startValue, target);
    }
}

// Backward Traverse (Target -> Source)
public class Solution {
    public int BrokenCalc(int startValue, int target) {
        int cnt = 0;
        while(target > startValue) {
            ++cnt;
            if((target & 1) == 1) ++target;
            else target /= 2;
        }
        return cnt + startValue - target;
    }
}