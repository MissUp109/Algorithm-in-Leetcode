#include <iostream>
#include <string>
#include <vector>
#include <climits>

#include <queue>
#include <functional>

#include <algorithm>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//Approach 1: Compare one by one
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

//Approach 2: Merge with Divide And Conquer
//Runtime: 24 ms, faster than 56.93% of C++ online submissions
//Time Complexity: O(Nlogk), n is the total number of nodes in two lists,  k is the list number
//Space Complexity: O(1)
/*
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size(); 
		if(len == 0) return NULL;
		if(len == 1) return lists[0];
		
		int interval = 1;
		while(interval < len){
			for(int i = 0; i <= len - interval; ){
				if(i + interval <= len - 1)
					lists[i] = merge2Lists(lists[i], lists[i + interval]);		
				i += interval * 2;
			}
			interval *= 2;
		}
		return lists[0];
	}

	ListNode* merge2Lists(ListNode* l1, ListNode* l2){
		ListNode* result = new ListNode(0);
		ListNode* ptr = result;

		while(l1 || l2){
			ListNode *newNode;
			if(l1 == NULL){
				ptr->next = l2;
				break;
			}
			if(l2 == NULL){
				ptr->next = l1;
				break;
			}

			if(l1->val < l2->val){
				newNode = new ListNode(l1->val);
				l1 = l1->next;
			}
			else{
				newNode = new ListNode(l2->val);
				l2 = l2->next;
			}

			ptr->next = newNode;
			ptr = ptr->next;
		}

		return result->next;
	}
};
*/

//Approach 3: vector + sort() 
//Runtime: 32 ms, faster than 42.49% of C++ online submissions
//Time complexity : O(n^2), N is total number in all lists
//Space complexity: O(n)
/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        ListNode* curr;
        for(int i = 0; i < lists.size(); i++){
            curr = lists[i];
            while(curr){
                temp.push_back(curr->val);
                curr = curr->next;
            }
        }
        ListNode* head = NULL;
        if(!temp.empty()){
            sort(temp.begin(),temp.end());
            head = new ListNode(temp[0]);
        }
        curr = head;
        for(int i = 1; i < temp.size(); i++){
            ListNode* t = new ListNode(temp[i]);
            curr->next = t;
            curr = t;
        }
        return head;
    }
};
*/

//Approach 4: Priority Queue, similar to approach 3
//Runtime: 16 ms, faster than 99.72% of C++ online submissions
//Time complexity : O(Nlogk), N is total number in all lists, k is the lists number
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