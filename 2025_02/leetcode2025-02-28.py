from typing import List
from sortedcontainers import SortedList
from collections import defaultdict

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.foodInfo = dict()
        self.cTot = defaultdict(SortedList)
        n = len(foods)
        for i in range(n):
            self.foodInfo[foods[i]] = [cuisines[i], ratings[i]]
            self.cTot[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        tmpCuisine, tmpRating = self.foodInfo[food]
        self.cTot[tmpCuisine].discard((-tmpRating, food))
        self.cTot[tmpCuisine].add((-newRating, food))
        self.foodInfo[food][1] = newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cTot[cuisine][0][1]

if __name__ == "__main__":
    foods = ["kimchi","miso","sushi","moussaka","ramen","bulgogi"]
    cuisines = ["korean","japanese","japanese","greek","japanese","korean"]
    ratings = [9,12,8,15,14,7]
    fr = FoodRatings(foods, cuisines, ratings)
    op = ["highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]
    cr = [["sushi",16],["ramen",16]]
    hr = ["korean","japanese","japanese","japanese"]
    c,h = 0, 0
    for o in op:
        if o == "changeRating":
            fr.changeRating(cr[c][0], cr[c][1])
            c += 1
        else:
            print(fr.highestRated(hr[h]))
            h += 1
