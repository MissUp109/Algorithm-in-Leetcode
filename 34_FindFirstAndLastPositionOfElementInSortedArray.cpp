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

//Approach 1: by Leah
//Runtime: 4 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        int l = 0, r = nums.size() - 1;
        binarySearch(nums, target, l, r, ret);
        return ret;
    }
    void binarySearch(vector<int>& nums, int target, int l, int r, vector<int>& range){
        int m;
    	while(l <= r){
            //cout << "l: " << l << ", r:" << r << endl;
    		m = (l + r) / 2;
            //cout << "m: " << m << endl;
    		if(nums[m] == target){
                if(range[0] == -1 && range[1] == -1){
                    range[0] = m; range[1] = m;
                }
                else{
                    range[0] = (m < range[0]) ? m : range[0];
                    range[1] = (m > range[1]) ? m : range[1];
                }

                binarySearch(nums, target, l, m - 1, range);
                binarySearch(nums, target, m + 1, r, range);

                break;
    		}
    		else if(nums[m] < target) l = m + 1;
    		else r = m - 1;	
    	}
    }
};


//Approach 2: by others
/*
class Solution {
    // returns leftmost (or rightmost) index at which `target` should be
    // inserted in sorted array `nums` via binary search.
private:
    int extremeInsertionIndex(vector<int>& nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else lo = mid + 1;
        }

        return lo;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange = {-1, -1};

        int leftIdx = extremeInsertionIndex(nums, target, true);

        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

        return targetRange;
    }
};
*/

int main(){
	Solution sol;
	vector<int> nums = {1};
	int target = 0;
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

00122, 2
1,1
123,1
*/

