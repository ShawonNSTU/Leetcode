// DFS Approach
class Solution {
public:
    void DFS(int u, vector<bool> &vis, vector<int> adj[], set<int> &vertexSet) {
        vis[u] = true;
        for(auto v : adj[u]) {
            if(vis[v]) vertexSet.erase(v);
            else DFS(v, vis, adj, vertexSet);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto v : edges) adj[v[0]].push_back(v[1]);
        vector<bool> vis(n, false);
        set<int> vertexSet;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                DFS(i, vis, adj, vertexSet);
                vertexSet.insert(i);
            }
        }
        return vector<int> (vertexSet.begin(), vertexSet.end());
    }
};

// Greedy Approach
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], res;
        for(auto v : edges) adj[v[1]].push_back(v[0]);
        for(int i = 0; i < n; ++i) {
            if(adj[i].size() == 0) res.push_back(i);
        }
        return res;
    }
};