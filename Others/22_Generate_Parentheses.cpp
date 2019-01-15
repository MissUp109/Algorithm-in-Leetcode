#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Approach 1: Brute Force

//Approach 2: Backtrack
//Time Complexity: O(C(2n, n) / n) -> O((4^n)/sqrt(n)) (Catalan number)
//Space Complexity: O(C(2n, n) / n) -> O((4^n)/sqrt(n))
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string> &ans, string cur, int open, int close, int max){
        if (cur.length() == max * 2) {
            //cout << cur << " ";
            ans.push_back(cur);
            return;
        }

        if (open < max)
            backtrack(ans, cur + "(", open + 1, close, max);
        if (close < open)
            backtrack(ans, cur + ")", open, close + 1, max);
    }
};
*/

//Approach 3: Closure Number
//Time Complexity: O(C(2n, n) / n) -> O((4^n)/sqrt(n)) (catalan number)
//Space Complexity: O(C(2n, n) / n) -> O((4^n)/sqrt(n))
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        } 
        else {
            for (int c = 0; c < n; ++c)
                for (string left: generateParenthesis(c))
                    for (string right: generateParenthesis(n-1-c))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    cout << result.size() << endl;
    for(auto itr = result.begin(); itr != result.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}