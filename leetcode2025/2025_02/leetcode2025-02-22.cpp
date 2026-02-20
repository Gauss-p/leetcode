#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector<int> tmpSet;
        for (string& i : words){
            int tmp = 0;
            for (char& j : i){
                tmp |= (1<<(j-'a'));
            }
            tmpSet.push_back(tmp);
        }
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (tmpSet[i] == tmpSet[j]){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words = {"aba","aabb","abcd","bac","aabc"};
    cout << s.similarPairs(words) << endl;
}
