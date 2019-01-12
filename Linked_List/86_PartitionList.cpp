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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *pre = NULL, *cur = head, *after = NULL;
        ListNode *tail = new ListNode(-1); 
        tail->next = head; head = tail;

        while(cur){
            if(cur->val < x){
                //cout << "cur: " << cur->val << " < " << x << endl;
                after = cur->next;
                if(tail->next != cur){
                    if(pre) pre->next = after;
                    cur->next = tail->next;
                    tail->next = cur;
                }
                tail = tail->next;
                cur = after;
            }
            else{
                //cout << "cur: " << cur->val << " > " << x << endl;
                pre = cur;
                cur = cur->next;
            }
        }
        return head->next;
    }
};
*/
/*
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *ret = new ListNode(0), *tail = ret;
        ListNode *tmp = new ListNode(0);
        tmp->next = head; head = tmp;

        ListNode *tmpnxt;
        while(tmp && tmp->next){
            tmpnxt = tmp->next;
            if(tmpnxt->val < x){
                //cout << " < " << x << endl;
                tmp->next = tmpnxt->next;
                
                tmpnxt->next = NULL;
                tail->next = tmpnxt;
                tail = tail->next;
            }
            else tmp = tmp->next;
        }
        tail->next = head->next;
        return ret->next;
    }
};*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;

        ListNode *ret;
        if(head->val < x){
            head->next = partition;
            return head;
        }
        else{
            ret = partition(head->next, x);
            ret->next = head;
            return ret;
        }

    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(5);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    ListNode *ret = sol.partition(head, 3);
    
    while(ret){
        cout << ret->val << " -> ";
        ret = ret->next;
    }
    cout << endl;
}