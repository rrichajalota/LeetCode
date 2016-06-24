/*  Question 111
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

// Solution using depth first traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
    
        if(!root)
            return 0;

        int lheight=minDepth(root->left);
        int rheight=minDepth(root->right);

        if(!lheight && !rheight){
            return 1;
        }

        if(lheight && !rheight)
            return 1+lheight;

        if(!lheight && rheight)
            return 1+rheight;

        else
            return 1+min(lheight, rheight);
        
    }
};