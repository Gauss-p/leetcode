#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    bool is_equal(string a, string b){
        if (a.size() != b.size()){
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> res = {words[0]};
        for (int i=1; i<n; i++){
            if (!is_equal(words[i], words[i-1])){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    vector<string> res = s.removeAnagrams(words);
    for (string& i : res){
        cout << i << " ";
    }
    cout << endl;
}
