#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (string s : queries){
            bool flag = false;
            for (string d : dictionary){
                if (s.size() != d.size()){
                    continue;
                }
                int cnt = 0;
                for (int i=0; i<s.size(); i++){
                    if (s[i] != d[i]){
                        cnt++;
                    }
                }
                if (cnt <= 2){
                    flag = true;
                    break;
                }
            }
            if (flag){
                res.push_back(s);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> queries = {"word","note","ants","wood"}, dictionary = {"wood","joke","moat"};
    vector<string> res = s.twoEditWords(queries, dictionary);
    for (auto& s : res){
        cout << s << " ";
    }
    cout << endl;
}
