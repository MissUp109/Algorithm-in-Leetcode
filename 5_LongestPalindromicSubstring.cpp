#include <iostream>
#include <string>
using namespace std;

//Approach 1: Brute Force
//Time complexity : O(n^3)
//Space complexity : O(1)
//----------------------------------------->time limit exceeded
/*
class Solution {
public:
    string longestPalindrome(string s) {
    	string result = s.substr(0, 1);
    	int maxLen = 1;
        for(int i = 0; i < s.length(); i++){
        	for(int j = i; j < s.length(); j++){
        		int tmpLen = j - i + 1;
        		string substr = s.substr(i, tmpLen);
        		if(IsPalindrome(substr) && maxLen < tmpLen){
        			result = substr;
        			maxLen = tmpLen;
        		}
        	}
        }
        return result;
    }

    bool IsPalindrome(string &s){
    	int begin = 0, end = s.length() - 1;
    	while (begin <= end){
    		if(s[begin] != s[end])
    			return false;
    		begin++;
    		end--;
    	}
    	return true;
    }
};
*/

//Approach 2-1: Dynamic Programming 动态规划 by yy
//Time complexity : O(n^2)
//Space complexity : O(n^2)
//----------------------------------------->time limit exceeded
/*
class Solution {
public:
    string longestPalindrome(string s) {
    	string result = "";
    	const int len = s.length();
    	if(len == 0) return result;

    	int **strMap = new int*[len];
    	for(int i = 0; i < len; i++)
    		strMap[i] = new int[len];

    	for(int i = 0; i < len; i++)
    		for(int j = i; j < len; j++){
    			if(j - i == 0) 
    				strMap[i][j] = 1;
    			else if(j - i == 1)
    				strMap[i][j] = (s[i] == s[j]) ? 1 : 0;
    			else 
    				strMap[i][j] = -1;
    		}

    	int maxLen = 0;
    	for(int i = 0; i < len; i++){
    		for(int j = i; j < len; j++){
    			if(isPalindrome(i, j, s, strMap) == 1 && maxLen < j - i + 1){
    				maxLen = j - i + 1;
    				result = s.substr(i, j - i + 1);
    			}
    		}
    	}
    	return result;
    }

    int isPalindrome(int begin, int end, string s, int **strMap){  	
    	if(strMap[begin][end] != -1)
    		return strMap[begin][end];
    	else
    		strMap[begin][end] = (isPalindrome(begin + 1, end - 1, s, strMap) == 1) && (s[begin] == s[end]);

    	return strMap[begin][end];
    }
};
*/

//Approach 2-2: Dynamic Programming 动态规划 by anonymous
//Runtime: 64ms
//Time complexity : O(n^2)
//Space complexity : O(n^2)
//Refer link-> https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP
/*
class Solution {
public:
    string longestPalindrome(string s) {
    	string result = "";
    	const int len = s.length();
    	if(len == 0) return result;

    	bool strMap[len][len] = {false};

    	for(int i = 0; i < len; i++){
    		strMap[i][i] = true;
    		if(i == len - 1) break;
    		strMap[i][i + 1] = s[i] == s[i + 1];
    	}

    	for(int i = len - 3; i >= 0; i--){
    		for(int j = i + 2; j < len; j++){
    			strMap[i][j] = strMap[i + 1][j - 1] && (s[i] == s[j]);
    		}
    	}
    	int maxIndex = 0, maxLen = 1;
    	for(int i = 0; i < len - 1; i++){
    		for(int j = i + 1; j < len; j++){
    			if(strMap[i][j] && maxLen < j - i + 1){
    				maxLen = j - i + 1;
    				maxIndex = i;
    			}
    		}	
    	}
    	result = s.substr(maxIndex, maxLen);
    	return result;	

    }
};
*/

//Approach 3: Expand Around Center
//Runtime: 16ms
//Time complexity : O(n^2)
//Space complexity : O(1)
/*
class Solution {
public:
    int pallindromeLength(int &l, int &r, string &s) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        l++; r--;
        return (r-l+1);
    }
    
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0, maxLen = 0, idx = 0;
        for (int i = 0; i < s.size(); ++i) {
        	//奇数回文
            int left = i-1, right = i+1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
            //偶数回文
            left = i; right = i+1;
            len = pallindromeLength(left, right, s);
            idx = (len > maxLen) ? left : idx;
            maxLen = max(len, maxLen);
        }
        
        if (maxLen)
            ans = s.substr(idx, maxLen);
        return ans;
    }
};
*/

//Approach 4: Manacher's algorithm
//Runtime: 4ms
//Time complexity : O(n)
//Space complexity : O(n)
//Refer Link -> https://articles.leetcode.com/longest-palindromic-substring-part-ii/
//将方法3的量汇总情况合并成一个考虑
//在字符串之间插入“#”符号
//比如字符串S = "abaaba"
//插入之后为T = "#a#b#a#a#b#a#"

class Solution {
public:
	string preProcess(string s){
		int n = s.length();
		if(n == 0)
			return "^$";
		
		string ret = "^";
		for(int i = 0; i < n; i++){
			ret += "#" + s.substr(i, 1);
		}
		ret += "#$";
		return ret;
	}
	string longestPalindrome(string s){
		string T = preProcess(s);
		const int n = T.length();
		int p[n] = {0};
		int C = 0, R = 0;
		for(int i = 1; i < n - 1; i++){
			p[i] = i < R ? min(p[2 * C - i], R - i) : 0;
			while(T[i + p[i] + 1] == T[i - p[i] - 1])
				p[i]++;

			if(i + p[i] > R){
				C = i;
				R = i + p[i];
			}
		}

		int maxP = 0, cIndex = 0;
		for(int i = 2; i < n - 2; i++){
			if(maxP < p[i]){
				maxP = p[i];
				cIndex = i;
			}
		}

		return s.substr((cIndex - 1 - maxP)/2, maxP);
	}
};

int main(){
	Solution sol;
	cout << sol.longestPalindrome("ghjdkalkgnvndkdk");
}