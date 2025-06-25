#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 避雷：c++ 中的除法有问题，-9/2在python3中答案是-5，而在c++ 中是-4!

class Solution {
private:
    vector<int> n1, n2;

    // long long check(long long v){
    //     long long cnt = 0;
    //     for (long long x : n1){
    //         int left = 0, right = n2.size()-1;
    //         while (left <= right){
    //             int mid = (left+right)/2;
    //             if ((x>=0 && n2[mid]*x<=v) || (x<0 && n2[mid]*x>v)){
    //                 left = mid+1;
    //             }
    //             else{
    //                 right = mid-1;
    //             }
    //         }
    //         if (x>=0){
    //             cnt += left;
    //         }
    //         else{
    //             cnt += n2.size()-left;
    //         }
    //     }
    //     return cnt;
    // }

    long long check(long long x){
        long long cnt = 0;
        for (long long i : n1){
            if (i > 0){
                // long long j = x/i;
                long long j = ceil((x+1)*1.0/i);
                long long indx = lower_bound(n2.begin(), n2.end(), j)-n2.begin();
                cnt += indx;
            }
            else if (i == 0){
                if (x >= 0){
                    cnt += n2.size();
                }
            }
            else{
                // long long j = -(x/(-i));
                long long j = ceil(x*1.0/i);
                long long indx = lower_bound(n2.begin(), n2.end(), j)-n2.begin();
                cnt += n2.size()-indx;
            }
        }
        return cnt;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        n1 = nums1;
        n2 = nums2;
        long long l = -1e10, r = 1e10;
        while (l<=r){
            long long mid = (l+r)>>1;
            long long cur = check(mid);
            if (cur < k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2,5}, nums2 = {3,4};
    int k = 2;
    cout << s.kthSmallestProduct(nums1, nums2, k) << endl;
}
