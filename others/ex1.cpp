#include <iostream>
#include <vector>
#include <string>
using namespace std;

int f(string x, string y){
    int m = x.size();
    int n = y.size();
    vector<vector<int>> v(m+1, vector<int>(n+1, 0));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (x[i-1] == y[j-1]){
                v[i][j] = v[i-1][j-1]+1;
            }
            else{
                v[i][j] = max(v[i][j-1], v[i-1][j]);
            }
        }
    }
    for (auto i : v){
        for (auto j : i){
            cout << j << "  ";
        }
        cout << endl;
    }
    return v[m][n];
}

bool g(string x, string y){
    if (x.size() != y.size()){
        return false;
    }
    return f(x+x, y) == y.size();
}

int find_missing(vector<int> nums){
    int left = 0, right = nums.size()-1;
    while (left<right){
        int mid = left+(right-left)/2;
        if (nums[mid] == mid+nums[0]){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return nums[0]+left;
}

int main(){
    string x, y;
    //cin >> x >> y;
    //cout << g(x, y) << endl;
    vector<int> nums = {1,2,3};
    cout << find_missing(nums) << endl;
    return 0;
}
