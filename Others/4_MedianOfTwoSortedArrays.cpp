#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		for(vector<int>::iterator itr = nums2.begin(); itr != nums2.end(); itr++){
			nums1.push_back(*itr);
		}
		sort(nums1.begin(), nums1.end());//, MyCompare()
		
		if (nums1.size() % 2 == 0) {
			//for(int i = 0; i < nums1.size(); i++)
				//cout << nums1[i] << endl;
			return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) * .5f;
		} 
		else {
			int index = floor(nums1.size() / 2.0f);
			return nums1[index];
		}
    }
};

/*
class Solution {
public: 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int m = nums1.size();
    	int n = nums2.size();

    	if(m > n){
    		vector<int> tmp = nums1; nums1 = nums2; nums2 = tmp;
    		int temp = m; m = n; n = temp;
    	}

    	int i_min = 0, i_max = m; //这里的i指的是长度，不是下标
    	while(i_min <= i_max){
    		int i = (i_min + i_max) / 2;
    		int j = (m + n + 1) / 2 - i;

    		if(i < i_max && nums2[j-1] > nums1[i]){//i < i_max
    			i_max = i + 1;
    		}
    		else if(i > i_min && nums1[i-1] > nums2[j]){ //i > i_min
    			i_min = i - 1;
    		}
    		else {
    			int maxLeft = 0;
    			if(i == 0) 
    				maxLeft = nums2[j - 1];
    			else if(j == 0) 
    				maxLeft = nums1[i - 1];
    			else 
    				maxLeft = max(nums1[i - 1], nums2[j - 1]);

    			if((m + n) % 2 == 1) return maxLeft;

    		    int minRight = 0;
    		    if(i == m) 
    		    	minRight = nums2[j];
    		    else if(j == n) 
    		    	minRight = nums1[i];
    		    else 
    		    	minRight = min(nums1[i], nums2[j]);

    		    return (maxLeft + minRight) * .5f;
    		}

    	}
    	return 0.0;
    }
};
*/



int main(){
	Solution sol;
	vector<int> nums1 = {2, 3, 5, 7};
	vector<int> nums2 = {2, 4};
	cout << sol.findMedianSortedArrays(nums1, nums2);
}