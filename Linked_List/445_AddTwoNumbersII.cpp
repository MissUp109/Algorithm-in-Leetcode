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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

	}

    ListNode* backtrack(ListNode* l1, ListNode* l2) {
        if(l1->next) addTwoNumbers(l1->next, l2);
        if(l2->next) addTwoNumbers(l1, l2->next);

    }
};

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(7);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);

    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    ListNode* ret = sol.addTwoNumbers(node0, node4);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }

    cout << endl;
}