#include <iostream>
#include <vector>
using namespace std;

//Approach 1 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int count = 0;
    	for(int i = 0; i < nums.size(); ++i){
        	if(nums[i] == val){
        		count++;
        	}
        	else{
        		nums[i - count] = nums[i];
        		cout << nums[i] << " ";
        	}
        }
        cout << endl;
        return nums.size() - count;
    }
};

//Approach 2: use sort()
/*
int removeElement(vector<int>& nums, int val) {
    int count = 0, INF = INT_MAX;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==val)
           nums[i]=INF, count++;
    sort(nums.begin(),nums.end());
    return nums.size()-count;
}
*/

int main(){
	int a[] = {0,1,2,2,3,0,4,2};
	vector<int> vec(a, a + 8);
	Solution sol;
	cout << sol.removeElement(vec, 2) << endl;
}
