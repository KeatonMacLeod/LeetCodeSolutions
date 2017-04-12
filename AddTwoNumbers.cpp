
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

				 if (currL1 == nullptr)
					 currL1Val = 0;
				 else
					 currL1Val = currL1->val;
				 if (currL2 == nullptr)
					 currL2Val = 0;
				 else
					 currL2Val = currL2->val;

				 int val = currL1Val + currL2Val;

				 if (carry)
					 val += 1;

				 carry = false;

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

				 if (newList == nullptr)
				 {
					 newList = new ListNode(val);
					 newListAdder = newList;
				 }

				 else
				 {
					 newListAdder->next = new ListNode(val);
					 newListAdder = newListAdder->next;
				 }

				 if (currL1 != nullptr)
					 currL1 = currL1->next;
				 if (currL2 != nullptr)
					 currL2 = currL2->next;
			 }

			 if (carry)
			 {
				 newListAdder->next = new ListNode(1);
			 }

			 return newList;
		 }
	 };
 };