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


//Approach 1: with <set>
#include <set>
class Solution {
public:
    ListNode *detectCycle(ListNode* head) {	
        set<ListNode*> nodeSet;
        while(head){
        	auto found = nodeSet.find(head);
        	if(found != nodeSet.end())
        		return *found;
        	nodeSet.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


//Approach 2: use slow/fast pointers
//ref: [https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description]
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {	
    	ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(entry != slow){
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
*/

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    node0->next = node1;
    node1->next = node0;
    node2->next = node3;
    node3->next = node1;
    node4->next = NULL;

    if(sol.detectCycle(node0)) 
        cout << sol.detectCycle(node0)->val << endl;
    else cout << "NULL" << endl;
}