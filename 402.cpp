class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int j = 0;
        int n = num.length();
        for(int i = 0; i < n; i++) {
            while(k > 0 && j > 0 && res[j-1] > num[i]) {
                res.pop_back();
                --j, --k;
            }
            if(num[i] == '0' && j == 0) continue;
            res.push_back(num[i]);
            ++j;
        }
        while(k > 0 && j > 0) res.pop_back(), --j, --k;
        if(j == 0) res = "0";
        return res;
    }
};