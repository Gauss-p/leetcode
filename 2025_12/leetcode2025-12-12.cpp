#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return (stoi(a[1]) < stoi(b[1])) || (stoi(a[1]) == stoi(b[1]) && a[0]=="OFFLINE" && b[0]=="MESSAGE");
        });
        vector<int> mentions(numberOfUsers, 0);
        vector<int> curOnline(numberOfUsers, 1);
        vector<pair<int, int>> willOnline;
        for (auto& e : events){
            string op = e[0], mStr = e[2];
            int timeStamp = stoi(e[1]);
            while (!willOnline.empty() && willOnline[0].first <= timeStamp){
                curOnline[willOnline[0].second] = 1;
                willOnline.erase(willOnline.begin());
            }
            if (op == "MESSAGE"){
                if (mStr == "ALL"){
                    for (int i=0; i<numberOfUsers; i++){
                        mentions[i]++;
                    }
                }
                else if (mStr == "HERE"){
                    for (int i=0; i<numberOfUsers; i++){
                        if (curOnline[i]){
                            mentions[i]++;
                        }
                    }
                }
                else{
                    mStr += ' ';
                    int last = 0;
                    for (int i=0; i<mStr.size(); i++){
                        if (mStr[i] == ' '){
                            int curIndx = stoi(mStr.substr(last+2, i-last-2));
                            mentions[curIndx]++;
                            last = i+1;
                        }
                    }
                }
            }
            else{
                curOnline[stoi(mStr)] = 0;
                willOnline.emplace_back(timeStamp+60, stoi(mStr));
            }
        }
        return mentions;
    }
};

int main(){
    Solution s;
    int numberOfUsers = 2;
    vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
    vector<int> res = s.countMentions(numberOfUsers, events);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
