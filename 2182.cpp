class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int, int>> pq;
        int cnt[26] = {0};
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            cnt[idx]++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(cnt[i] > 0) {
                pq.push({i, cnt[i]});
            }
        }
        
        pair<int, int> prev = {-1, 0};
        string res = "";
        
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            
            if(prev.second > 0) pq.push(prev);
            
            int idx = p.first;
            int freq = p.second;
            
            if(prev.second > 0 && prev.first > idx) {
                res += ('a' + idx);
                --freq;
            }
            else {
                for(int i = 0; i < repeatLimit; i++) {
                    res += ('a' + idx);
                    --freq;
                    if(freq == 0) break;
                }
            }
            
            prev = {idx, freq};
        }
        
        return res;
    }
};