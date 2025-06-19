import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length <= 1) {
            return 0;
        }

        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int end = intervals[0][1];
        int removals = 0;

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) {
                removals += 1;
            } else {
                end = intervals[i][1];
            }
        }

        return removals;
    }
}

public class L72_Non_overlapping_Intervals {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] intervals = {{1, 5}, {2, 3}, {3, 4}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8, 10}};
        System.out.println(solution.eraseOverlapIntervals(intervals));
    }
}

// https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75