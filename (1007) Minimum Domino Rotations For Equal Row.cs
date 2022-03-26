public class Solution {
    private int minRotation(int n, int[] tops, int[] bottoms) {
        int[] cnt1 = new int[7], cnt2 = new int[7];
        for(int i = 0; i < n; ++i) {
            cnt1[tops[i]]++;
            if((tops[i] ^ bottoms[i]) > 0) cnt2[bottoms[i]]++;
        }
        for(int i = 1; i < 7; ++i) {
            if(cnt1[i] + cnt2[i] >= n) return Math.Min(n - cnt1[i], n - cnt2[i]);
        }
        return -1;
    }
    public int MinDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.Length;
        return Math.Min(minRotation(n, tops, bottoms), minRotation(n, bottoms, tops));
    }
}
