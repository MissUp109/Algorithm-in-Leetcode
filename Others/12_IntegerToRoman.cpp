#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Approach by Leah using struct
/*
struct Refer{
	int int_num;
	string roman_num;
};
class Solution {
public:
    string intToRoman(int num) {
    	string result = "";
    	Refer table[7] = {
    		1, "I", 5, "V", 10, "X", 50,"L", 
    		100, "C", 500,"D", 1000, "M"
    	};

    	int i = 7, quotient, remainder = num;
    	while(i >= 1){
    		quotient = remainder / table[i - 1].int_num;
    		while(quotient-- > 0) result += table[i - 1].roman_num;

    		remainder = remainder % table[i - 1].int_num;
    		if(remainder == 0) return result;

    		if(i > 1){
    			int pivot = (i / 2) * 2 - 1;
    			quotient = remainder / (table[i - 1].int_num - table[pivot - 1].int_num);
    			while(quotient-- > 0) result += (table[pivot - 1].roman_num + table[i - 1].roman_num);

    			remainder = remainder % (table[i - 1].int_num - table[pivot - 1].int_num);
    			if(remainder == 0) return result;
    		}
    		
    		--i;
    	}
    	return result;
    }     
};
*/

//Approach mostly uesd
class Solution {
public:
    const vector<int> values{1000, 900, 500,400,100,90,50,40,10,9,5,4,1};
    const vector<string> str{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
    string intToRoman(int num) {
        string ret;
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                num -= values[i];
                ret += str[i];
            }
        }
        return ret;
    }
};

int main(){
	Solution sol;
	cout << sol.intToRoman(3) << endl;//"III"
	cout << sol.intToRoman(9) << endl;
	cout << sol.intToRoman(58) << endl;
	cout << sol.intToRoman(1994) << endl;
}

/*
    	Refer table[13] = {
    		1, "I", 4, "IV", 5, "V", 9, "IX", 10, "X", 40, "XL", 50，"L", 
    		90，"XC", 100, "C", 400，"CD", 500，"D", 900, "CM", 1000, "M"
    	}
*/