/***                                                *
 * 1. method                                        *                              
 * Time complexity: O(n)                        *
 * Space complexity: O(logn)                         ***/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int listLength = 0;
        ListNode* curr = head;
        while(curr) {
            listLength++;
            curr = curr->next;
        }
        
        return generateBST(head, 0, listLength - 1);
    }
    
    TreeNode* generateBST(ListNode*& currList, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int mid = start + (end - start) / 2;
        
        TreeNode* left = generateBST(currList, start, mid - 1);
        TreeNode* curr = new TreeNode(currList->val);
        currList = currList->next;
        curr->left = left;
        curr->right = generateBST(currList, mid + 1, end);
        
        return curr;
    }
};