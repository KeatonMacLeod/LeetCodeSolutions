//Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

 class AddTwoNumbers {
 public:
	 class Solution {
	 public:
		 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			 ListNode* newList = nullptr;
			 ListNode* newListAdder = nullptr;
			 ListNode* currL1 = l1;
			 ListNode* currL2 = l2;
			 bool carry = false;
			 int currL1Val = 0;
			 int currL2Val = 0;

			 while (currL1 != nullptr || currL2 != nullptr)
			 {
				 //Get proper values for each linked list.
				 if (currL1 == nullptr)
					 currL1Val = 0;
				 else
					 currL1Val = currL1->val;
				 if (currL2 == nullptr)
					 currL2Val = 0;
				 else
					 currL2Val = currL2->val;

				 int val = currL1Val + currL2Val;

				 //Check if there was a carry-over from the previous addition.
				 if (carry)
					 val += 1;

				 carry = false;

				 //Set values and flags depending on the newly computed value.
				 if (val >= 10)
				 {
					 carry = true;
					 if (val != 10)
					 {
						 val = val % 10;
					 }
					 else
					 {
						 val = 0;
					 }
				 }

				 //If this is the first node, point the whole newList to it.
				 if (newList == nullptr)
				 {
					 newList = new ListNode(val);
					 newListAdder = newList;
				 }

				 //Otherwise, get our newListAdder to append additional listNodes.
				 else
				 {
					 newListAdder->next = new ListNode(val);
					 newListAdder = newListAdder->next;
				 }

				 //Advance our pointers in our linked lists.
				 if (currL1 != nullptr)
					 currL1 = currL1->next;
				 if (currL2 != nullptr)
					 currL2 = currL2->next;
			 }

			 //If there was a carry in the last addition of the loop, append the carried "1".
			 if (carry)
			 {
				 newListAdder->next = new ListNode(1);
			 }

			 return newList;
		 }
	 };
 };