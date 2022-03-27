public class Solution {
    public class CustomPriority : IComparer<int[]> {
        public int Compare(int[] arr1, int[] arr2) {
            if(arr1[0] < arr2[0] || (arr1[0] == arr2[0] && arr1[1] < arr2[1])) return -1;
            else return 1;
        }
    }
    private int BinarySearch(int[] arr) {
        int lo = 0, hi = arr.Length - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] == 1) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi + 1;
    }
    public int[] KWeakestRows(int[][] mat, int k) {
        PriorityQueue<int, int[]> pq = new PriorityQueue<int, int[]>(new CustomPriority());
        for(int i = 0; i < mat.Length; ++i) {
            pq.Enqueue(i, new int[]{BinarySearch(mat[i]), i});
        }
        int[] res = new int[k];
        for(int i = 0; i < k; ++i) res[i] = pq.Dequeue();
        return res;
    }
}