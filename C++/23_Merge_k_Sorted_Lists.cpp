/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct myCmp {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }   
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myCmp> myQ;
        for(vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++) {
            if(*iter) {
                myQ.emplace(*iter);
            }
        }
        
        if(myQ.empty()) {
            return NULL;
        }
        
        ListNode* res = myQ.top();
        myQ.pop();
        if (res->next) {
            myQ.push(res->next);
        }

        ListNode* curr = res;            
        while (!myQ.empty()) {
            curr->next = myQ.top();
            myQ.pop();
            curr = curr->next;
            if (curr->next) {
                myQ.push(curr->next);
            }
        }
        
        return res;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if(length == 0) {
            return NULL;
        }
        int interval = 1;
        while(interval < length) {
            for(int i = 0; i < length - interval; i = i + interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return head->next;
    }
};