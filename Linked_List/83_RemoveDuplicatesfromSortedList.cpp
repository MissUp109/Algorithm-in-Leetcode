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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL, *cur = head;
        while(cur){
            if(pre != NULL && cur->val == pre->val)
                pre->next = cur->next;
            else pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode *ret = sol.deleteDuplicates(head);
    while(ret){
        cout << ret->val << " -> ";
        ret = ret->next;
    }
    cout << endl;
}