/*  Question 111
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

// Solution using level order traversal

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
    
    struct qitem{       // a structure to contain current node and depth at which the node is present
        TreeNode *node;
        int depth;
    };
    
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
            
        queue<qitem> q;  
        qitem qi= {root, 1};
        q.push(qi);
        while(q.empty()==false){
            qi= q.front();
            TreeNode *current= qi.node;
            int depth= qi.depth;
            
            if(!current->left && !current->right){
                return depth;
            }
            if(current->left){
                qi.node= current->left;
                qi.depth= depth+1;
                q.push(qi);
            }
            if(current->right){
                qi.node= current->right;
                qi.depth= depth+1;
                q.push(qi);
            }
            q.pop();
        }
        return 0;
    }
};