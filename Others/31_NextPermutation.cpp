#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Runtime: 4 ms, faster than 100.00% of C++ online submissions
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || size == 1) return;

        int i;
        for(i = size - 2; i >= 0; ){
        	if(nums[i] >= nums[i + 1]) --i;
        	else break;
        }

        //cout << "i: " << i << endl;

        if(i < 0) {
        	reverse(nums, 0, size - 1);
        	return;
        }

        int j;
        for(j = i + 1; j < size; ++j)
        	if(nums[i] >= nums[j]) break;

        //cout << "j: " << j << endl;
        swap(nums, i, j - 1);
        reverse(nums, i + 1, size - 1);
    }

    void reverse(vector<int> &nums, int left, int right){
    	if(left >= right || right > nums.size() - 1) return;

    	int tmp;
    	while(left < right){
    		swap(nums, left, right);
    		++left;
    		--right;
    	}
    }

    void swap(vector<int> &nums, int i, int j){
    	int tmp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = tmp;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 3, 5, 4};
	sol.nextPermutation(nums);
	//sol.reverse(nums, 0, 3);
	for(auto itr = nums.begin(); itr != nums.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
}