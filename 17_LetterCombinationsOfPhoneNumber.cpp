#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

//Runtime: 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
	Solution(){
		table = {
			{2, "abc"}, {3, "def"}, {4, "ghi"},
			{5, "jkl"}, {6, "mno"}, {7, "pqrs"},
			{8, "tuv"}, {9, "wxyz"}
		};
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> result;
    	//cout << digits << endl;
    	return recursiveCombination(result, digits);
    }

    vector<string> recursiveCombination(vector<string>& com, string digits){
    	if(digits.size() == 0) return com;

    	vector<string> ret;
    	string num_str = table[digits[0] - '0'];
    	if(com.size() == 0){
    		for(int j = 0; j < num_str.size(); ++j){
    			//cout << "size == 0" << endl;
    			string new_str = "";
    			new_str += num_str[j];
    			ret.push_back(new_str);
    			//cout << new_str << " ";
    		}
    		//cout << endl;
    	}
    	else{
    		//cout << "size != 0" << endl;
    		for(int i = 0; i < com.size(); ++i){
    			string old_str = com[i];
    			for(int j = 0; j < num_str.size(); ++j){
    				string new_str = old_str + num_str[j];
    				ret.push_back(new_str);
    				//cout << new_str << " ";
    			}
    		}
    		//cout << endl;
    	}

    	return recursiveCombination(ret, digits.substr(1, digits.size() - 1));
    }

private:
	map<int, string> table;
};

int main(){
	Solution sol;
	vector<string> res = sol.letterCombinations("234");
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << " " ;
	
}