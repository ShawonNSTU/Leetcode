// Binary Search in Sorted Set
// TLE, because accessing set via index is costly
public class Solution {
    SortedSet<int> st = new SortedSet<int>();
    private int binary_search(int l, int r, int num) {
        while(l <= r) {
            int mid = (l + r) / 2;
            if(st.ElementAt(mid) == num) return mid;
            else if(st.ElementAt(mid) > num) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
    public int NumRescueBoats(int[] people, int limit) {
        int[] freq = new int[limit + 1];
        int boatCnt = 0;
        Array.Sort(people);
        foreach(int weight in people) {
            st.Add(weight);
            ++freq[weight];
        }
        for(int i = 0; i < people.Length; ++i) {
            int diff = limit - people[i];
            if(freq[people[i]] > 0) {
                int pos = binary_search(0, st.Count - 1, diff);
                if(pos >= 0) {
                    int num = st.ElementAt(pos);
                    if(--freq[num] == 0) st.Remove(num);
                }
                if(--freq[people[i]] == 0) st.Remove(people[i]);
                ++boatCnt;
            }
        }
        return boatCnt;
    }
}

// Greedy, Two Pointer Technique
public class Solution {
    public int NumRescueBoats(int[] people, int limit) {
        Array.Sort(people);
        int l = 0, r = people.Length - 1, cnt = 0;
        while(l <= r) {
            if(people[l] + people[r] <= limit) ++l;
            --r;
            ++cnt;
        }
        return cnt;
    }
}