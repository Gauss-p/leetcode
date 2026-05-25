#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] == '1'){
            return false;
        }
        vector<int> pos;
        for (int i=0; i<n; i++){
            if (s[i] == '0'){
                pos.push_back(i);
            }
        }
        int begin = 0;
        vector<int> q = {0};
        while (!q.empty()){
            vector<int> q2;
            for (int i : q){
                if (i == n-1){
                    return true;
                }
                int j = lower_bound(pos.begin(), pos.end(), i+minJump)-pos.begin();
                j = max(j, begin);
                while (j<pos.size() && pos[j]-i >= minJump && pos[j]-i <= maxJump){
                    q2.push_back(pos[j]);
                    j++;
                }
                begin = j;
            }
            q = q2;
        }
        return false;
    }
};

int main(){
    Solution sl;
    string s = "011010";
    int minJump = 2, maxJump = 3;
    cout << sl.canReach(s, minJump, maxJump) << endl;
}
