#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    void genPermutations(string base, int length, string cur, vector<string>& permutations){
        if (cur.size() == length){
            // 累加到了length的长度，就加入答案
            permutations.push_back(cur);
            return;
        }
        for (int i=0; i<base.size(); i++){
            if (i>0 && base[i]==base[i-1]){
                // 去重，每一个字符在每一个位置只加一遍
                continue;
            }
            genPermutations(base.substr(0, i)+base.substr(i+1), length, cur+base[i], permutations); // 递归
        }
    }

    bool isSubSeries(string& s, string& candidate, int k){
        string newS;
        for (int i=0; i<k; i++){
            newS += candidate;
        }
        int i = 0, j = 0; // 双指针手动判断k个candidate是否是s的子序列
        while (i<s.size() && j<newS.size()){
            if (s[i] == newS[j]){
                j++;
            }
            i++;
        }
        return j==newS.size();
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        // 这里面我们需要用递归来实现生成所有排列的功能，并手写一个判断子序列的函数
        unordered_map<char, int> mp; // 统计频次
        for (char c : s){
            mp[c]++;
        }
        
        vector<char> keys; // 排序
        for (auto&kv : mp){
            keys.push_back(kv.first);
        }
        
        sort(keys.rbegin(), keys.rend());
        string base; // 创建基字符串
        for (char key : keys){
            base.append(string(mp[key]/k, key));
        }
        
        for (int length=base.size(); length>0; length--){
            vector<string> permutations;
            genPermutations(base, length, "", permutations); // 生成所有的长度为length的答案子序列
            for (auto& candidate : permutations){
                if (isSubSeries(s, candidate, k)){ // 判断是否为s的子序列
                    return candidate;
                }
            }
        }
        
        return "";
    }
};

int main(){
    Solution sl;
    string s = "letsleetcode";
    int k = 2;
    cout << sl.longestSubsequenceRepeatedK(s, k) << endl;
}
