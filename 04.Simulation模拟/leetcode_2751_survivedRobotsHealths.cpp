#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indexs;
        for (int i=0; i<n; i++){
            indexs.push_back(i);
        }
        sort(indexs.begin(), indexs.end(), [&](int& a, int& b){
            return positions[a]<positions[b];
        });

        stack<int> st;
        for (int& i : indexs){
            if (directions[i] == 'R'){
                st.push(i);
                continue;
            }
            while (!st.empty()){
                int j = st.top();
                if (healths[i] < healths[j]){
                    healths[i] = 0;
                    healths[j] -= 1;
                    break;
                }
                if (healths[i] == healths[j]){
                    healths[i] = 0;
                    healths[j] = 0;
                    st.pop();
                    break;
                }
                healths[i] -= 1;
                healths[j] = 0;
                st.pop();
            }
        }
        vector<int> res;
        for (int i : healths){
            if (i>0){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> positions = {5,4,3,2,1}, healths = {2,17,9,15,10};
    string directions = "RRRRR";
    vector<int> res = s.survivedRobotsHealths(positions, healths, directions);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
