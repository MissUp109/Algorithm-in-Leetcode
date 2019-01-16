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

//Sort a linked list in O(n log n) time using constant space complexity.
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        return mergeSort(head, head2);
    }

    ListNode* mergeSort(ListNode* list1, ListNode* list2){
        if(list1 && list1->next){
            ListNode *slow = list1, *fast = list1;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            ListNode* list1_2 = slow->next;
            slow->next = NULL;
            list1 = mergeSort(list1, list1_2);
        }

        if(list1 && list2->next){
            ListNode *slow = list2, *fast = list2;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            ListNode* list2_2 = slow->next;
            slow->next = NULL;
            list1 = mergeSort(list2, list2_2);
        }

        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val < list2->val){
            list1->next = list2;
            return list1;
        }
        else{
            list2->next = list1;
            return list1;
        }
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

    ListNode* ret = sol.sortList(node0);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }
    cout << endl;
}