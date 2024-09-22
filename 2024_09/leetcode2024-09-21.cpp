#include <iostream>
#include <vector>

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n);
        for (int i=0; i<n; i++){
            score[edges[i]] += i;
        }
        long long mx = 0;
        int res = 0;
        for (int i=0; i<n; i++){
            if (score[i] > mx){
                res = i;
                mx = score[i];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> edges = {1,0,0,0,0,7,7,5};
    cout << s.edgeScore(edges) << endl;
}
