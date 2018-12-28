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

//Runtime: 4 ms, faster than 98.74% of C++ online submissions

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int l = 0, r = nums.size() - 1, m;
        while(l <= r){
        	m = (l + r) / 2;
        	if(nums[m] == target)
        		return m;
        	else if(nums[m] < target){
        		l = m + 1;
        		//if(l < nums.size() && nums[l] > target) return l;
        	}
        	else{
        		r = m - 1;
        		//if(r >= 0 && nums[r] < target) return m;
        	}
        }
        return l;
        //if(l == nums.size()) return nums.size();
        //if(r == -1) return 0;
    }
};

/*
class Solution{
public:
	int searchInsert(vector<int>& nums, int target){
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};
*/


/*
Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
int main(){
	Solution sol;
	vector<int> nums = {1, 3, 5, 6};
	cout << sol.searchInsert(nums, 5) << endl;
}