#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int positive = 0, total = 0;
        int n = distance.size();
        if (start > destination){
            swap(start, destination);
        }
        for (int i=0; i<n; i++){
            if (i>=start && i<destination){
                positive += distance[i];
            }
            total += distance[i];
        }
        return min(positive, total-positive);
    }
};

int main(){
    Solution s;
    vector<int> distance = {7,10,1,12,11,14,5,0};
    int start = 7, destination = 2;
    cout << s.distanceBetweenBusStops(distance, start, destination) << endl;
}
