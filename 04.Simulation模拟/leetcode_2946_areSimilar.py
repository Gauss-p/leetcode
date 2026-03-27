from typing import List

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        return all(row[k%len(mat[0]):]+row[:k%len(mat[0])] == row for row in mat)

if __name__ == "__main__":
    s = Solution()
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    k = 4
    print(s.areSimilar(mat, k))
