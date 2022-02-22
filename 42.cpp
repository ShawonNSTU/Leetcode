// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax[n], rightMax[n];
        leftMax[0] = 0, rightMax[n-1] = 0;
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[0], rightMax = height[r];
        int res = 0;
        while(l < r) {
            if(leftMax < rightMax) {
                ++l;
                res += max(0, leftMax - height[l]);
                leftMax = max(leftMax, height[l]);
            }
            else {
                --r;
                res += max(0, rightMax - height[r]);
                rightMax = max(rightMax, height[r]);
            }
        }
        return res;
    }
};