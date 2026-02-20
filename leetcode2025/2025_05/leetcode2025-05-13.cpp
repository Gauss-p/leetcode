#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> cnt(26, 0);
        int n = s.size();
        for (int i=0; i<n; i++){
            cnt[s[i]-'a']++;
        }
        int modNum = 1e9+7;
        for (int i=0; i<t; i++){
            vector<long long> tmp(26, 0);
            for (int j=0; j<26; j++){
                if (cnt[j]){
                    if (j != 25){
                        tmp[j+1] = cnt[j]%modNum;
                    }
                    else{
                        tmp[0] = (tmp[0]+cnt[j])%modNum;
                        tmp[1] = (tmp[1]+cnt[j])%modNum;
                    }
                }
            }
            for (int j=0; j<26; j++){
                cnt[j] = tmp[j];
            }
        }
        long long res = 0;
        for (int i=0; i<26; i++){
            res = (res+cnt[i])%modNum;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abcyy";
    int t = 2;
    cout << sl.lengthAfterTransformations(s, t) << endl;
}
