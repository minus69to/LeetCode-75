class Solution {

    public int longestCommonSubsequence(String text1, String text2) {
        int row = text1.length();
        int col = text2.length();
        int[][] dp = new int[row + 1][col + 1];

        for (int r = 0; r < row; r++) {
            dp[r][0] = 0;
        }

        for (int c = 0; c < col; c++) {
            dp[0][c] = 0;
        }

        for (int r = 1; r <= row; r++) {
            for (int c = 1; c <= col; c++) {
                if (text1.charAt(r - 1) == text2.charAt(c - 1)) {
                    dp[r][c] = dp[r - 1][c - 1] + 1;
                } else {
                    dp[r][c] = Math.max(dp[r - 1][c], dp[r][c - 1]);
                }
            }
        }

        return dp[row][col];
    }
}

public class L64_Longest_Common_Subsequence {

    public static void main(String[] args) {
        Solution solution = new Solution();
        String text1 = "abcde";
        String text2 = "ace";
        int result = solution.longestCommonSubsequence(text1, text2);
        System.out.println(result);
    }
}
