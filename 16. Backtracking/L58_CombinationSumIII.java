import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), k, n, 1);

        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> current, int k, int remaining, int start) {
        if (current.size() == k) {
            if (remaining == 0) {
                result.add(new ArrayList<>(current));
            }
            return;
        }

        for(int i = start; i <= 9; i++) {
            current.add(i);
            backtrack(result, current, k, remaining-i, i+1);
            current.remove(current.size()-1);
        }
    }
}

public class L58_CombinationSumIII {
    public static void main(String[] args) {
        Solution solution = new Solution();
        List<List<Integer>> result = solution.combinationSum3(3, 9);
        System.out.println(result);
    }
}
