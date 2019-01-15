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

//Approach 1: backtracking
/*
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *left = head, *right = head;
        bool flag = true;
        recursion(left, right, flag);
    }

    void recursion(ListNode* &left, ListNode* right, bool &flag){
    	if(!right) return;

    	recursion(left, right->next, flag);

    	if(flag && (left->next == right || left == right)){
    		//cout << "final....." << endl;
    		//cout << "left: " << left->val << ", right: " << right->val << endl;
    		right->next = NULL;
    		flag = false;
    	}

    	if(flag){
    		//cout << "left: " << left->val << ", right: " << right->val << endl;
    		ListNode *tmp = left->next;
    		left->next = right;
    		right->next = tmp;	
    		left = tmp;//update left	
    	}
    }
};
*/

//Approach 2: vector
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> temp;
        while(head) {
            temp.push_back(head);
            head = head->next;
        }
        int i = 0, j = temp.size()-1;
        while(i <= j) {
            temp[i]->next = temp[j];
            temp[j]->next = i+1 <= j-1 ? temp[i+1] : nullptr;
            ++i; --j;
        }
    }
};

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node4->next = NULL;

    sol.reorderList(node0);

    while(node0){
    	cout << node0->val << "->";
    	node0 = node0->next;
    }
    cout << endl;
}