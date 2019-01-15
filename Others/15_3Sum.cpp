#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

static const auto iso_sync_off = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return 0;
}();


//Runtime: 424 ms, faster than 8.01% of C++ online submissions
/*
struct Info {
	int count;
	int index;
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> ret;

    	int len = nums.size();
    	if(len < 3) return ret;

    	map<int, Info> table;
    	vector<int> rnums;
        for(int i = 0; i < len; ++i){
        	if(table.count(nums[i]))
        		table[nums[i]].count++;
        	else{
        		table[nums[i]].count = 1;
        		table[nums[i]].index = rnums.size();
        		rnums.push_back(nums[i]);     		
        	}
        }
        for(int i = 0; i < rnums.size(); ++i){
        	cout << "num: " << rnums[i] << ", index: " << table[rnums[i]].index << ", count: " << table[rnums[i]].count << endl;
        }

        int rlen = rnums.size();
        for(int i = 0; i < rlen; ++i){
        	Info info = table[rnums[i]];
        	if(info.count >= 3 && rnums[i] == 0){
        		vector<int> tmp;
        		tmp.push_back(0);
        		tmp.push_back(0);
        		tmp.push_back(0);
        		ret.push_back(tmp);
        	}
        	if(info.count >= 2){
        		auto itr = table.find(-2 * rnums[i]);
        		if(itr != table.end() && rnums[i] != 0){
        			vector<int> tmp;
        		    tmp.push_back(rnums[i]);
        		    tmp.push_back(rnums[i]);
        		    tmp.push_back(-2 * rnums[i]);
        		    ret.push_back(tmp);
        		}
        	}
        	if(i == rlen - 1) break;
        	for(int j = i + 1; j < rlen - 1; ++j){
        		auto itr = table.find(- rnums[i] - rnums[j]);
        		if(itr != table.end() && (itr->second).index > j){
        			vector<int> tmp;
        			tmp.push_back(rnums[i]);
        			tmp.push_back(rnums[j]);
        			tmp.push_back(- rnums[i] - rnums[j]);
        			ret.push_back(tmp);
        		}
        	}
        }
        
        return ret;
    }
};
*/

//Runtime: 72 ms, faster than 92.37% of C++ online submissions
class Solution{
public:
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> ret;
		if(nums.size() <= 2) return ret;
		sort(nums.begin(), nums.end());

		for(unsigned int i = 0; i < nums.size() - 2; ++i){
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = nums.size() - 1;
			while(j < k){
				int sum = nums[i] + nums[j] + nums[k];
				if(sum > 0) k--;
				else if(sum < 0) j++;
				else{
					ret.push_back(vector<int> {nums[i], nums[j], nums[k]} );
					while(nums[j] == nums[j + 1]) j++;
					while(nums[k] == nums[k - 1]) k--;
					j++;
					k--;
				}
			}
		}
		return ret;
	}	
};

int main(){
	Solution sol;
	int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<int> vec(&a[0], &a[15]);
	vector<vector<int>> test = sol.threeSum(vec);
	for(int i = 0; i < test.size(); ++i){
		for(int j = 0; j < test[i].size(); ++j){
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
}

