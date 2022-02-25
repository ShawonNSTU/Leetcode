// Sliding Window Technique
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, res = 0;
        vector<int> pos(256, -1);
        for(int i = 0; i < n; i++) {
            if(pos[s[i]] >= 0) {
                res = max(res, i - l);
                for(int j = l; j < pos[s[i]]; j++) pos[s[j]] = -1;
                l = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
        }
        return max(res, n - l);
    }
};