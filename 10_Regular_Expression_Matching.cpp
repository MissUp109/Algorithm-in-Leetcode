#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//enum TYPE {Dot, Star, Letter};


//Approach 1: Recursive 
//Runtime: 104 ms
//Time Complexity: 
//Space Complexity:
/*
class Solution {
public:
    bool isMatch(string s, string p) {
    	if(p.empty()) return s.empty();
    	bool first_match = (!s.empty()) && (s[0] == p[0] || p[0] == '.');
    	if(p.length() >= 2 && p[1] == '*')
    		return isMatch(s, p.substr(2)) || first_match && isMatch(s.substr(1), p);
    	else
    		return first_match && isMatch(s.substr(1), p.substr(1));
    }
};
*/


//Approach 2: Dynamic Programming: Top-Down Variation
//Runtime: 8 ms
//Time Complexity: O(TP)
//Space Complexity: O(TP)
/*
class Solution {
public:
    bool isMatch(string text, string pattern) {
        memo = new int *[text.length() + 1];
        for(int i = 0; i < text.length() + 1; ++i){
        	memo[i] = new int[pattern.length() + 1];
        	memset(memo[i], -1, sizeof(int) * (pattern.length() + 1));
        } 
        //ERROR: memset(memo, 0, sizeof(int) * (pattern.length() + 1) * (text.length() + 1));
        return dp(0, 0, text, pattern);
    }

    bool dp(int i, int j, string text, string pattern) {
        if (memo[i][j] != -1) 
            return memo[i][j] == 1;
        
        bool ans;
        if (j == pattern.length()){
            ans = (i == text.length());
        }
        else{
            bool first_match = (i < text.length() && (pattern[j] == text[i] || pattern[j] == '.'));

            if (j + 1 < pattern.length() && pattern[j + 1] == '*'){
            	ans = (dp(i, j + 2, text, pattern) || first_match && dp(i + 1, j, text, pattern));
            }
            else{
            	ans = first_match && dp(i + 1, j + 1, text, pattern);
            } 
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
private:
	int **memo;
};
*/
//Approach 3: Dynamic Programming: Bottom-Up Variation
//Time Complexity: O(TP)
//Space Complexity: O(TP)
//Runtime: 4 ms
class Solution {
public:
	bool isMatch(string text, string pattern) {
        bool **dp = new bool *[text.length() + 1];
        for(int i = 0; i < text.length() + 1; ++i){
        	dp[i] = new bool[pattern.length() + 1];
        	memset(dp[i], false, sizeof(bool) * (pattern.length() + 1));
        }

        dp[text.length()][pattern.length()] = true;

        for (int i = text.length(); i >= 0; i--){
            for (int j = pattern.length() - 1; j >= 0; j--){
                bool first_match = (i < text.length() && (pattern[j] == text[i] || pattern[j] == '.'));
                if (j + 1 < pattern.length() && pattern[j + 1] == '*'){
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                } 
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main(){
	Solution sol;
	string s, p;
	s= "acaabbaccbbacaabbbb"; p = "";
	if(sol.isMatch(s, p)) cout << "true" << endl;
	else cout << "false" << endl;
}