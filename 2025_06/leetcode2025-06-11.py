class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        # 读题可知，题目中给出的s其实只包含五个数字，0，1，2，3，4，所以我们可以两两计算，取出其中两个数字x,y，计算子数组中x出现奇数次，y出现偶数次时，x的出现次数和y出现次数的最大差值
        # 定义前缀和数组preSum，其中preSum[i][a]表示数字a在s[:i+1]中出现的次数，那么对于一个子数组[l,r)和给定的两个数字x,y，我们需要计算的就是(preSum[r][x]-preSum[l][x])-(preSum[r][y]-preSum[l][y])，我们暂时先不考虑x的出现次数和y出现次数的奇偶性问题，那么本质上我们要求的差值就是上边这个式子，将其交换一下，可以得到这样的式子：
        # (preSum[r][x]-preSum[r][y])-(preSum[l][x]-preSum[l][y])，记这个式子为(*)式
        # 那么也就意味着对于每一个位置，我们只需要计算出当前位置的preSum[i][x]-preSum[i][y]即可，这样对于r和l都只需要计算出这个式子的值并求差
        # 但是这时我们需要考虑题目要求的子数组中x出现奇数次，y出现偶数次，那么也就是说对于当前位置(我们将当前位置看作是子数组的右端点r)r，我们需要的左端点l要满足的条件就是preSum[l][x]和preSum[r][x]出现次数的奇偶性不同，preSum[l][y]和preSum[r][y]出现次数的奇偶性相同
        # 所以我们就可以根据preSum[r][x]的奇偶性和preSum[r][y]的奇偶性来确定l的信息，记preSum[r][x]%2的值为p，preSum[r][y]%2的值为q，那么l就需要满足:preSum[l][x]%2=p-1，且preSum[l][y]%2=q
        # 如果我们要直接再次循环r之前的所有值来寻找满足条件的l，就会浪费之前循环到的所有小于r的位置，因为我们是从前往后循环r的，那么一定将所有可能的l都计算过一遍了，这时我们需要将l的信息保存下来，因为p和q都会有两种情况，都是0和1，所以我们可以用p和q作为索引，创建一个2×2的列表minV，保存所有的l的信息，即，如果preSum[l][x]%2=a, preSum[l][y]%2=b，那么就在minV[a][b]中保存preSum[l][x]-preSum[l][y]的值，并且因为在这之后我们是要将这个值减去的，所以我们需要取minV[a][b]和preSum[l][x]-preSum[l][y]的最小值，只有这样才能在之后的减法运算中让子数组中x和y的出现次数的差值更大
        # 因为我们是将右端点r从左向右遍历的，所以在每一次循环的时候就将这个r当作之后的左端点保存其信息。而在计算以r为右端点的子数组中x和y的出现次数最大差值时，就可以先取出preSum[r][x]的奇偶性rp和preSum[r][y]的奇偶性rq，那么根据题目可以知道，preSum[l][x]的奇偶性应为rp^1，preSum[l][y]的奇偶性应为rq，所以答案就是preSum[r][x]-preSum[r][y]-minV[rp^1][rq]，那么每一次记录一下答案的最大值即可
        myMax = lambda x,y : x if x>y else y
        myMin = lambda x,y : x if x<y else y

        nums = list(map(int, s))
        res = -float("inf")
        n = len(nums)
        for x in range(5):
            # 一共只有5个数字，循环所有的情况进行计算即可
            for y in range(5):
                if x == y:
                    continue
                
                right_preSum = [0]*5 # 相当于preSum[r]
                left_preSum = [0]*5 # 相当于preSum[l]
                left = 0 # 左端点位置
                minV = [[float("inf"), float("inf")] for _ in range(2)]
                for right in range(1, n+1):
                    # 先统计preSum[r]的值
                    right_preSum[nums[right-1]] += 1
                    # 滑动窗口控制子数组的长度不小于k
                    while right-left >= k and right_preSum[x]>left_preSum[x] and right_preSum[y]>left_preSum[y]:
                        p, q = left_preSum[x]&1, left_preSum[y]&1
                        minV[p][q] = myMin(minV[p][q], left_preSum[x]-left_preSum[y]) # 记录左端点的信息
                        left_preSum[nums[left]] += 1 # 每次l滑出窗口就将它统计入preSum[l]中
                        left += 1
                    
                    if right >= k:
                        # 只有right>=k的时候才能保证子数组的长度能够超过k
                        rp, rq = right_preSum[x]&1^1, right_preSum[y]&1 # 计算对应preSum[l]中x,y出现次数的奇偶性
                        res = myMax(res, right_preSum[x]-right_preSum[y]-minV[rp][rq]) # 记录答案
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "12233"
    k = 4
    print(sl.maxDifference(s, k))
