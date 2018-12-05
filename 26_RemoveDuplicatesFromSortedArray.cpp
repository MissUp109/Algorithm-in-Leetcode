#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0) return 0;
    	int pre = nums[0], count = 0;
        for(int i = 1; i < nums.size(); ++i){
        	if(nums[i] != pre){
        		nums[++count] = nums[i];
        		pre = nums[i];
        	}
        }
        return count + 1;
    }
};

int main(){
	int a[10] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> vec(a, a + 10);
	Solution sol;
	int test = sol.removeDuplicates(vec);
	cout << test << endl;
	for(int i = 0; i < vec.size(); ++i){
		cout << vec[i] << " ";
	}
	cout <<  endl;
}