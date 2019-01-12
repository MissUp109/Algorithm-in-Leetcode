#include <iostream>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == NULL) return head;
    	int len = getLength(head);
    	k = k % len;
    	if(k == 0) return head;

    	int c = len - k;
    	ListNode* toChange = head;
    	while(c > 1){
    		toChange = toChange->next;
    		--c;
    	}
    	ListNode* tmp1 = toChange->next;
    	toChange->next = NULL;
    	toChange = tmp1;
    	
    	ListNode* tmp2 = head;
    	head = toChange;
    	while(toChange->next != NULL)
    		toChange = toChange->next;
    	toChange->next = tmp2;
    	return head;
    }

    int getLength(ListNode* head){
    	int len = 0;
    	while(head != NULL){
    		++len;
    		head = head->next;
    	}
    	return len;
    }
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(0);
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;

	ListNode *ret = sol.rotateRight(head, 4);
	while(ret != NULL){
		cout << ret->val << " -> ";
		ret = ret->next;
	}
	cout << endl;
}