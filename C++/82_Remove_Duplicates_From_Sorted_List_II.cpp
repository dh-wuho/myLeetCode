/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr) {
            while(curr && curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }
            if(prev->next != curr) {
                prev->next = curr->next;
            }
            else {
                prev = curr;
            }
            
            curr = curr->next;
        }
        
        return dummy->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        if(head->val == head->next->val) {
            while(head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }
        else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};