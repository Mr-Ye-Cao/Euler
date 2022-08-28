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
    map<TreeNode*, int> heightmap;

    TreeNode *rightRotate(TreeNode *y){
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;
     
        // Perform rotation
        x->right = y;
        y->left = T2;
     
        // Update heights
        heightmap[x] = max(heightmap[x->left], heightmap[x->right]) + 1;
        heightmap[y] = max(heightmap[y->left], heightmap[y->right]) + 1;
     
        // Return new root
        return x;
    }

    TreeNode *leftRotate(TreeNode *x){
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;
     
        // Perform rotation
        y->left = x;
        x->right = T2;
     
        // Update heights
        heightmap[x] = max(heightmap[x->left], heightmap[x->right]) + 1;
        heightmap[y] = max(heightmap[y->left], heightmap[y->right]) + 1;
     
        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(TreeNode* N)
    {
        if (N == nullptr)
            return 0;
        return heightmap[N->left] - heightmap[N->right];
    }

    TreeNode* insert(TreeNode* node, int val){
        /* 1. Perform the normal BST insertion */
        if (node == nullptr){
            return new TreeNode(val);
        }

        if (val < node->val)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        /* 2. Update height of this ancestor node */
        heightmap[node] = 1 + max(heightmap[node->left], heightmap[node->right]);


        /* 3. Get the balance factor of this ancestor
              node to check whether this node became
              unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases
 
        // Left Left Case
        if (balance > 1 && val < node->left->val){
            return rightRotate(node);
        }
     
        // Right Right Case
        if (balance < -1 && val > node->right->val){
            return leftRotate(node);
        }
     
        // Left Right Case
        if (balance > 1 && val > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
     
        // Right Left Case
        if (balance < -1 && val < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    TreeNode* constructAVLTree(const vector<int>& elements){
        TreeNode* resultRoot = nullptr;
        for(int e: elements){
            resultRoot = insert(resultRoot, e);
        }

        return resultRoot;
    }

    void traverseTree(vector<int>& elements, TreeNode* root){
        if(root == nullptr)
            return;

        elements.push_back(root->val);
        traverseTree(elements, root->left);
        traverseTree(elements, root->right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> elements;
        traverseTree(elements, root);

        return constructAVLTree(elements);
    }
};

class Solution {
public:
    vector<int>i;

    void traverseTree(TreeNode* root){
        if(! root)
            return;

        traverseTree(root->left);
        i.push_back(root->val);
        traverseTree(root->right);
    }

    //once you get the inorder traversal ..generate the bst out of it
    TreeNode* build(int s,int e)
    {
        //if s crosses e then return NULL
        if(s>e)
            return NULL;
        //the root node will be of the middle value in inorder traversal
        int mid=s+(e-s)/2;
        //assign the roor's value
        TreeNode* root=new TreeNode(i[mid]);
        //the elements on left of root will be smaller hence the array which will form the left subtree will be from s to mid-1
        root->left=build(s,mid-1);
        //for right subtree we want elements greater than mid .. hence the array will be between mid+1 and e
        root->right=build(mid+1,e);
        // once the root is formed return it 
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        traverseTree(root);

        return build(0,i.size()-1);
    }
};