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
#include <unordered_map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {	
        unordered_map<ListNode*, int> nodeMap;

        int i = 0;
        ListNode* ret = head;
        while(head){
        	auto found = nodeMap.find(head);
        	if(found != nodeMap.end()){
        		cout << "tail connects to node index " << found->second << endl;
        		return ret;
        	}
        	nodeMap[head] = i++;
        	head = head->next;
        }

        cout << "no cycle" << endl;
        return ret;
    }
};
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {	
    	if(!head || !head->next || !head->next->next){
    		cout << "no cycle" << endl;
    		return head;
    	}
    	ListNode *slow = head->next, *fast = head->next->next;
    	int idx = 1;
    	while(slow->next && fast->next->next){
    		if(slow == fast){
    			cout << "tail connects to node index " << idx << endl;
    			return head;
    		}
    		slow = slow->next;
    		fast = fast->next->next;
    		++idx;
    	}

    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    //ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    //node4->next = node2;

    sol.detectCycle(head);
}