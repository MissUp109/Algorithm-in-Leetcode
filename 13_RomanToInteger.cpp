#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//Runtime: 60 ms, faster than 57.85% of C++ 

static const auto io_sync_off = []() {//Lambda捕获
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}(); 
// modified by reference: https://blog.csdn.net/qq_32320399/article/details/81518476
//refer 2: https://www.cnblogs.com/PrayG/p/5749832.html

class Solution {
public:
    int romanToInt(string s) {
    	map<char, int> table;
    	table['I'] = 1; table['V'] = 5; table['X'] = 10; table['L'] = 50;
    	table['C'] = 100; table['D'] = 500; table['M'] = 1000;
    	int result = 0, pre = 0, cur;
    	for(int i = s.size() - 1; i >= 0; --i){
    		cur = table[s[i]];
    		if(pre > cur) result -= table[s[i]];
    		else result += cur;
    		pre = cur;
    	}
        return result;
    }
};


int main(){
	Solution sol;
	cout << sol.romanToInt("III") << endl;
	cout << sol.romanToInt("IV") << endl;
	cout << sol.romanToInt("IX") << endl;
	cout << sol.romanToInt("LVIII") << endl;
	cout << sol.romanToInt("MCMXCIV") << endl;
}