class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int minElement = INT_MAX, ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int val = nums[i] << 1;
            if(!(nums[i] & 1)) val = nums[i];
            pq.push(val);
            minElement = min(minElement, val);
        }
        while(!(pq.top() & 1)) {
            int max = pq.top();
            pq.pop();
            ans = min(ans, max - minElement);
            pq.push(max >> 1);
            minElement = min(minElement, max >> 1);
        }
        return min(pq.top() - minElement, ans);
    }
};