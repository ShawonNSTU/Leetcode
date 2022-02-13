class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        sort(beans.begin(), beans.end());
        
        const int MAX_SIZE = 100001;
        long long prefix[MAX_SIZE] = {0}, suffix[MAX_SIZE] = {0};
        
        long long n = beans.size();
        prefix[0] = beans[0];
        
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + beans[i];
        for(int i = n-1; i >= 0; i--) suffix[i] = suffix[i+1] + beans[i];
        
        long long ans = prefix[n-1] - (n * beans[0]);
        
        for(int i = 1; i < n; i++) {
            long long a = prefix[i-1] + suffix[i+1];
            long long b = (n-i-1) * beans[i];
            ans = min(ans, a-b);
        }
        
        return ans;
    }
};