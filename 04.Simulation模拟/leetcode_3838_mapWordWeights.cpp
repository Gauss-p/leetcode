#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (auto& w : words){
            int cur = 0;
            for (auto& c : w){
                cur = (cur+weights[c-'a'])%26;
            }
            res += ('z'-cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    cout << s.mapWordWeights(words, weights) << endl;
}
