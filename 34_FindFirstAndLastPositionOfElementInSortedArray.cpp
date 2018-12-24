#include <iostream>
#include <vector>
#include <string>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        int l = 0, r = nums.size() - 1;
        bool flag = false;
        binarySearch(nums, target, l, r, flag);
        if(flag){
        	ret[0] = l; ret[1] = r;
        	cout << "flag = true" << endl;
        }
        return ret;
    }
    void binarySearch(vector<int>& nums, int target, int& l, int& r, bool& flag){
    	while(l < r){
    		int m = (l + r) / 2;
    		cout << "m: " << m << endl;
    		if(nums[m] == target){
    			int cm = m;
    			flag = true;
    			binarySearch(nums, target, l, cm - 1, flag);
    			binarySearch(nums, target, cm + 1, r, flag);
    			break;
    		}
    		else if(m < target) {
    			l = m + 1;
    			//cout << "l: " << l << endl;
    		}
    		else{
    			r = m - 1;
    			//cout << "r: " << r << endl;
    		}
    	}
    }
};

int main(){
	Solution sol;
	vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> ret = sol.searchRange(nums, target);
	cout << ret[0] << " " << ret[1] << endl;
}

/*
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

