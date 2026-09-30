#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt = 0;
        vector<int> res;
        for (auto& c : seq){
            if (c == '('){
                cnt++;
                res.push_back(cnt%2);
            }
            else{
                res.push_back(cnt%2);
                cnt--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string seq = "(()())";
    vector<int> res = s.maxDepthAfterSplit(seq);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
