#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i=0; i<words.size(); i++){
            if (count(words[i].begin(), words[i].end(), x)){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"leet", "code"};
    char x = 'e';
    vector<int> res = s.findWordsContaining(words, x);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
