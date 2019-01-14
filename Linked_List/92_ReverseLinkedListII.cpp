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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m < 1 || m >= n || !head) return head;
    	
    	int c = n - m;
    	ListNode *ret = new ListNode(0), *left = ret;
    	ret->next = head;
        while(m > 1){
        	left = left->next;
        	--m;
        }

        if(!left->next) return head;

        ListNode *pre = left->next, *cur = pre->next;
        while(cur && c > 0){
        	pre->next = cur->next;
        	cur->next = left->next;
        	left->next = cur;

        	cur = pre->next;
        	--c;
        }
        return ret->next;
    }
};
*/

class Solution {
public:
    void recurseAndReverse(ListNode* right, ListNode* &left, int m, int n, bool &stop) {
        if (n == 1) {
            return;
        }

        right = right->next;

        if (m > 1) left = left->next;

        recurseAndReverse(right, left, m - 1, n - 1, stop);

        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if (left == right || right->next == left) {
            stop = true;            
        }

        // Until the boolean stop is false, swap data between the two pointers
        if (!stop) {
        	cout << "left: " << left->val << ", right: " << right->val << endl;
            int t = left->val;
            left->val = right->val;
            right->val = t;

            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            left = left->next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *left = head; 
        bool stop = false;
        recurseAndReverse(head, left, m, n, stop);
        return head;
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode *ret = sol.reverseBetween(head, 2, 4);
    while(ret){
        cout << ret->val << " -> ";
        ret = ret->next;
    }
    cout << endl;
}