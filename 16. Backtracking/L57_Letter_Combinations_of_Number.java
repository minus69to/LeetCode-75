
import java.util.*;

class Solution {

    private static final Map<Character, String> phoneMap = new HashMap<>() {
        {
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }
    };

    private void backtrack(List<String> result, String digits, int index, String combination) {
        if (index == digits.length()) {
            result.add(combination);
            return;
        }

        char digit = digits.charAt(index);
        String letters = phoneMap.get(digit);

        for (char letter : letters.toCharArray()) {
            String newCombination = combination + letter;
            backtrack(result, digits, index + 1, newCombination);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();

        if (digits == null || digits.length() == 0) {
            return result;
        }

        backtrack(result, digits, 0, "");

        return result;
    }
}

public class L57_Letter_Combinations_of_Number {

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.letterCombinations("23"));
    }
}