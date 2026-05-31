from typing import List

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for i in range(len(asteroids)):
            if mass < asteroids[i]:
                return False
            mass += asteroids[i]
        return True

if __name__ == "__main__":
    s = Solution()
    mass = 10
    asteroids = [3,9,19,5,21]
    print(s.asteroidsDestroyed(mass, asteroids))
