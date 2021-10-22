//  https://leetcode.com/problems/delete-node-in-a-bst/

//  Delete Node in a BST

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
        
        TreeNode* findmax(TreeNode* root)
        {
            if(!root->left && !root->right)
                return root;
            if(!root->right)
                return root;
            root=findmax(root->right);
            return root;
        }
        TreeNode* findmin(TreeNode* root)
        {
            if(!root->left && !root->right)
                return root;
            if(!root->left)
                return root;
            root=findmin(root->left);
            return root;
        }
        TreeNode* deleteNode(TreeNode* root, int key)
        {
            if(!root)
                return NULL;
            if(key<root->val)
            {
                root->left=deleteNode(root->left,key);
            }
            else if(key>root->val)
            {
                root->right=deleteNode(root->right,key);
            }
            else if(root->val==key)
            {
                if(!root->left && !root->right)
                {
                    TreeNode* temp=root;
                    root=NULL;
                    delete temp;
                    return root;
                }
                else if(root->left)
                {
                    TreeNode* temp=findmax(root->left);
                    root->val=temp->val;
                    root->left=deleteNode(root->left,root->val);
                }
                else
                {
                    TreeNode* temp=findmin(root->right);
                    root->val=temp->val;
                    root->right=deleteNode(root->right,root->val);
                }
            }            
            return root;
        }       
 };
