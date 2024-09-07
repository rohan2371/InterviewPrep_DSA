/*
Leetcode link : https://leetcode.com/problems/linked-list-in-binary-tree/description/
*/

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(root == NULL) // element is not found that reason reached root at null position
            return false;
        return check(head,root) || // first check element is matching with head element
                isSubPath(head,root->left) ||
                isSubPath(head,root->right);
    }
    bool check(ListNode* head, TreeNode* root)
    {
        if(head == NULL)// if head is NULL that means all elements are matching
            return true;
        if(root == NULL) // if root is NULL that means path is not matching
            return false;
        
        if(head->val != root->val) // if head is not matching value then it means that path is not matching
            return false;

        return check(head->next,root->left) || check(head->next,root->right);
    }
};