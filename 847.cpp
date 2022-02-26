class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // If there is only one node in the input graph
        if(n == 1) return 0;
        
        // i.e. (1 << 3) - 1 = 2^3 - 1 = 7 = 111
        int finalState = (1 << n) - 1;
        
        queue<pair<int,int>> q;
        
        // Initially push all node to queue as there is no starting point
        for(int i = 0; i < n; i++) {
            q.push({i, 1 << i});    // 2^0, 2^1, 2^2, 2^3... = 0001, 0010, 0100, 1000...
        }
        
        vector<vector<int>> vis(n, vector<int>(finalState, 0));
        int cnt = 0;
        
        while(!q.empty()) {
            ++cnt;
            int qSize = q.size();
            while(qSize--) {
                pair<int,int> p = q.front();
                q.pop();
                int currNode = p.first;
                int currMask = p.second;
                for(int adj : graph[currNode]) {
                    // i.e. currMask = 0100 | (1 << 3) = 0100 | 1000 = 1100
                    int newMask = currMask | (1 << adj);
                    if(newMask == finalState) return cnt;
                    if(!vis[adj][newMask]) {
                        vis[adj][newMask] = 1;
                        q.push({adj, newMask});
                    }
                }
            }
        }
        
        return 0;
    }
};