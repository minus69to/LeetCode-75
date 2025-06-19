class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length == 2) {
            return Math.min(cost[0], cost[1]);
        }

        int i_2 = cost[0];
        int i_1 = cost[1];
        int i = 0;

        for(int current = 2; current < cost.length; current++)
        {
            i = cost[current] + Math.min(i_1, i_2);
            i_2 = i_1;
            i_1 = i;
        }

        return Math.min(i_1, i_2);
    }
}

public class L60_Min_Cost_Climbing_Stairs {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

        System.out.println(solution.minCostClimbingStairs(cost));
    }
}