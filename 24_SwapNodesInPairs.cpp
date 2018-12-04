#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL || head->next == NULL) return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;

        p1->next = p3;
        p2->next = p1;
        head = p2;

        while(p3 && p->next){
        	ListNode* tmp = p1;
        	p1 = p1->next;
        	p2 = p1->next;
        	p3 = p2->next;

        	p1->next = p3;
        	p2->next = p1;
        	tmp->next = p2;
        }
        return head;
    }
};

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	//ListNode* n3 = new ListNode(3);
	//ListNode* n4 = new ListNode(4);
	//n3->next = n4;
	//n2->next = n3;
	n1->next = n2;

	Solution sol;
	ListNode* sp = sol.swapPairs(n1);

	while(sp){
		cout << sp->val << " ";
		sp = sp->next;
	}
	cout << endl;

}