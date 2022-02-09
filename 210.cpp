class Solution {
    
    map<int, bool> mp;
    vector<int>adjList[5005];
    vector<int> crsPath;
    bool isAdded[2005] = {0};
    
    bool DFS(int courseId) {
        if(mp[courseId]) return false;
        if(adjList[courseId].size() == 0) {
            if(!isAdded[courseId]) {
                crsPath.push_back(courseId);
                isAdded[courseId] = 1;
            }
            return true;
        }
        mp[courseId] = true;
        for(int preCrs : adjList[courseId]) {
            bool res = DFS(preCrs);
            if(!res) return false;
        }
        mp[courseId] = false;
        adjList[courseId].clear();
        if(!isAdded[courseId]) {
            crsPath.push_back(courseId);
            isAdded[courseId] = 1;
        }
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for(int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }
        for(int i = 0; i < numCourses; i++) {
            if(DFS(i) == false) {
                crsPath.clear();
                break;
            }
        }
        return crsPath;
    }
};