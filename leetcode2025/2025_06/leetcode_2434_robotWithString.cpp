#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> back_min(n+1, 'z');
        for (int i=n-1; i>=0; i--){
            back_min[i] = min(back_min[i+1], s[i]);
        }

        string res;
        stack<char> st;
        for (int i=0; i<n; i++){
            st.push(s[i]);
            while (!st.empty() && st.top()<= back_min[i+1]){
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "bac";
    cout << sl.robotWithString(s) << endl;
}
