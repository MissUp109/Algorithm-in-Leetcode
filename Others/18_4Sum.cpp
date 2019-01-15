#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

//Runtime: 8 ms, faster than 99.65% of C++ online submissions
static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
    	if(nums.size() < 4) return result;

    	sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 3; ++i){
        	if(i > 0 && nums[i] == nums[i - 1]) continue;
        	for(int j = i + 1; j < nums.size() - 2; ++j){
        		if(j > i + 1 && nums[j] == nums[j - 1]) continue;
        		int m = j + 1;
        		int n = nums.size() - 1;
        		if(nums[i] + nums[j] + 2 * nums[m] > target) continue;
        		if(nums[i] + nums[j] + 2 * nums[n] < target) continue;
        		while(m < n){
        			int sum = nums[i] + nums[j] + nums[m] + nums[n];
        			if(sum < target) m++;
        			else if(sum > target) n--;
        			else{
        				vector<int> vec{nums[i], nums[j], nums[m], nums[n]};
        				result.push_back(vec);
        				while(nums[m + 1] == nums[m]) m++;
        				while(nums[n - 1] == nums[n]) n--;
        				m++;
        				n--;
        			}

        		}
        	}
        }
        return result;
    }
};


int main(){
	Solution sol;
	vector<int> vec{1, 0, -1, 0, -2, 2};
	vector<vector<int>> ret = sol.fourSum(vec, 0);
	for(int i = 0; i < ret.size(); ++i){
		cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << " " << ret[i][3] <<endl;
	}
}