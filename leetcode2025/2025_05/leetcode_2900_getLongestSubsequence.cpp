#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        int last = groups[0];
        vector<string> res = {words[0]};
        for (int i=1; i<n; i++){
            if (last != groups[i]){
                last = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"c","a"};
    vector<int> groups = {0,1};
    vector<string> res = s.getLongestSubsequence(words, groups);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
