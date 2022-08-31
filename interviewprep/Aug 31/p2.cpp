/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compareTwoTree(TreeNode* root, TreeNode* subRoot){
            if((root == nullptr) || (subRoot == nullptr)){
                return (root == nullptr) && (subRoot == nullptr);
            }

            return root->val == subRoot->val &&
                    compareTwoTree(root->left, subRoot->left) && 
                    compareTwoTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }

        return  compareTwoTree(root, subRoot) || 
                isSubtree(root->left, subRoot) || 
                isSubtree(root->right, subRoot);
    }
};