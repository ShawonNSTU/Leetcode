public class Solution {
    private void DFS(int u, IList<IList<int>> adj, bool[] vis) {
        vis[u] = true;
        foreach(var v in adj[u]) {
            if(!vis[v]) DFS(v, adj, vis);
        }
    }
    public bool CanVisitAllRooms(IList<IList<int>> rooms) {
        int n = rooms.Count;
        bool[] vis = new bool[n];
        DFS(0, rooms, vis);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) return false;
        }
        return true;
    }
}