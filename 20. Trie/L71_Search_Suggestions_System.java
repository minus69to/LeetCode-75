import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public class TrieNode {
        TrieNode[] children = new TrieNode[26];
        List<String> suggestions = new ArrayList<>();
    }

    TrieNode root = new TrieNode();

    public void insert(String word) {
        TrieNode node = root;

        for (var ch : word.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];

            if (node.suggestions.size() < 3) {
                node.suggestions.add(word);
            }
        }
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);

        for (var product : products) {
            insert(product);
        }

        List<List<String>> answer = new ArrayList<>();
        TrieNode node = root;

        for (var ch : searchWord.toCharArray()) {
            int index = ch - 'a';

            if (node != null && node.children[index] != null) {
                node = node.children[index];
                answer.add(new ArrayList<>(node.suggestions));
            } else {
                node = null;
                answer.add(new ArrayList<>());
            }
        }

        return answer;
    }
}

public class L71_Search_Suggestions_System {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
        String searchWord = "mouse";

        List<List<String>> suggestions = solution.suggestedProducts(products, searchWord);

        for (List<String> suggestion : suggestions) {
            System.out.println(suggestion);
        }
    }
}
