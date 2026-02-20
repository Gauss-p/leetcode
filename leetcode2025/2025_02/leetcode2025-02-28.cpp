#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cTot;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i=0; i<n; i++){
            foodInfo[foods[i]] = make_pair(ratings[i], cuisines[i]);
            cTot[cuisines[i]].emplace(-ratings[i], foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        string tmpC = foodInfo[food].second;
        int tmpR = foodInfo[food].first;
        cTot[tmpC].erase(make_pair(-tmpR, food));
        cTot[tmpC].emplace(-newRating, food);
        foodInfo[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        return cTot[cuisine].begin()->second;
    }
};

int main(){
    vector<string> foods = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"korean","japanese","japanese","greek","japanese","korean"};
    vector<int> ratings = {9,12,8,15,14,7};
    FoodRatings fr(foods, cuisines, ratings);
    vector<string> op = {"highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"};
    vector<string> cr1 = {"sushi","ramen"};
    vector<int> cr2 = {16,16};
    vector<string> hr = {"korean","japanese","japanese","japanese"};
    int c=0, h=0;
    for (auto& o : op){
        if (o == "changeRating"){
            fr.changeRating(cr1[c],cr2[c]);
            c++;
        }
        else{
            cout << fr.highestRated(hr[h]) << endl;
            h++;
        }
    }
}
