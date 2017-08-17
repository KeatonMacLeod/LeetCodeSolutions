/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* newList = NULL;
        ListNode* last = NULL;
        
        while (l1 != NULL || l2 != NULL) {
            
            ListNode* newNode;
            
            if (l1 != NULL && l2 == NULL) {
                newNode = new ListNode(l1->val);
                l1 = l1->next;
            }
            
            else if (l1 == NULL && l2 != NULL) {
                newNode = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            else if (l1 != NULL && l2 != NULL) {
                int min = std::min(l1->val, l2->val);
                newNode = new ListNode(min);
                
                if (min == l1->val)
                    l1 = l1->next;
                else
                    l2 = l2->next;
            }
            
            if (newList == NULL) {
                newList = newNode;
                last = newNode;
            }
            
            else {
                last->next = newNode;
                last = last->next;
            }
            
        }//while
        
        return newList;
    }
};
