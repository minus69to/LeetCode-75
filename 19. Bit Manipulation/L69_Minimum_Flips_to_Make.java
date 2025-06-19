class Solution {
    public int minFlips(int a, int b, int c) {
        int flip = 0;
        for (int i = 0; i < 32; i++) {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            int z = (c >> i) & 1;

            if (z == 0) {
                flip +=  (x + y);
            }
            else
            {
                if (x == 0 && y == 0) {
                    flip += 1;
                }
            }
        }

        return flip;
    }
}

public class L69_Minimum_Flips_to_Make {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.minFlips(2, 2, 4));
    }
}

// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75