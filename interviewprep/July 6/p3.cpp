class Solution {
public:
    TreeNode * help(TreeNode *root, set<int>&st, vector<TreeNode *>&ans){
        if(!root){
            return root;
        }
        root->left = help(root->left, st, ans);
        root->right = help(root->right, st, ans);
        if(st.find(root->val)!=st.end()){
            TreeNode *rr = root->right;
            TreeNode *ll = root->left;
            if(rr){
                ans.push_back(rr);
            }
            if(ll){
                ans.push_back(ll);
            }
            st.erase(root->val);
            delete root;
            return NULL;
        }
        return root;
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>st;
        for(int i:to_delete){
            st.insert(i);
        }
        vector<TreeNode *>ans;
        TreeNode *tmp = root;
        root = help(root, st, ans);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};