// Time Complexity: O(32*N)
// Space Complexity: O(1)
public class Solution {
    public int SingleNumber(int[] nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            int cnt = 0;
            for(int j = 0; j < nums.Length; ++j) {
                if(((nums[j] >> i) & 1) == 1) ++cnt;
            }
            if(cnt % 3 == 1) res += 1 << i;
        }
        return res;
    }
}