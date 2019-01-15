#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;
//Approach 1: by Leah
//Runtime: 20ms
class Solution {
public:
    int myAtoi(string str) {
    	if(str.length() == 0) return 0;
        bool nonWhiteSpace = false;
    	bool started = false;      
    	char mark = '\0';
    	string ret = "";
  	
    	for(int i = 0; i < str.length(); ++i){
            if(!started && ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+' && str[i] != ' '))) { return 0; }
    		if(!started && str[i] == ' ') { if(nonWhiteSpace) return 0; continue; }
            if(!started && str[i] == '0'){ nonWhiteSpace = true; continue; }
    		if(!started && (str[i] == '-' || str[i] == '+')) {
                if(nonWhiteSpace) return 0;
                else{ mark = str[i]; nonWhiteSpace = true; continue;} 
    		}
            if(!started && (str[i] >= '1' && str[i] <= '9')){ started = true; ret += str[i]; continue; }		
    		
    		if(started && (str[i] < '0' || str[i] > '9')) { break; }
    		if(started && (str[i] >= '0' && str[i] <= '9')) { ret += str[i]; }
    	}

    	if(mark != '\0') ret = mark + ret;

    	int len = ret.length();
    	if(len == 0 || (len == 1 && (ret[0] == '-' || ret[0] == '+'))) return 0;

        stringstream ss;
        int quotient = 0, remainder = 0;    	
    	ss << ret.substr(len - 1, 1);
    	ss >> remainder;

    	if(ret[0] != '-' && ret[0] != '+'){
            if(len > 10) return INT_MAX;

            if(len > 1){
                ss.clear(); ss.str("");
                ss << ret.substr(0, len - 1);
                ss >> quotient;
            }
            
            if((quotient > INT_MAX / 10) || (quotient == INT_MAX /10 && remainder > 7)) return INT_MAX;
            else return quotient * 10 + remainder;
    	}
        else{
            if(len > 2) {
                ss.clear(); ss.str("");
                ss << ret.substr(1, len - 2);
                ss >> quotient;
            }

            if(ret[0] == '-'){
                if(len > 11) return INT_MIN;
                if((-quotient < INT_MIN / 10) || (-quotient == INT_MIN /10 && -remainder < -8)) return INT_MIN;
                else return -quotient * 10 - remainder;
            }

            if(ret[0] == '+'){
                if(len > 11) return INT_MAX;
                if((quotient > INT_MAX / 10) || (quotient == INT_MAX /10 && remainder > 7)) return INT_MAX;
                else return quotient * 10 + remainder;
            }
        }
        cout << endl;
    }
};

//Approach 2: define ret as a double-type

int main(){
	Solution sol;
	cout << sol.myAtoi("  -42");
}