#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Runtime: 0 ms, faster than 100.00%
static const auto iso_sync_off = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size(); 
        if(len == 0) return "";
        if(len == 1) return strs[0];

        string ret = strs[0], cmp, tmp;
        for(int i = 1; i < strs.size(); ++i){
        	cmp = strs[i];
        	if(ret.size() > cmp.size()){
        		tmp = ret;
        		ret = cmp;
        		cmp = tmp;
        	}

        	while(ret.size() > 0){
        		int retLen = ret.size();
        		cmp = cmp.substr(0, retLen);
        		if(ret.compare(cmp) != 0) ret = ret.substr(0, retLen - 1);
        		else break;
        	}

        	if(ret.size() == 0) return "";

        }
        return ret;
    }
    
};

int main(){
	Solution sol;
	string s[] = {"dog", "racecar", "car"};
	vector<string> vec(&s[0], &s[3]);
	cout << sol.longestCommonPrefix(vec) << endl;
}