// Time Complexity: O(n*nlogn)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res;
        vector<int> v, vis(n, 0);
        for(int j = 0; j < n; ++j) {
            int currMinHeight = 1000001, idx = -1;
            for(int i = 0; i < n; ++i) {
                if(!vis[i]) {
                    int k = v.size() - (lower_bound(v.begin(), v.end(), people[i][0]) - v.begin());
                    if(k == people[i][1] && currMinHeight > people[i][0]) {
                        currMinHeight = people[i][0];
                        idx = i;
                    }
                }
            }
            vis[idx] = 1;
            res.push_back(people[idx]);
            v.push_back(people[idx][0]);
            sort(v.begin(), v.end());
        }
        return res;
    }
};

// Time Complexity: O(n*n)
class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        else return v1[1] > v2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), vector<int>());
        for(int i = 0; i < people.size(); ++i) {
            int cnt = 0, j = 0;
            for(; j < res.size(); ++j) {
                if(res[j].empty()) {
                    if(cnt == people[i][1]) break;
                    cnt++;
                }
            }
            res[j] = people[i];
        }
        return res;
    }
};