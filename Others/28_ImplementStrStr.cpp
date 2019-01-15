#include <iostream>
#include <string>
using namespace std;

//Approach 1
//Runtime: 4 ms, faster than 98.68% of C++ online submissions
class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle == "") return 0;
    	if(haystack.size() < needle.size()) return -1;

    	int len1 = haystack.size(), len2 = needle.size();
        for(int i = 0; i < len1; ++i){
        	if(len1 - i < len2) return -1;
        	if(haystack.substr(i, len2) == needle)
        		return i;
        }
        return -1;
    }
};

/*
//Approach 2
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        
        if(needle.size() > haystack.size()) {
            return -1;
        }
        
		// Find first occurrence
    	size_t found = haystack.find(needle); 
    	if (found != string::npos) {
        	return found; // It is Found!
		}
		//Not Found!
        return -1;
    }	
};
*/

int main(){
	string hs = "aaaaa", ndl = "";
	Solution sol;
	cout << sol.strStr(hs, ndl) << endl;
}
