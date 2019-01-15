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

enum SetFuncType
{
  BUILD_SET = 0,
  CHECK_SET = 1
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board){
      bool flag = RowSetFunc(board, BUILD_SET) && ColumnSetFunc(board, BUILD_SET) && SubSetFunc(board, BUILD_SET);
      /*
      cout << "-------------row" << endl;
      for(int i = 0; i < rowSet.size(); ++i){
        set<char> rowSet_i = rowSet[i];
        for(auto j = rowSet_i.begin(); j != rowSet_i.end(); ++j){
          cout << *j << " ";
        }
        cout << endl;
      }
      cout << "-------------col" << endl;
      for(int i = 0; i < colSet.size(); ++i){
        set<char> colSet_i = colSet[i];
        for(auto j = colSet_i.begin(); j != colSet_i.end(); ++j){
          cout << *j << " ";
        }
        cout << endl;
      }

      cout << "-------------sub" << endl;
      for(int i = 0; i < subSet.size(); ++i){
        set<char> subSet_i = subSet[i];
        for(auto j = subSet_i.begin(); j != subSet_i.end(); ++j){
          cout << *j << " ";
        }
        cout << endl;
      }*/
      
      if(!flag){
        cout << "[flag == false] The original board is not valid.." << endl;
        return;
      }
      int i = 0, j = 0;
      if(greedySolution(board, i, j))
        cout << "done" << endl;
      else cout << "The board is unsolvable.." << endl;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return RowSetFunc(board, CHECK_SET) && ColumnSetFunc(board, CHECK_SET) && SubSetFunc(board, CHECK_SET);
    }

    bool greedySolution(vector<vector<char>>& board, int& i, int& j) {
      if(i == 9) return true;

      if(board[i][j] != '.'){
        i = (j + 1 == 9) ? i + 1 : i;
        j = (j + 1) % 9;
        return greedySolution(board, i, j);
      }

      for(int num = 1; num <= 9; ++num){
        if(rowSet[i].count(num) == 0 && colSet[j].count(num) == 0 && subSet[i / 3 + (j / 3) * 3].count(num) == 0){
          
          vector<vector<char>> old_board = board;//record old board
          board[i][j] = '0' + num;//update board

          //update sets
          rowSet[i].insert(num);
          colSet[j].insert(num);
          subSet[i / 3 + (j / 3) * 3].insert(num);
          
          if(i == 0 && j == 5){
          cout << "-------------row modified" << endl;
          for(int i = 0; i < rowSet.size(); ++i){
            set<char> rowSet_i = rowSet[i];
            for(auto j = rowSet_i.begin(); j != rowSet_i.end(); ++j){
              cout << *j << " ";
            }
            cout << endl;
          }}

          int old_i = i, old_j = j;//record old i and j       
          i = (j + 1 == 9) ? i + 1 : i;//update i and j
          j = (j + 1) % 9;

          if(greedySolution(board, i, j)){//update board
            return true;
          }
          else{
            board = old_board;
            i = old_i;
            j = old_j;
            rowSet[i].erase(num);

            if(i == 0 && j == 5){
            cout << "-------------row back" << endl;
            for(int i = 0; i < rowSet.size(); ++i){
              set<char> rowSet_i = rowSet[i];
              for(auto j = rowSet_i.begin(); j != rowSet_i.end(); ++j){
                cout << *j << " ";
              }
              cout << endl;
            }}

            colSet[j].erase(num);
            subSet[i / 3 + (j / 3) * 3].erase(num);
          }
        }
      }
      return false;
    }

    bool RowSetFunc(vector<vector<char>>& board, SetFuncType type){
    	for(int i = 0; i < 9; ++i){
    		set<char> mySet;
    		for(int j = 0; j < 9; ++j){
    			if(board[i][j] == '.') continue;
    			if(mySet.count(board[i][j]) == 1) return false;
    			mySet.insert(board[i][j]);
    		}
        if(type == 0)
          rowSet.push_back(mySet);
    	}
    	return true;
    }

    bool ColumnSetFunc(vector<vector<char>>& board, SetFuncType type){
    	for(int j = 0; j < 9; ++j){
    		set<char> mySet;
    		for(int i = 0; i < 9; ++i){
    			if(board[i][j] == '.') continue;
    			if(mySet.count(board[i][j]) == 1) return false;
    			mySet.insert(board[i][j]);
    		}
    		if(type == 0)
            colSet.push_back(mySet);
    	}
    	return true;
    }

    bool SubSetFunc(vector<vector<char>>& board, SetFuncType type){
    	for(int i = 0; i < 3; ++i){
    		for(int j = 0; j < 3; ++j){
    			set<char> mySet;
    			for(int m = 0; m < 3; ++m){
    				for(int n = 0; n < 3; ++n){
    					if(board[m + 3 * i][n + 3 * j] == '.') continue;
    					if(mySet.count(board[m + 3 * i][n + 3 * j]) == 1) return false;
    					mySet.insert(board[m + 3 * i][n + 3 * j]);
    				}
    			}
          if(type == 0)
            subSet.push_back(mySet);
    		}
    	}
    	return true;
    }
private:
    vector<set<char>> rowSet;
    vector<set<char>> colSet;
    vector<set<char>> subSet;
};

int main(){
	Solution sol;
	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','.'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

  sol.solveSudoku(board);

	for(int i = 0; i < 9; ++i){
    for(int j = 0; j < 9; ++j)
     ;// cout << board[i][j] << "  ";
    cout << endl;
  }

  return 0;
    
}