/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merge_list = NULL;
        
        if (lists.size() == 0)
            return merge_list;
        
        for (int a = 0; a < lists.size(); a++)
            merge_list = mergeTwoLists(merge_list,lists[a]);
        
        return merge_list;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* start = new ListNode(INT_MIN);
        ListNode* last = start;
        
        while (l1 && l2) {
            
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            }
            
            else {
                last->next = l2;
                l2 = l2->next;
            }
            
            last = last->next;
            
        }//while
        
        last->next = l1 != NULL ? l1 : l2;
        return start->next;
    }
};
