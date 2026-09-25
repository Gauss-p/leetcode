#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
private:
    set<string> st;

    void dfs(string exp){
        int right = exp.find_first_of('}');
        if (right == string::npos){
            st.insert(exp);
            return;
        }
        int left = right-1;
        while (exp[left]!='{'){
            left--;
        }
        string a = exp.substr(0, left), c = exp.substr(right+1);
        string b = exp.substr(left+1, right-left-1);
        b += ',';
        string cur;
        for (char tmp : b){
            if (tmp != ','){
                cur += tmp;
            }
            else{
                dfs(a+cur+c);
                cur = "";
            }
        }
    }
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(st.begin(), st.end());
    }
};

int main(){
    Solution s;
    string expression = "{a,b}{c,{d,e}}";
    vector<string> res = s.braceExpansionII(expression);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
