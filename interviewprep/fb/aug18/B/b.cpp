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
class BSTIterator {
public:
    int pos;
    vector<int> content;
    
    void traverse(TreeNode* root){
        if(root==nullptr)
            return;
        
        content.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        content.push_back(-1);        
        traverse(root);
        std::sort(content.begin(),content.end());
        pos=0;
    }
    
    int next() {
        pos++;
        return content[pos];
    }
    
    bool hasNext() {
        return pos<content.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */