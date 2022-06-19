class Solution {
public:
    void reverseString(vector<char>& s) {
        // ["h","e","l","l","o"]
        // ["o","l","l","e","h"]
        //   ->              <-
        for(int i=0;i<s.size()/2;i++){
            char temp=s[i];
            s[i]=s[s.size()-i-1];
            s[s.size()-i-1]=temp;
        }

    }
};