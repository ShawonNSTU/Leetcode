class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n);
        deque<int> dq;
        for(int i = 0; i < n; ++i) dq.push_back(i);
        int idx = 0, flag = 0;
        while(!dq.empty()) {
            if(!flag) {
                res[dq.front()] = deck[idx++];
                dq.pop_front();
            }
            else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            flag ^= 1;
        }
        return res;
    }
};