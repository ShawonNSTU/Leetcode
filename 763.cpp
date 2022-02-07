class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        vector<int> arr(26, -1);
        
        for(int i = 0; i < n; i++) {
            arr[s[i]-'a'] = i;
        }
        
        vector<int> res;
        int cnt = 0;
        int lastIdx = 0;
        
        for(int i = 0; i < n; i++) {
            ++cnt;
            if(lastIdx < arr[s[i]-'a']) {
                lastIdx = arr[s[i]-'a'];
            }
            if(lastIdx == i) {
                res.push_back(cnt);
                cnt = 0;
            }
        }
        
        return res;
    }
};