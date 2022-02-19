class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        long long rem = num % 3;
        if(rem == 0) {
            long long div = num / 3;
            res.push_back(div - 1);
            res.push_back(div);
            res.push_back(div + 1);
        }
        return res;
    }
};