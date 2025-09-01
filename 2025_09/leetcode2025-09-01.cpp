#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i=0; i<classes.size(); i++){
            auto c = classes[i];
            double a = 1.0*c[0], b = 1.0*c[1];
            pq.push(make_pair((a+1)/(b+1)-a/b, i));
        }
        while (extraStudents){
            pair<double, int> p = pq.top();
            pq.pop();
            int indx = p.second;
            classes[indx][0]++;
            classes[indx][1]++;
            double a = 1.0*classes[indx][0], b = 1.0*classes[indx][1];
            pq.push(make_pair((a+1)/(b+1)-a/b, indx));
            extraStudents--;
        }
        double res = 0;
        for (int i=0; i<classes.size(); i++){
            res += 1.0*classes[i][0]/classes[i][1];
        }
        return res/classes.size();
    }
};

int main(){
    Solution s;
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    cout << s.maxAverageRatio(classes, extraStudents) << endl;
}
