class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, int>> maxHeap;
        int n = s.length();
        
        int cnt[26] = {0};
        for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) maxHeap.push({cnt[i], i});
        }
        
        string res = "";
        pair<int, int> prev = {0, 0};
        
        while(!maxHeap.empty()) {
            pair<int, int> p = maxHeap.top();
            res += 'a' + p.second;
            maxHeap.pop(), p.first--;
            if(prev.first) maxHeap.push(prev);
            prev = p;
        }
        
        return res.length() == n ? res : "";
    }
};