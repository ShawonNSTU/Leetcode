public class Solution {
    private bool BFS(int start, int[] color, int[][] graph) {
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        while(q.Count > 0) {
            int u = q.Dequeue();
            foreach(int v in graph[u]) {
                if(color[v] == 0) {
                    color[v] = color[u] == 1 ? 2 : 1;
                    q.Enqueue(v);
                }
                else if(color[u] == color[v]) return false;
            }
        }
        return true;
    }
    public bool IsBipartite(int[][] graph) {
        int n = graph.Length;
        int[] color = new int[n];
        for(int i = 0; i < n; ++i) {
            if(color[i] == 0) {
                color[i] = 1;
                if(!BFS(i, color, graph)) return false;
            }
        }
        return true;
    }
}