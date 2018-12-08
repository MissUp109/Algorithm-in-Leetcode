#include <iostream>
#include <string>
#include <climits>

using namespace std;
//Time Limit Exceeded
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

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

int main(){
	Solution sol;
	cout << sol.divide(INT_MIN, 2) << endl;
}