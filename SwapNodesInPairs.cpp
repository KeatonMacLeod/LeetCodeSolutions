/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (!head || !head->next)
            return head;
        
        ListNode* prev = NULL;  ListNode* curr = NULL;
        ListNode* next = NULL;  ListNode* swap = NULL;
        
        prev = head;
        curr = head->next;
        head = curr;
        
        while (prev && curr) {
            next = curr->next;
            if (swap) swap->next = curr;
            curr->next = prev;
            swap = prev;
            prev->next = NULL;
            prev = next;
            if (next) curr = next->next;
        }
        
        if (!curr && swap) swap->next = prev;
        
        return head;
    }
};
