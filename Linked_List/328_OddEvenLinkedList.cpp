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

//Runtime: 12 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if(!head || !head->next || !head->next->next) return head;
    	ListNode *even = head->next, *tail = head, *tmp = NULL;
    	while(even && even->next){
    		//sort	
    		tmp = even->next->next;
    		even->next->next = tail->next;
    		tail->next = even->next;
    		even->next = tmp;
    		//update
    		even = tmp;
    		tail = tail->next;
    	}
        return head;
    }
};

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(-1);
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(0);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode* ret = sol.oddEvenList(node0);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }

    cout << endl;
}