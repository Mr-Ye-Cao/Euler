class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string encode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> en;

        for(string word: words){
            string worden = "";
            for(char c: word){
                worden += encode[c - 'a'];
            }
            en.insert(worden);
        }

        return en.size();

    }
};