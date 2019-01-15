#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Acceleration
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Approach 1: Create a new head node (by Leah)
//Runtime: 12 ms with acceleration, faster than 100.00% of C++ online submissions
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        ListNode*nhead = new ListNode(0);
        nhead->next = head;

        int _count = 0;
        ListNode* pre = nhead;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        ListNode* preEnd; 
        while(1){
            if(_count == 0){
                ListNode* tmp = cur;
        		int count = 0;
        		while(tmp){ //to check if the number of current group is equal to k
        			tmp = tmp->next;
        			count++;
        		}
        		if(count < k) return nhead->next;
            
        		preEnd = pre; //Record the last node of one group
        		pre = cur;
        	}
        	else{ //swap
                cur->next = preEnd->next;
        		preEnd->next = cur;
        		pre->next = nxt;
        	}

        	if(nxt == NULL) break;
            cur = nxt;
        	nxt = nxt->next;
        	_count = (_count + 1 == k) ? 0 : (_count + 1);
        }
        return nhead->next;

    }
};


//Approach 2: recursive (by net friend)
//Runtime: 12 ms with acceleration, faster than 100.00% of C++ online submissions
/*
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr != NULL && count != k) { // find the k+1 node
            curr = curr->next;
            count++;
        }
        if (count == k) { // if k+1 node is found
            curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
            // head - head-pointer to direct part, 
            // curr - head-pointer to reversed part;
            while (count-- > 0) { // reverse current k-group: 
                ListNode* tmp = head->next; // tmp - next head in direct part
                head->next = curr; // preappending "direct" head to the reversed list 
                curr = head; // move head of reversed part to a new node
                head = tmp; // move "direct" head to the next node in direct part
            }
            head = curr;
        }
        return head;
    }

};
*/

int main(){
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    n5->next = n6;
	n4->next = n5; 
    n3->next = n4;
	n2->next = n3; 
    n1->next = n2;

	Solution sol;
	ListNode* test = sol.reverseKGroup(n1, 2);
	while(test != NULL){
		cout << test->val << " ";
		test = test->next;
	}
	cout <<  endl;
}