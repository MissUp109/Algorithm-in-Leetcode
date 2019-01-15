#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

//Runtime: 132 ms, faster than 7.74% of C++ online submissions
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {       
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[nums.size() -1];
        for(int i = 0; i < nums.size() - 2; ++i){
        	if(i > 0 && nums[i] == nums[i - 1]) continue;
        	for(int j = i + 1; j < nums.size() - 1; ++j){
        		int k = j + 1;
        		while(k < nums.size()){
        			int sum = nums[i] + nums[j] + nums[k];
        			if(abs(sum - target) < abs(ret - target))
        				ret = sum;
        			k++;
        		}
        	}
        }
        return ret;
    }
};
*/

//Runtime: 12 ms, faster than 31.02% of C++ online submissions
/*
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ret = nums[0] + nums[1] + nums[2], sum;
		for(int i = 0; i < nums.size() - 2; ++i){
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			for(int j = i + 1; j < nums.size() - 1; ++j){
				if(j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1;
				int right = nums.size() - 1;
				int middle;
				while(left < right){
					middle = (left + right) / 2;
					sum = nums[i] + nums[j] + nums[middle];
					if(abs(ret - target) > abs(sum - target))
						ret = sum;	
					if(sum > target)
						right = middle;
					else if(sum < target)
						left = middle + 1;
					else
						return target;
					
				}
				if(left == right){
					sum = nums[i] + nums[j] + nums[left];
					if(abs(ret - target) > abs(sum - target))
						ret = sum;	
					continue;
				}	
			}
		}
		return ret;
	}
};
*/

//Runtime: 4 ms, faster than 99.96% of C++ online submissions 
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int sum, ret;
		ret = nums[0] + nums[1] + nums[2];
		for(int i = 0; i < nums.size() - 2; ++i){
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k){
				sum = nums[i] + nums[j] + nums[k];
				if(abs(ret - target) > abs(sum - target))
					ret = sum;
				if(sum > target) k--;
				else if(sum < target) j++;
				else return target;
			}
		}
		return ret;
	}
};

int main(){
	Solution sol;
	vector<int> vec{-1, 2, 1, -4};
	cout << sol.threeSumClosest(vec, 1);
}