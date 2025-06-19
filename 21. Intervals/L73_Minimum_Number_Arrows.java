
import java.util.Arrays;

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int lastPos = points[0][1];
        int arrows = 1;

        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > lastPos) {
                arrows += 1;
                lastPos = points[i][1];
            }
        }

        return arrows;
    }
}

public class L73_Minimum_Number_Arrows {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] points = {{10,16},{2,8},{1,6},{7,12}};
        System.out.println(solution.findMinArrowShots(points));
    }
}

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75