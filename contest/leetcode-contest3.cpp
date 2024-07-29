#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int i=0; i<n; i++){
            vector<int> str_counter(26);
            int length = 0;
            for (int j=i; j<n; j++){
                str_counter[s[j]-'a']++;
                int maxest = *max_element(str_counter.begin(), str_counter.end());
                if (maxest > 2) break;
                length++;
            }
            res = max(res, length);
        }
        return res;
    }
};

class Solution2 {
public:
    int minOperations(int k) {
        int res = INT_MAX;
        for (int i=1; i<=k; i++){
            int copy_num = (k+i-1)/i-1;
            res = min(res, i-1+copy_num);
        }
        return res;
    }
};

class Solution3 {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<int, long long> cnt;
        multiset<long long> mst;
        vector<long long> res;
        for (int i=0; i<n; i++){
            int x = nums[i], y = freq[i];
            if (cnt.count(x)){
                mst.erase(mst.find(cnt[x]));
            }
            cnt[x] += y;
            mst.insert(cnt[x]);
            res.push_back(*mst.rbegin());
        }
        return res;
        // vector<long long> dic(1e5+1);
        // int n = nums.size();
        // vector<long long> res;
        // for (int i=0; i<n; i++){
        //     dic[nums[i]] += freq[i];
        //     res.push_back(*max_element(dic.begin(), dic.end()));
        // }
        // return res;
    }
};

int main(){
    Solution1 s1;
    string s = "bcbbbcba";
    cout << "s1 : " << s1.maximumLengthSubstring(s) << endl;
    // --------------------------------------------------------
    Solution2 s2;
    int k = 11;
    cout << "s2 : " << s2.minOperations(k) << endl;
    // --------------------------------------------------------
    Solution3 s3;
    vector<int> nums = {2,3,2,1};
    vector<int> freq = {3,2,-3,1};
    vector<long long> answer = s3.mostFrequentIDs(nums, freq);
    cout << "s3 : ";
    for (auto &i : answer) cout << i << " ";
}
