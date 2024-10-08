#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> st;
        for (auto i : paths){
            st.insert(i[0]);
        }
        for (auto i : paths){
            if (st.count(i[1]) == 0){
                return i[1];
            }
        }
        return "";
    }
};

int main(){
    Solution s;
    vector<vector<string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    cout << s.destCity(paths) << endl;
}
