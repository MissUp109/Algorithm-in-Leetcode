#include <iostream>
#include <math.h>
using namespace std;

//Approach 1: by Leah
//Runtime: 156 ms

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0) return false;
        int len = 0, root = x;
        while(root != 0){
        	len++;
        	root /= 10;
        }
        int k = 0, quotient, remainder;
        while (k < len/2){
        	quotient = x / pow(10, len - (1 + 2 * k)); quotient %= 10; 
        	remainder = x % 10; cout << remainder << endl;
        	x /= 10; k++; 
        	if(quotient != remainder) return false;
        }

        return true;
    }
};

//Approach 2: Revert half of the number
//Time complexity : O(log10(n))
//Space complexity : O(1)
//Runtiem : 240ms
/*
class Solution {
public:
	bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }
};
*/
int main(){
	Solution sol;
	if(sol.isPalindrome(11)) cout << "true" << endl;
	else cout << "false" << endl;
}