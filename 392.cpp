// Two Pointer Approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, cnt = s.size();
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == s[j]) ++j, --cnt;
        }
        return cnt > 0 ? false : true;
    }
};

// Binary Search Approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> ump;
        for(int i = 0; i < t.size(); ++i) ump[t[i]].push_back(i);
        int prevPos = -1;
        for(int i = 0; i < s.size(); ++i) {
            auto it = ump.find(s[i]);
            if(it != ump.end()) {
                vector<int> pos = it->second;
                int idx = upper_bound(pos.begin(), pos.end(), prevPos) - pos.begin();
                if(idx == pos.size()) return false;
                prevPos = pos[idx];
            }
            else return false;
        }
        return true;
    }
};