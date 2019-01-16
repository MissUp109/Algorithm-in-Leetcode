#include <iostream>
using namespace std;

/* This file contains 2 approaches.*/

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

//Runtime: 16 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next) return head;

        ListNode* newHead = new ListNode(0);
        newHead->next = head;

        ListNode* tail = head; 
        ListNode* cur = head->next;

        ListNode *tmp, *pivot;
        while(cur){
            if(tail->val > cur->val){
                tmp = cur->next;
                pivot = newHead;
                while(pivot->next && cur->val > pivot->next->val)
                    pivot = pivot->next;

                tail->next = cur->next;
                cur->next = pivot->next;
                pivot->next = cur;

                cur = tmp; //cur = cur->next
            }
            else{
                tail = cur;
                cur = cur->next;
            }
        	

        }
        return newHead->next;
    }
};

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(-1);
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(0);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode* ret = sol.insertionSortList(node0);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }
    cout << endl;
}