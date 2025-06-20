
class Solution {

    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }

        int a = 0;
        int b = 1;
        int c = 1;
        int d = 0;

        for(int i = 3; i <= n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        
        return d;
    }
}

public class L59_Nth_Tribonacci_Number {

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.tribonacci(37));
    }
}
