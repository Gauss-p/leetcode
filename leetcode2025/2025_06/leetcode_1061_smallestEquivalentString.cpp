#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, char> pa;

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if (px > py){
            pa[px] = py;
        }
        else{
            pa[py] = px;
        }
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i=0; i<26; i++){
            pa['a'+i] = 'a'+i;
        }

        for (int i=0; i<s1.size(); i++){
            merge(s1[i], s2[i]);
        }

        string res;
        for (char& c : baseStr){
            res += find(c);
        }
        return res;
    }
};

int main(){
    Solution s;
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    cout << s.smallestEquivalentString(s1, s2, baseStr) << endl;
}
