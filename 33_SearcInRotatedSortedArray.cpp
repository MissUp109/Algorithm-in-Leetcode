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
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size() == 0) return -1;
        if(nums[0] == target) return 0;
        if(nums.size() == 1 && nums[0] != target) return -1;

        if(nums[0] < target){
        	for(int i = 1; i < nums.size(); ++i){
        		if(nums[i] == target) return i;
        		if(nums[i - 1] > nums[i]) return -1;
        	}
        }
        else{
        	for(int i = nums.size() - 1; i >= 1; --i){	
        		if(nums[i] == target) return i;
        		if(nums[i - 1] > nums[i]) return -1;
        	}
        }
        return -1;
    }
};
*/

class Solution{
public:
	int search(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1;

		while(left <= right){
			int middle = (left + right) / 2;
			if(nums[middle] == target) return middle;
			if(nums[middle] < nums[right]){
				if(nums[middle] < target && target <= nums[right])
					left = middle + 1;
				else right = middle - 1;
			}
			else{
				if(nums[middle] > target && target >= nums[left])
					right = middle - 1;
				else left = middle + 1;
			}
		}
		return -1;
		
	}
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4, 0};
	int target = 4; //0, 3
	cout << sol.search(nums, target) << endl;
}