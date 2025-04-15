#include <iostream>
#include <vector>
using namespace std;

template<typename T>

class TreeArray{
private:
    vector<int> tree;

public:
    TreeArray(int n){
        tree.resize(n+1, 0);
    }

    void update(int pos, T val){
        while (pos<(int)tree.size()){
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

    T preSum(int pos){
        T res = 0;
        while (pos>0){
            res += tree[pos];
            pos -= (pos & -pos);
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> funx(n, 0);
        for (int i=0; i<n; i++){
            funx[nums1[i]] = i;
        }
    
        long long res = 0;
        // vector<int> st(n+1, 0);
        TreeArray<int> st(n);
        for (int i=0; i<n; i++){
            int v = nums2[i];
            int y = funx[v];
            // int less = accumulate(st.begin(), st.begin()+y+1, 0);
            int less = st.preSum(y);
            res += 1ll*less*(n-1-y-(i-less));
            // st[y+1] = 1;
            st.update(y+1, 1);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2,0,1,3};
    vector<int> nums2 = {0,1,2,3};
    cout << s.goodTriplets(nums1, nums2) << endl;
}
