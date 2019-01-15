#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given n non-negative integers a1, a2, ..., an , where each represents 

a point at coordinate (i, ai). n vertical lines are drawn such that t

-he two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 

which together with x-axis forms a container, such that the container 

contains the most water.

Note: You may not slant the container and n is at least 2.
*/

//Approach 1: Brute Force
//Runtime: 560ms
//Time Complexity: O(n^2)
//Space Complexity: O(1)
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	//cout << "len: " << len << endl;
    	int result  = 0, cur = 0;;
    	for(int i = 0; i < len; ++i){
    		for(int j = len - 1; j > i; --j){
    			cur = (j - i) * min(height[i], height[j]); 
    			//cout << "i: " << i << ", j: " << j << ", cur: " << cur << endl;
    			result = result < cur ? cur : result;
    		}
    	}
        return result;
    }
};
*/

//Approach 2: Two Pointer Approach
//Runtime: 12 ms
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	int result = 0;
    	for(int i = 0, j = len - 1; i < len, j > i; ){
    		result = max(result, (j - i) * min(height[i], height[j]));
    		if(height[i] < height[j]) ++i;
    		else --j;
    	}
    	return result;
    }
};



int main(){
	Solution sol;
	int v[9] = {1,8,6,2,5,4,8,3,7};
	vector<int> vec(&v[0], &v[9]);//注意第二个参数
	cout << sol.maxArea(vec) << endl;//49
}