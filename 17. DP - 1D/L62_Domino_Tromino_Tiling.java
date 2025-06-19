class Solution {
    public int numTilings(int n) {
        int MOD = 1_000_000_007;

        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 5;
        }

        int i_1 = 5;
        int i_2 = 2;
        int i_3 = 1;
        int i;

        for (int k = 4; k <= n; k++) {
            i = (2 * i_1 % MOD + i_3) % MOD;

            i_3 = i_2;
            i_2 = i_1;
            i_1 = i;
        }

        return i_1;
    }
}

public class L62_Domino_Tromino_Tiling {

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numTilings(8));
    }
}

// https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=leetcode-75