#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
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
//Runtime: 4 ms, faster than 99.91% of C++ online submissions
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
    	vector<char> bucket;
    	int result = 0;
    	for(int i = 0; i < s.size(); ++i){
    		if(s[i]  == '('){
    			bucket.push_back('(');
    			continue;
    		}

    		if(s[i] == ')'){
    			if(bucket.size() == 0) continue;

    			int bSize = bucket.size();

    			if(bucket[bSize - 1] == '('){
    				bucket[bSize - 1] = '2';
    				continue;
    			}

    			if(bucket[bSize - 1] == '2'){
    				int j = bSize - 1, tmp = 0;
    			    while(j >= 0 && bucket[j] == '2'){ // To find last position which includes '('
    			    	--j; tmp += 2;
    			    } 
    			    if(j < 0){
    			    	result = result < tmp ? tmp : result;
    			    	tmp = 0; bucket.clear();
    			    }
    			    else bucket[j] = '2';
    			}

    		}
    	}

    	int tmp = 0;
    	for(int i = 0; i < bucket.size(); ++i){
    		if(bucket[i] == '2') tmp += 2;
    		else {
    			result = result < tmp ? tmp : result;
    			tmp = 0;
    		}
    	}
    	return result < tmp ? tmp : result;
    }
};
*/

//Approach 2: Using Dynamic Programming
//Runtime: 8 ms, faster than 66.87% of C++ online submissions
//Time Complexity: O(n)
//Space Complexity: O(n)
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        const int LEN = s.length();
        if(LEN <= 0) return 0;
        int *dp = new int[LEN]();
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        delete [] dp;
        return maxans;
    }
};
*/

//Approach 3: Using Stack  ---------> Optimal solution 
//Runtime: 4 ms, faster than 99.91% of C++ online submissions
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> bucket;
        bucket.push(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') 
                bucket.push(i);
            else {
                bucket.pop();
                if (bucket.empty())
                	bucket.push(i);
                else maxans = max(maxans, i - bucket.top());
            }
        }
        return maxans;
    }
};

int main(){
	Solution sol;
	cout << sol.longestValidParentheses("((()))((((((()))))((())(()())(()((()()(()()))((())((((()))(()())))))())))()())((()()))((((()()()()()((()())))(())((()(()((()))()()()))()(())()))))))()(()))((()()()()())(()()()))(())((())())") << endl;
}

