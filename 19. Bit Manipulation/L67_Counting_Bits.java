class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n+1];

        for (int i = 0; i <= n; i++) {
            if (i % 2 == 0) {
                ans[i] = ans[i/2];
            }
            else
            {
                ans[i] = ans[i/2] + 1;
            }
        }

        return ans;
    }
}

public class L67_Counting_Bits {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] ans = solution.countBits(16);

        for(var val : ans) {
            System.out.print(val + " ");
        }
    }
}
