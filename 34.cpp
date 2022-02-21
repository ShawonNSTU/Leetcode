class Solution {
    
    int binarySearch(vector<int>& v, int t, bool isLower) {
        int l = 0, r = v.size() - 1;
        int pos = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(v[mid] > t) r = mid - 1;
            else if(v[mid] < t) l = mid + 1;
            else {
                pos = mid;
                if(isLower) r = mid - 1;
                else l = mid + 1;
            }
        }
        return pos;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        int l = binarySearch(nums, target, true);
        int r = binarySearch(nums, target, false);
        res[0] = l, res[1] = r;
        return res;
    }
};