#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int i=0; i<=n/2; i++){
            if (words[(startIndex-i+n)%n] == target || words[(startIndex+i)%n] == target){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;
    cout << s.closestTarget(words, target, startIndex) << endl;
}
