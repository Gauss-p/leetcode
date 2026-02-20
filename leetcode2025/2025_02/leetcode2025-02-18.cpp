#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(mp[value].begin(), mp[value].end(), left)-mp[value].begin();
        int r = upper_bound(mp[value].begin(), mp[value].end(), right)-mp[value].begin()-1;
        return r-l+1;
    }
};

int main(){
    vector<int> arr = {12,33,4,56,22,2,34,33,22,12,34,56};
    RangeFreqQuery rfq(arr);
    cout << rfq.query(1,2,4) << endl;
}
