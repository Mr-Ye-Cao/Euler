// Google problem 1 # solved with 26 mins

// g++ -Wall -Wextra -Wpedantic -std=c++11 -o test test.cpp
// ./test

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> get_Factors(int i){
        vector<int> facs;
        for(int f=1;f<i;f++){
            if(i%f==0){
                cout<<i<<" "<<f<<endl;
                facs.push_back(f);
            }
        }
        
        return facs;
    }
    
    bool divisorGame(int n) {
        // memo[i]: person has the decision to make with i left
        vector<bool> memo(1001,false);
        memo[1] = false;
        memo[2] = true;
        memo[3] = false;
        
        for(int i=4;i<=n;i++){
            // find all the factors of number i: f1, f2, f3, ...
            // check if memo[i] = memo[i-f1] || memo[i-f2] || ... 
            vector<int> facs=get_Factors(i);
            for(int j=0;j<facs.size();j++){
                memo[i] =  memo[i] || !memo[i-facs[j]];
            }
        }
        
        return memo[n];
    }
};

int main() {


    cout << "Hello, World!\n";

    vector<vector<int>> v;

    minimumTotal();

    return 0;
}