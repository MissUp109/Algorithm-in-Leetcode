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

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ret = NULL, *tail = NULL;
        ListNode *pre = NULL, *cur = head;
        while(cur){
            if((!cur->next || cur->val != cur->next->val) && (!pre || cur->val != pre->val)){
                if(tail){
                    tail->next = cur;
                    tail = tail->next;
                }
                else{
                    tail = cur;
                    ret = tail;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        if(tail) tail->next = NULL;
        return ret;
    }
};
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode* p = head->next;
        
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } 
        else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = NULL;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    ListNode *ret = sol.deleteDuplicates(NULL);
    while(ret){
        cout << ret->val << " -> ";
        ret = ret->next;
    }
    cout << endl;
}