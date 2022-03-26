public class Solution {
    public int Search(int[] nums, int target) {
        int lo = 0, hi = nums.Length - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
}