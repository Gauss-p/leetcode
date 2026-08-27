#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<int, int> left;
        for (auto& c : s){
            left[c]++;
        }
        for (auto& c : target){
            left[c]--;
        }

        for (int i=s.size()-1; i>=0; i--){
            left[target[i]] += 1;
            bool flag = true;
            for (auto& kv : left){
                if (kv.second < 0){
                    flag = false;
                }
            }
            if (!flag){
                continue;
            }

            for (char c=target[i]+1; c<='z'; c++){
                if (left[c] == 0){
                    continue;
                }

                left[c] -= 1;
                string res = target.substr(0, i);
                res += c;

                for (char cur='a'; cur<='z'; cur++){
                    if (left[cur] > 0){
                        res += string(left[cur], cur);
                    }
                }
                return res;
            }
        }
        return "";
    }
};

int main(){
    Solution sl;
    string s = "abc", target = "bba";
    cout << sl.lexGreaterPermutation(s, target) << endl;
}
