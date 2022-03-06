class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i) {
            string str = to_string(nums[i]);
            string newStr = "";
            for(char ch : str) {
                int val = ch - '0';
                newStr += (mapping[val] + '0');
            }
            int newNum = stoi(newStr);
            auto it = mp.find(newNum);
            if(it != mp.end()) mp[newNum].push_back(nums[i]);
            else {
                vector<int> v;
                v.push_back(nums[i]);
                mp[newNum] = v;
            }
        }
        vector<int> res;
        for(auto myPair : mp) {
            vector<int> v = myPair.second;
            for(int val : v) {
                res.push_back(val);
            }
        }
        return res;
    }
};