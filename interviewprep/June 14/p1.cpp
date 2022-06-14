// Google problem 1 # solved with 20 mins

// g++ -Wall -Wextra -Wpedantic -std=c++11 -o test test.cpp
// ./test

#include <iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        // (()())(())(()(()))
        // decompose
        // (()()) (()) (()(()))
    //   0 121210 1210 12123210
        // ()()() ()(())

        vector<int> v(s.length()+1, 0);
        
        for(int i=1;i<=s.length();i++){
            v[i] = v[i-1] + (s[i-1]=='(' ? 1 : -1);
        }

        vector<string> p;
        string pp="";
        for(int i=1;i<v.size();i++){
            if(v[i]==0){
                pp+=s[i-1];
                p.push_back(pp);
                pp="";
            }else{
                pp+=s[i-1];
            }
        }

        string result="";
        for(int i=0;i<p.size();i++){
            result+=p[i].substr(1,p[i].length()-2);
        }

        return result;
    }
};

int main() {


    cout << "Hello, World!\n";

    vector<vector<int>> v;

    minimumTotal();

    return 0;
}