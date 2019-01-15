#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>//#include <algorithm>
#include <string>
using namespace std;

//Approach 1: by myself
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)
//Runtime = 32ms
/*
class Solution {
public:
    string convert(string s, int numRows) {
    	const int len = s.length();
    	if(len <= 0) return "";
    	if(numRows == 1) return s;
    	const int tmp = len / (2 * numRows - 2) + 1;
    	const int columns = (numRows - 1) * tmp; 

    	char record[numRows][columns];
    	memset(record, '\0', sizeof(record)); //fill_n(record, numRows * columns, 0);

        for(int index = 0; index < len; ++index){
        	int quotient = index / (numRows - 1);
        	int remainder = index % (numRows - 1);
        	
        	if(quotient % 2 == 0){
        	    //cout << remainder << " " << (numRows - 1) * quotient / 2 << endl;    		
        		record[remainder][(numRows - 1) * quotient / 2] = s[index];	
        	}
        	else{
        		//cout << (numRows - 1) - remainder << " " << (numRows - 1) * (quotient / 2) + remainder << endl;
        		record[(numRows - 1) - remainder][(numRows - 1) * (quotient / 2) + remainder] = s[index];
        	}
        }

        string result = "";
        
        for(int i = 0; i < numRows; ++i){
        	for(int j = 0; j < columns; ++j){
        		if(record[i][j] != '\0')
        			result += record[i][j];
        	}
        }
        
        return result;
    }
};
*/

//Approach 2: Sort by Row
//Time Complexity: O(n), where n==len(s)
//Space Complexity: O(n)
//Runtime = 20ms
/*
class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows == 1) return s;
    	int len = min(numRows, int(s.length()));
    	vector<string> rows(len);
    	int curRow = 0;
    	bool goingDown = true;
    	for(char c : s){
    		rows[curRow] += c;
    		if((curRow == 0 && !goingDown) || (curRow == len - 1 && goingDown))
    			goingDown = !goingDown;
    		if(goingDown) ++curRow;
    		else --curRow;
    	}
    	string ret = "";
    	for(string row : rows)
    		ret += row;
    	
    	return ret;
    }
};
*/


//Approach 3: Visit by Row
//Time Complexity: O(n), where n==len(s)
//Space Complexity: O(n)
//Runtime = 20ms

/*
For all whole numbers kk,
Characters in row 0 are located at indexes k*(2*numRows - 2);
Characters in row numRows-1 are located at indexes k * (2 * numRows - 2) + numRows - 1;
Characters in inner row i are located at indexes k * (2 * numRows - 2) + i and (k+1)(2 * numRows - 2)- i;
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};

int main(){
	Solution sol;
	string s = "PAYPALISHIRING";
	cout << sol.convert(s, 4);
}