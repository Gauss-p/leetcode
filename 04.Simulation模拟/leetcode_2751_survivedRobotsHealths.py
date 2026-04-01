from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        indexs = sorted(range(n), key = lambda i:positions[i])
        # 用索引数组可以在不改变原数组的情况下按照位置从小到大循环
        
        st = []
        for i in indexs:
            if directions[i] == 'R':
                st.append(i)
                continue

            while st:
                # 直接模拟三种情况
                j = st[-1]
                if healths[i] < healths[j]:
                    healths[i] = 0
                    healths[j] -= 1
                    break
                if healths[i] == healths[j]:
                    healths[i] = 0
                    healths[j] = 0
                    st.pop()
                    break
                healths[i] -= 1
                healths[j] = 0
                st.pop()
        
        res = []
        for i in healths:
            if i>0:
                res.append(i)
        return res

if __name__ == "__main__":
    s = Solution()
    positions = [5,4,3,2,1]
    healths = [2,17,9,15,10]
    directions = "RRRRR"
    print(s.survivedRobotsHealths(positions, healths, directions))
