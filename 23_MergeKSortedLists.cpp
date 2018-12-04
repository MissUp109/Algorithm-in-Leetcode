#include <iostream>
#include <string>
#include <vector>
#include <climits>

#include <queue>
#include <functional>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Runtime: 180 ms, faster than 17.40% of C++ online submissions
//Time Complexity: O(m * n)
//Space Complexity: O(m * n)
/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size() == 0) return NULL;
    	if(lists.size() == 1) return lists[0];

    	ListNode* result = new ListNode(0);
    	ListNode* tmp = result;
        int count = 0;
        for(int i = 0; i < lists.size(); ++i)
        	if(lists[i] != NULL) ++count;
        
        while(count > 0){
        	int minVal = INT_MAX, minIndex = -1;
        	for(int i = 0; i < lists.size(); ++i){
        		if(lists[i] == NULL) continue;
        		if(lists[i]->val < minVal){
        			minVal = lists[i]->val;
        			minIndex = i;
        		}
        	}
        	
        	ListNode* newNode = new ListNode(minVal);
        	tmp->next = newNode;
        	tmp = tmp->next;

        	lists[minIndex] = lists[minIndex]->next;
        	if(lists[minIndex] == NULL){
        		--count;
        		lists.erase(lists.begin() + minIndex);
        	}
        }
        return result->next;
    }
};
*/


//Approach 2: Priority Queue
//Runtime: 16 ms, faster than 99.72% of C++ online submissions
//Time complexity : O(Nlogk)where k is the number of linked lists, N is total number
//Space complexity: O(n)
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) return NULL;
		if(lists.size() == 1) return lists[0];

		priority_queue<int, vector<int>, greater<int> > mergeQueue;

		for(int i = 0; i < lists.size(); ++i){
			while(lists[i] != NULL){
				mergeQueue.push(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}

		ListNode *result = new ListNode(0);
		ListNode *ptr = result;
		while(!mergeQueue.empty()){
			ListNode* newNode = new ListNode(mergeQueue.top());
			ptr->next = newNode;
			ptr = ptr->next;
			mergeQueue.pop();
		}
		return result->next;
	}
};


int main(){
	Solution sol;
	vector<ListNode*> lists;

	ListNode* n11 = new ListNode(1);
	ListNode* n12 = new ListNode(4);
	ListNode* n13 = new ListNode(5);
	n12->next = n13; n11->next = n12;
	lists.push_back(n11);

	ListNode* n21 = new ListNode(1);
	ListNode* n22 = new ListNode(3);
	ListNode* n23 = new ListNode(4);
	n22->next = n23; n21->next = n22;
	lists.push_back(n21);

	ListNode* n31 = new ListNode(2);
	ListNode* n32 = new ListNode(6);
	n31->next = n32;
	lists.push_back(n31);

	ListNode *test = sol.mergeKLists(lists);
	while(test != NULL){
		cout << test->val << " ";
		test = test->next;
	}
	cout <<  endl;
}