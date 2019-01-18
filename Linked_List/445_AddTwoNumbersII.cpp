#include <iostream>
#include <vector>
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

//Approach 1
//Runtime: 36 ms, faster than 96.71% of C++ online submissions
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		if(!l1) return l2;
		if(!l2) return l1;

		vector<int> v1, v2;
		while(l1){
			v1.push_back(l1->val);
			l1 = l1->next;
		}
		while(l2){
			v2.push_back(l2->val);
			l2 = l2->next;
		}

		ListNode *head = new ListNode(0);
		int num = 0, sum = 0;
		int i = v1.size() - 1, j = v2.size() - 1;
		cout << i << " " << j << endl; 
		while(i >= 0 || j >= 0 || num > 0){
			if(i < 0 && j >= 0) sum = v2[j] + num;
			else if(i >= 0 && j < 0) sum = v1[i] + num;
			else if(i < 0 && j < 0) sum = num;
			else sum = v1[i] + v2[j] + num;

			num = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			newNode->next = head->next;
			head->next = newNode;
			--i; --j;
		}
		return head->next;
	}
};
*/

//Approach 2
//Runtime: 28 ms, faster than 99.81% of C++ online submissions
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        while( curr1 ){ curr1=curr1->next; n1++; }
        while( curr2 ){ curr2=curr2->next; n2++; } 
        curr1 = l1; curr2 = l2;
        while( n1 > 0 && n2 > 0){
            int sum = 0;
            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
            if( n2 > n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
            res = addToFront( sum, res );
        }
        curr1 = res; res = NULL;
        while( curr1 ){
            curr1->val += carry; carry = curr1->val/10;
            res = addToFront( curr1->val%10, res );
            curr2 = curr1; 
            curr1 = curr1->next;
            delete curr2;
        }
        if( carry ) res = addToFront( 1, res );
        return res;
    }
    ListNode* addToFront( int val, ListNode* head ){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
};

//Approach 3
//https://leetcode.com/problems/add-two-numbers-ii/discuss/206817/Java%3A-recursion-solutionTime-%3A-O(n)-Space%3A-O(1)-no-reverse-no-stack
/*
[3,9,9,9,9,9,9,9,9,9]
[7]

[0]
[0]
*/

int main(){
    Solution sol;
    ListNode *node0 = new ListNode(7);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);

    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    ListNode* ret = sol.addTwoNumbers(node0, node4);

    while(ret){
    	cout << ret->val << "->";
    	ret = ret->next;
    }

    cout << endl;
}