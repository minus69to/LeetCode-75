class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }

        int i_2 = nums[0];
        int i_1 = Math.max(nums[0], nums[1]);
        int i;

        for(int k = 2; k < nums.length; k++)
        {
            i = Math.max(i_1, nums[k] + i_2);
            i_2 = i_1;
            i_1 = i;
        }

        return i_1;
    }
}

public class L61_HouseRobber {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2,7,9,3,1};
        System.out.println(solution.rob(nums));
    }
}
