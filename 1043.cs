public class Solution {
    public int MaxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.Length;
        int[] dp = new int[n + 1];
        for(int i = 0; i < n; ++i) {
            int subArrMax = arr[i], currMax = arr[i];
            for(int j = i; j > i - k && j >= 0; --j) {
                currMax = Math.Max(arr[j], currMax);
                int currSum = currMax * (i - j + 1);
                subArrMax = Math.Max(dp[j] + currSum, subArrMax);
            }
            dp[i + 1] = subArrMax;
        }
        return dp[n];
    }
}