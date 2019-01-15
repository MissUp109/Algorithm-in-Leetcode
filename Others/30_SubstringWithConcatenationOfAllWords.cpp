#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

//Approach 1
//Runtime: 492 ms, faster than 11.92% of C++ online submissions
/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return {}; 

        int wlen = words[0].length();
        int wNum = words.size();
        if(s.length() < wlen * wNum) return {};

        vector<int> ret;
        unordered_map<string, int> table;
        for(auto& w: words) ++table[w];
       
        for(int i = 0; i < wlen; ++i){
            int tmp = i, num = 0;
            unordered_map<string, int> tmpTable = table;
            for(int j = i; j <= s.size() - wlen; ){
                string sub = s.substr(j, wlen);
                if(tmpTable.count(sub) == 1 && --tmpTable[sub] >= 0){
                    if(num == 0) tmp = j;
                    ++num;
                    if(num == wNum){
                        ret.push_back(tmp); 
                        tmpTable = table; num = 0;
                        tmp += wlen;
                        j = tmp;
                    }
                    else j = j + wlen;   
                }
                else{
                    tmpTable = table; num = 0;
                    tmp += wlen;
                    j = tmp;
                }
            }
        }
        return ret;
    }
};
*/

//Approach 2
//Runtime: 20 ms, faster than 84.25% of C++ online submissions
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return {}; 

        int wlen = words[0].size();
        int wNum = words.size();
        int len = s.size();
        if(len < wlen * wNum) return {};

        vector<int> ret;
        unordered_map<string, int> table, tmpTable;
        for(auto& w: words) ++table[w];
       
        for(int i = 0; i < wlen; ++i){
            int tmp = i, num = 0;
            tmpTable.clear();
            for(int j = i; j <= s.length() - wlen;){ 
                string sub = s.substr(j, wlen);
                auto itr = table.find(sub);
                if(itr == table.end()){
                    tmpTable.clear(); num = 0;
                    j += wlen;
                    tmp = j;  
                    continue;
                }
                else if(tmpTable[sub] == itr->second){
                    string f;
                    while((f = s.substr(tmp, wlen)) != sub){
                        --tmpTable[f]; --num;
                        tmp += wlen;
                    }
                    tmp += wlen;
                    j += wlen;
                }
                else{
                    ++tmpTable[sub]; 
                    ++num;
                    j += wlen;
                }
                if(num == wNum) ret.push_back(tmp);
            }
        }
        return ret;
    }
};

/* Test Input-Output
  s = "barfoothefoobarman",
  words = ["foo","bar"]
  Expect: [0,9]

  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
  Expect: []

  s = "barfoofoobarthefoobarman"
  words = ["bar","foo","the"]
  Expect: [6,9,12]

  s = "ababaab"
  words = ["ab","ba","ba"]
  Expect: [1]

  s = "aaa"
  words = ["a","a"]
  Expect: [0, 1]

  s = "lingmindraboofooowingdingbarrwingmonkeypoundcake"
  words = ["fooo","barr","wing","ding","wing"]
  Expect: [13]
*/

int main(){
    Solution sol;
    vector<string> words = {"ab","ba","ba"};
    vector<int> ret = sol.findSubstring("ababaab", words);
    for(auto itr = ret.begin(); itr != ret.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    
}