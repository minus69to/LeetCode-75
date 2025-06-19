class Trie {

    class TrieNode {

        TrieNode[] children;
        boolean isEndofWord;

        TrieNode() {
            children = new TrieNode[26];
            isEndofWord = false;
        }
    }

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;

        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isEndofWord = true;
    }

    public boolean search(String word) {
        TrieNode node = root;

        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                return false;
            }
            node = node.children[index];
        }
        return node.isEndofWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char ch : prefix.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                return false;
            }
            node = node.children[index];
        }

        return true;
    }
}

public class L70_Implement_Trie {
    public static void main(String[] args) {
        Trie trie = new Trie();

        trie.insert("apple");
        System.out.println(trie.search("apple"));    // true
        System.out.println(trie.search("app"));      // false
        System.out.println(trie.startsWith("app"));  // true

        trie.insert("app");
        System.out.println(trie.search("app"));      // true
        System.out.println(trie.search("apple"));    // true
        System.out.println(trie.startsWith("app"));  // true

        trie.insert("banana");
        System.out.println(trie.search("banana"));   // true
        System.out.println(trie.search("ban"));      // false
        System.out.println(trie.startsWith("ban"));  // true

        System.out.println(trie.startsWith(""));     // true

        System.out.println(trie.search("grape"));    // false
    }
}

// https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=leetcode-75