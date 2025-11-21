#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> l(26, -1), r(26, -1);
        for (int i=0; i<n; i++){
            int indx = s[i]-'a';
            if (l[indx] == -1){
                l[indx] = i;
            }
            r[indx] = i;
        }

        int res = 0;
        for (int i=0; i<26; i++){
            int curL = l[i], curR = r[i];
            if (curL==-1 || curL+1 >= curR){
                continue;
            }
            set<char> st;
            for (int j=curL+1; j<curR; j++){
                st.insert(s[j]);
            }
            res += st.size();
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aabca";
    cout << sl.countPalindromicSubsequence(s) << endl;
}
