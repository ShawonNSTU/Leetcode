class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if(finalSum % 2) return res;
        long long curr = 2;
        bool flag = true;
        while(finalSum > curr) {
            long long diff = finalSum - curr;
            if(diff <= curr) {
                flag = false;
                break;
            }
            res.push_back(curr);
            finalSum = diff;
            curr += 2;
        }
        if(!flag) res.push_back(finalSum);
        else res.push_back(curr);
        return res;
    }
};