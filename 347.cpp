class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        unordered_map<int, int> ump;
        
        for(int num : nums) ump[num]++;
        
        vector<int> freq[nums.size() + 1];
        for(auto x : ump) freq[x.second].push_back(x.first);
        
        int cnt = 0;
        bool flag = true;
        for(int i = nums.size(); i >= 0; i--) {
            for(int x : freq[i]) {
                res.push_back(x);
                cnt++;
                if(cnt == k) {flag = false; break;}
            }
            if(!flag) break;
        }
        
        return res;
    }
};