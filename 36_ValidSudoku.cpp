#include <iostream>
#include <vector>
#include <set>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Runtime: 8 ms, faster than 98.98% of C++ online submissions
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isRowValid(board) && isColumnValid(board) && isSubboxValid(board, 3);
    }

    bool isRowValid(vector<vector<char>>& board){
    	for(int i = 0; i < board.size(); ++i){
    		set<char> mySet;
    		for(int j = 0; j < board[0].size(); ++j){
    			if(board[i][j] == '.') continue;
    			if(mySet.count(board[i][j]) == 1) return false;
    			mySet.insert(board[i][j]);
    		}
    		//mySet.clear();
    	}
    	return true;
    }

    bool isColumnValid(vector<vector<char>>& board){
    	for(int j = 0; j < board[0].size(); ++j){
    		set<char> mySet;
    		for(int i = 0; i < board.size(); ++i){
    			if(board[i][j] == '.') continue;
    			if(mySet.count(board[i][j]) == 1) return false;
    			mySet.insert(board[i][j]);
    		}
    		//mySet.clear();
    	}
    	return true;
    }

    bool isSubboxValid(vector<vector<char>>& board, int num){
    	for(int i = 0; i < num; ++i){
    		for(int j = 0; j < num; ++j){
    			set<char> mySet;
    			for(int m = 0; m < num; ++m){
    				for(int n = 0; n < num; ++n){
    					if(board[m + num * i][n + num * j] == '.') continue;
    					if(mySet.count(board[m + num * i][n + num * j]) == 1) return false;
    					mySet.insert(board[m + num * i][n + num * j]);
    				}
    			}
    		}
    	}
    	return true;
    }
};

/*
Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false


*/

int main(){
	Solution sol;
	vector<vector<char>> board = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','.'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	if(sol.isValidSudoku(board)) cout << "true" << endl;
	else cout << "false" << endl;
}

