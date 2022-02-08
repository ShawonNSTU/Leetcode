class Solution {
    
    map<int, bool> mp;
    vector<int>adjList[5005];
    
    bool DFS(int courseId) {
        if(mp[courseId]) return false;
        if(adjList[courseId].size() == 0) return true;
        mp[courseId] = true;
        for(int preCrs : adjList[courseId]) {
            bool res = DFS(preCrs);
            if(!res) return false;
        }
        mp[courseId] = false;
        adjList[courseId].clear();
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for(int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }
        for(int i = 0; i < numCourses; i++) {
            if(DFS(i) == false) return false;
        }
        return true;
    }
};