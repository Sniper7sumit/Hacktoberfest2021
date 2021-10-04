/*
243. Shortest Word Distance
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1

Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Companies: Amazon, Google, LinkedIn, Microsoft, Oracle, Paypal and Uber
*/

/*
Algorithm
It is enough to traverse the array once, initialize the two variables p1, p2 to -1, and then traverse the array.
When word 1 is encountered, its position is stored in p1, and if word 2 is encountered, its position is stored in p2. If p1, p2 are not -1 anymore, then update the result.
*/ 

//Code:

public class Shortest_Word_Distance {

    public static void main(String[] args) {
        Shortest_Word_Distance out = new Shortest_Word_Distance();
        Solution s = out.new Solution();

        System.out.println(s.shortestDistance(new String[]{"practice", "makes", "perfect", "coding", "makes"}, "makes", "coding"));
    }

    public class Solution {
        public int shortestDistance(String[] words, String word1, String word2) {
            int posA = -1;
            int posB = -1;
            int minDistance = Integer.MAX_VALUE;

            for (int i = 0; i < words.length; i++) {
                if (words[i].equals(word1)) {
                    posA = i;
                }

                if (words[i].equals(word2)) {
                    posB = i;
                }

                if (posA != -1 && posB != -1) { // will be run every time, after 1st pair is found
                    minDistance = Math.min(minDistance, Math.abs(posA - posB));
                }
            }

            return minDistance;
        }
    }
}