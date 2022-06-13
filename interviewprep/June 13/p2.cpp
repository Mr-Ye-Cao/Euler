// medium https://leetcode.com/problems/add-two-numbers/solution/

// g++ -Wall -Wextra -Wpedantic -std=c++11 -o test test.cpp
// ./test

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);;
        
        ListNode *cp1=l1, *cp2=l2, *cpr=result;

        int carry = 0;
        
        while(cp1!=nullptr || cp2!=nullptr){
            int x = (cp1 != nullptr) ? cp1->val : 0;
            int y = (cp2 != nullptr) ? cp2->val : 0;
            
            int sum = carry + x + y;
            carry = sum / 10;
            cpr->next = new ListNode(sum % 10);
            cpr = cpr->next;
            
            if(cp1!=nullptr){
                cp1 = cp1->next;
            }
            
            if(cp2!=nullptr){
                cp2 = cp2->next;
            }
        }

        if(carry>0){
            cpr->next=new ListNode(carry);
        }

        return result->next;
    }
};

int main() {
    return 0;
}