class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
}

public class L63_Unique_Paths {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.uniquePaths(5, 6));
    }
}

// https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=leetcode-75