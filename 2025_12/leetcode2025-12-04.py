class Solution:
    def countCollisions(self, directions: str) -> int:
        # 最左边的所有向左移动的车辆不会发生任何碰撞，最右边的所有向右移动的车辆不会发生任何碰撞，因此我们可以先去除directions左边所有为'L'的值以及右边所有为'R'的值
        # 剩余的所有车辆，只要移动就一定会发生一次碰撞，但是注意静止的车辆不会发生任何碰撞，因此碰撞总次数就是剩余的车辆总数量减去静止的车辆总数即可
        directions = directions.lstrip('L')
        directions = directions.rstrip('R')
        return len(directions)-directions.count('S')

if __name__ == "__main__":
    s = Solution()
    directions = "RLRSLL"
    print(s.countCollisions(directions))
