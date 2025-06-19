class Solution {

    public int maxProfit(int[] prices, int fee) {
        int buy = -prices[0] - fee;
        int sell = 0;

        for (int i = 1; i < prices.length; i++) {
            int prevBuy = buy;
            buy = Math.max(buy, sell - prices[i] - fee);
            sell = Math.max(sell, prices[i] + prevBuy);
        }

        return sell;
    }
}

public class L65_Best_Time_Buy_Sell_Stock {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] prices = {1,3,2,8,4,9};
        System.out.println(solution.maxProfit(prices, 2));
    }
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75

// https://www.youtube.com/watch?v=DzH4kVcyuOI