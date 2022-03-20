public class Solution {
    private int GetRightMostSetBitPosition(int num) {
        for(int i = 0; i < 32; ++i) {
            int l = 1 << i;
            if((num & l) == l) return i;
        }
        return -1;
    }
    public int[] SingleNumber(int[] nums) {
        int xor = 0;
        int[] res = new int[2];
        for(int i = 0; i < nums.Length; ++i) xor ^= nums[i];
        int l = 1 << GetRightMostSetBitPosition(xor);
        for(int i = 0; i < nums.Length; ++i) {
            if((nums[i] & l) == 0) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        return res;
    }
}

/*
[1, 2, 1, 3, 2, 5]

1 = 001
2 = 010
1 = 001
3 = 011
2 = 010
5 = 101

Here, XOR of all number means XOR of 3 and 5.
011 ^ 101 = 110 (1 means mismatch in that particular position of the two numbers)

Now, get the position of right most set bit and divide nums array into two group having 1 or 0 in that position.
*/