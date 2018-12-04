


/*
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head == nullptr) return nullptr;

    	ListNode* tmp1 = head; 
    	int count = 0;
    	while(tmp1->next != nullptr){
    		tmp1 = tmp1->next;
    		count++;
    	}
    	count++;

    	ListNode* tmp2 = head;
    	int sub = count - n;
    	if(sub == 0)
    		return head->next;
    	
    	while(--sub > 0)
    		tmp2 = tmp2->next;
    	ListNode *del = tmp2->next;

    	tmp2->next = del->next;
    	delete del;

    	return head;
    }

};

/*
// more beautiful: only one pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        if (slow->next == NULL){
            return NULL;
        }
        for (int i=0; i < n; i++){
            fast = fast->next;
        }
        if (fast == NULL){
            return head->next;
        }
        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
*/

int main(){
	Solution sol;
	ListNode* list = new ListNode(1);
	/*
	ListNode* tmp = list;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = new ListNode(5);
	*/

	ListNode* result = sol.removeNthFromEnd(list, 1);
	/*
	while(result->next != nullptr){
		cout << result->val << " ";
		result = result->next;
	}
	cout << result->val << endl;
	*/
	if(result == nullptr) cout << "nullptr" << endl;
	
}