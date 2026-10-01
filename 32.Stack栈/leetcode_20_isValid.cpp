#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        unordered_map<char, char> mp = {{')','('}, {'}','{'}, {']','['}};
        for (auto& c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push_back(c);
            }
            else{
                if (st.size() && st.back() == mp[c]){
                    st.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};

int main(){
    Solution sl;
    string s = "()";
    cout << sl.isValid(s) << endl;
}
