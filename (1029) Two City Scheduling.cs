public class Solution {
    public int TwoCitySchedCost(int[][] costs) {
        PriorityQueue<int, int> pqA = new PriorityQueue<int, int>();
        PriorityQueue<int, int> pqB = new PriorityQueue<int, int>();
        for(int i = 0; i < costs.Length; ++i) {
            int diff = costs[i][0] - costs[i][1];
            pqA.Enqueue(costs[i][0], diff);
            pqB.Enqueue(costs[i][1], diff);
        }
        int res = 0;
        for(int i = 0; i < costs.Length / 2; ++i) {
            res += pqA.Dequeue();
            pqB.Dequeue();
        }
        for(int i = 0; i < costs.Length / 2; ++i) {
            res += pqB.Dequeue();
        }
        return res;
    }
}
