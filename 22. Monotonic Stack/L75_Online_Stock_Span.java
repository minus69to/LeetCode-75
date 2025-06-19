import java.util.Stack;

class StockSpanner {
    Stack<int[]> stack;

    public StockSpanner() {
        stack = new Stack<>();
    }
    
    public int next(int price) {
        int span = 1;

        while(!stack.empty() && price >= stack.peek()[0])
        {
            span += stack.pop()[1];
        }
        stack.push(new int[]{price, span});

        return span;
    }
}

public class L75_Online_Stock_Span {
    public static void main(String[] args) {
        StockSpanner spanner = new StockSpanner();
        int[] prices = {100, 80, 60, 70, 60, 75, 85};

        for (var price : prices) {
            int span = spanner.next(price);
            System.out.print(span + " ");
        }
        // Output: 1 1 1 2 1 4 6
    }
}

// https://leetcode.com/problems/online-stock-span/description/?envType=study-plan-v2&envId=leetcode-75