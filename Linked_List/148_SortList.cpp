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

//Sort a linked list in O(n log n) time using constant space complexity.
//Runtime: 40 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = findMid(head);
        ListNode* head2 = slow->next;
        slow->next = NULL;
        return mergeSort(head, head2);
    }

    //Find the middle node of list
    ListNode* findMid(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //Merge two 'ordered' lists 
    ListNode* Merge(ListNode* list1, ListNode* list2){
        ListNode *head = new ListNode(0), *pivot = head; //ListNode *head = NULL, *pivot = NULL; 
        while(list1 && list2){
            if(!list1 || (list2 && list2->val <= list1->val)){
                /*
                if(!pivot && !head){
                    head = list2; pivot = head;
                } else {*/
                    pivot->next = list2;
                    pivot = pivot->next;
                //}
                list2 = list2->next;
            }
            else if(!list2 || (list1 && list1->val < list2->val)){
                /*
                if(!pivot && !head){
                    head = list1; pivot = head;
                } else {*/
                    pivot->next = list1;
                    pivot = pivot->next;
                //}
                list1 = list1->next;
            }
        }
        if(list1) pivot->next = list1;
        else if(list2) pivot->next = list2;

        return head->next;
    }

    //Backtracking merge
    ListNode* mergeSort(ListNode* list1, ListNode* list2){
        if(list1 && list1->next){
            ListNode* slow = findMid(list1);
            ListNode* list1_2 = slow->next;
            slow->next = NULL;
            list1 = mergeSort(list1, list1_2);
        }

        if(list2 && list2->next){
            ListNode* slow = findMid(list2);
            ListNode* list2_2 = slow->next;
            slow->next = NULL;
            list2 = mergeSort(list2, list2_2);
        }

        return Merge(list1, list2);
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
    //ListNode* ret = sol.Merge(NULL, node1);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }

    cout << endl;
}