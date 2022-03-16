// Time Complexity: O(m*n)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        for(auto p : firstList) {
            int l = p[0], r = p[1];
            for(int i = 0; i < secondList.size(); ++i) {
                if(l <= secondList[i][0] && secondList[i][0] <= r) {
                    res.push_back(vector<int> {secondList[i][0], min(r, secondList[i][1])});
                }
                else if(l >= secondList[i][0] && l <= secondList[i][1]) {
                    res.push_back(vector<int> {l, min(r, secondList[i][1])});
                }
            }
        }
        return res;
    }
};

// Time Complexity: O(m+n) = Two Pointer
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()) {
            int l1 = firstList[i][0], r1 = firstList[i][1];
            int l2 = secondList[j][0], r2 = secondList[j][1];
            if(l1 <= l2 && l2 <= r1) {
                res.push_back(vector<int> {l2, min(r1, r2)});
            }
            else if(l1 >= l2 && l1 <= r2) {
                res.push_back(vector<int> {l1, min(r1, r2)});
            }
            if(r1 < r2) ++i;
            else if(r1 > r2) ++j;
            else ++i, ++j;
        }
        return res;
    }
};