class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        StringBuilder str = new StringBuilder();
        for (String s : sentence) {
            s = s + " ";
            str.append(s);
        }
        
        int start = 0;
        for (int i = 0; i < rows; i++) {
            start = start + cols;
            if (str.charAt(start % str.length()) == ' ') {
                start++;
            } else {
                while (start > 0 && str.charAt((start-1) % str.length())  != ' ') {
                    start--;
                }
            }
        }
        return start / str.length();
    }
}