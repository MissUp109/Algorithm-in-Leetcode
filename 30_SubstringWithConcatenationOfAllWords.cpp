#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	std::vector<int> ret;
        if(words.size() == 0) return ret; 

    	int wlen = words[0].length();
        int totalLen = wlen * words.size();
        if(s.length() < totalLen) return ret;

        set<string> table;
        for(int i = 0; i < words.size(); ++i)
            table.insert(words[i]);

        string tmpRet = ""; int tmp = 0;
        for(int i = 0; i < s.size(); i = i + wlen){
            if(i + wlen > s.size()) break;

            string sub = s.substr(i, wlen);
            if(table.count(sub) == 1){ // sub is included in words
                size_t found = tmpRet.find(sub); // first position of sub in tmpRet
                if(found == std::string::npos){ // sub hasn't been used in tmpRet
                    if(tmpRet.length() == 0){
                        tmp = i;
                    }
                    tmpRet += sub;
                    if(tmpRet.length() == totalLen){
                        ret.push_back(tmp);
                        tmp = i + wlen;
                        tmpRet = "";
                    }
                }
                else{ // sub has already been used in tmpRet
                    tmpRet = tmpRet.substr((int)found + wlen);
                    tmp = tmp + ((int)found / wlen + 1);
                    tmpRet += sub;
                }
            }
            else{ // sub isn't included in words
                tmp = i + wlen;
                tmpRet = "";
            }
        }
        return ret;
    }
};

/*
"barfoofoobarthefoobarman"
["bar","foo","the"]

Expect: [6,9,12]
*/

int main(){
	Solution sol;
	vector<string> words = {"word", "student"};
	vector<int> ret = sol.findSubstring("wordgoodstudentgoodword", words);
	for(auto itr = ret.begin(); itr != ret.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
}