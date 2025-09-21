#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <tuple>
using namespace std;

struct HashTuple{
    size_t operator() (const tuple<int, int>& x) const{
        auto [a, b] = x;
        return hash<int>()(a) ^ hash<int>()(b);
    }
};

class MovieRentingSystem {
private:
    unordered_map<tuple<int, int>, int, HashTuple> total_movies;
    unordered_map<int, set<pair<int, int>>> movie_details;
    set<tuple<int, int, int>> out_movies;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries){
            int s=e[0], m=e[1], p=e[2];
            total_movies[make_tuple(s, m)] = p;
            movie_details[m].insert(make_pair(p, s));
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto it = movie_details[movie].begin();
        for (int i=0; i<5 && it!=movie_details[movie].end(); i++, it++){
            res.push_back(it->second);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = total_movies[make_tuple(shop, movie)];
        out_movies.insert(make_tuple(price, shop, movie));
        movie_details[movie].erase(make_pair(price, shop));
    }
    
    void drop(int shop, int movie) {
        int price = total_movies[make_tuple(shop, movie)];
        out_movies.erase(make_tuple(price, shop, movie));
        movie_details[movie].insert(make_pair(price, shop));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        auto it = out_movies.begin();
        for (int i=0; i<5 && it!=out_movies.end(); i++, it++){
            auto [p, s, m] = *it;
            res.push_back({s, m});
        }
        return res;
    }
};

int main(){
    int tot = 3;
    vector<vector<int>> entries = {{0,1,5},{0,2,6},{0,3,7},{1,1,4},{1,2,7},{2,1,5}};
    MovieRentingSystem mrs(tot, entries);
    vector<string> op = {"search","rent","rent","report","drop","search"};
    vector<vector<int>> num = {{1},{0,1},{1,2},{},{1,2},{2}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "search"){
            vector<int> cur = mrs.search(num[i][0]);
            for (auto& i : cur){
                cout << i << " ";
            }
            cout << endl;
        }
        if (op[i] == "rent"){
            mrs.rent(num[i][0], num[i][1]);
        }
        if (op[i] == "drop"){
            mrs.rent(num[i][0], num[i][1]);
        }
        if (op[i] == "report"){
            vector<vector<int>> cur = mrs.report();
            for (vector<int> i : cur){
                for (int j : i){
                    cout << j << " ";
                }
                cout << ",";
            }
            cout << endl;
        }
    }
}
