#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
private:
    int n;
    string Word;
    vector<vector<int>> pos;
    unordered_map<int, int> memo;
    int dfs(int finger1, int finger2, int indx){
        if (indx == n){
            return 0;
        }
        int key = finger1<<20 | finger2<<10 | indx;
        if (memo.count(key)){
            return memo[key];
        }
        int cur = Word[indx]-'A';
        int dis1 = finger1<0 ? 0 : abs(pos[finger1][0]-pos[cur][0])+abs(pos[finger1][1]-pos[cur][1]);
        int dis2 = finger2<0 ? 0 : abs(pos[finger2][0]-pos[cur][0])+abs(pos[finger2][1]-pos[cur][1]);
        int ans = INT_MAX;
        ans = min(ans, dis1+dfs(cur, finger2, indx+1));
        ans = min(ans, dis2+dfs(finger1, cur, indx+1));
        memo[key] = ans;
        return ans;
    }
public:
    int minimumDistance(string word) {
        Word = word;
        n = word.size();
        for (int i=0; i<26; i++){
            pos.push_back({i/6, i%6});
        }
        return dfs(-1, -1, 0);
    }
};

int main(){
    Solution s;
    string word = "CAKE";
    cout << s.minimumDistance(word) << endl;
}
