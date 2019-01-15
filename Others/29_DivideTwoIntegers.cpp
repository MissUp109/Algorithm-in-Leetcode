#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Approach 1
//Time Limit Exceeded
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) {
        	if(dividend == INT_MIN) return INT_MAX;
        	else return -dividend;
        }

        int flag = 1, ofw_1 = 0, ofw_2 = 0;
        if(dividend < 0){
        	flag *= -1;
        	if(dividend > INT_MIN) dividend = -dividend;
        	else { dividend = INT_MAX; ofw_1 = 1;}
        }

        if(divisor < 0){
        	flag *= -1;
        	if(divisor > INT_MIN) divisor = -divisor;
        	else { divisor = INT_MAX; ofw_2 = 1; }
        }

        dividend = (dividend - divisor) + (ofw_1 - ofw_2);
        if(dividend < 0) return 0;

        divisor += ofw_2;
        int result = 1;
        while(dividend >= divisor){
        	dividend -= divisor;
        	++result;
        }

        return result * flag;
    }
};
*/

//Approach 2 
//Ref: https://leetcode.com/problems/divide-two-integers/discuss/13420/32-times-bit-shift-operation-in-C-with-O(1)-solution
//Runtime: 8 ms, faster than 99.49% of C++ online submissions
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }

        bool flag = (dividend > 0) ^ (divisor > 0);
        unsigned int A = abs(divisor), B = abs(dividend);
        //cout << udividend << " " << udivisor << endl;

        int result = 0;
        for(int i = 31; i >= 0; i--){
            if((B >> i) >= A){
                result = (result << 1) | 0x01;
                B -= (A << i);
            }
            else result = result << 1;
        }
        result = flag ? -result : result;
        return result;
    }
};

int main(){
	Solution sol;
	cout << sol.divide(10, 3) << endl;
}