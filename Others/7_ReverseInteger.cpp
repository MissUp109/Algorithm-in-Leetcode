#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <math.h>
using namespace std;

//Approach 1: Using strignstream (by Leah)
//Runtime: 30ms
/*
class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        ss << x;
        string str_x;
        ss >> str_x;

        //cout << "string x: " << str_x << endl;
        string str_ret = "";
        if(str_x[0] == '-'){
        	str_ret += '-';
        	str_x = str_x.substr(1, str_x.length() - 1);
        }
        //cout << "string x 2: " << str_x << endl;

        for(int i = str_x.length() - 1; i >= 0; --i){
        	str_ret += str_x[i];
        }
        //cout << "string ret: " << str_ret << endl;

        ss.clear(); ss.str("");
        ss << str_ret;
        int int_ret;
        ss >> int_ret;
        //cout << "int ret: " << int_ret << endl;

        ss.clear(); ss.str("");
        string tmp;
        ss << int_ret;
        ss >> tmp;
        //cout << "tmp string: " << tmp << endl;

        if(str_ret.compare(tmp) != 0){
            if(str_ret[0] == '0')
                return int_ret;
            else if(str_ret[0] == '-' && str_ret[1] == '0')
                return int_ret;
            else return 0;
        }     
        else return int_ret;
    }
};
*/

//Approach 2: Pop and Push Digits & Check before Overflow
//Runtime: 12ms
//Time Complexity: O(log10(x))
//Space Complexity: O(1)
class Solution {
public:
    int reverse(int x){
        int ret = 0;

        while(x != 0){
            int pop = x % 10;

            if((x > 0) && ((ret > INT_MAX / 10) || (ret == INT_MAX / 10 && pop > 7)))
                return 0;
            else if((x < 0) && (ret < INT_MIN / 10) || (ret == INT_MIN / 10 && pop > 8))
                return 0;
            else ret = ret * 10 + pop;
            x /= 10;
        }
        return ret;
    }
};

int main(){
	Solution sol;
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "INT_MIN: " << INT_MIN << endl;
	cout << sol.reverse(INT_MAX) << endl;
}