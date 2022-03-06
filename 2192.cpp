class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int src, int par, vector<int> adj[], vector<int> &vis, vector<int> &temp) {
        if(src != par) temp.push_back(src);
        vis[src] = 1;
        for(int u : adj[src]) if(!vis[u]) dfs(u, par, adj, vis, temp);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i : edges) adj[i[1]].push_back(i[0]);
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            vector<int> temp;
            dfs(i, i, adj, vis, temp);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};