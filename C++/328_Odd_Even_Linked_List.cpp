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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
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
    ListNode* oddEvenList(ListNode* head) {     
        if(head == NULL) {
            return head;
        }
        
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur && cur->next) {
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        
        return head;
    }
};