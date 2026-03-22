class Solution:
    def countGoodSubarrays(self, nums: list[int]) -> int:
        n = len(nums)
        or_left = []
        def init():
            return -1
        last = defaultdict(init)
        res = 0
        for i in range(n):
            x = nums[i]
            last[x] = i
            for j in range(len(or_left)):
                or_left[j][0] |= x
            or_left.append([x, i])

            indx = 1
            for j in range(1, len(or_left)):
                if or_left[j][0] != or_left[j-1][0]:
                    or_left[indx] = or_left[j]
                    indx += 1
            del or_left[indx:]

            for k in range(len(or_left)):
                orVal, low = or_left[k]
                high = or_left[k+1][1]-1 if k+1<len(or_left) else i
                lastOr = last[orVal]
                if lastOr >= low:
                    res += (min(high, lastOr)-low+1)
        return res
                

        # n = len(nums)
        # st = []
        # right = [0]*n
        # for i in range(n):
        #     j = 0
        #     while j<len(st):
        #         indx = st[j]
        #         if (nums[indx] | nums[i]) != nums[indx]:
        #             right[indx] = i-indx
        #             st.pop(j)
        #         else:
        #             j += 1

        #     st.append(i)
        # for indx in st:
        #     right[indx] = n-indx

        # st = []
        # left = [0]*n
        # for i in range(n-1, -1, -1):
        #     j = 0
        #     while j<len(st):
        #         indx = st[j]
        #         if (nums[indx] | nums[i]) != nums[indx]:
        #             left[indx] = indx-i
        #             st.pop(j)
        #         else:
        #             j += 1

        #     st.append(i)
        # for indx in st:
        #     left[indx] = indx+1

        # res = 0
        # for i in range(n):
        #     res += right[i]*left[i]
            
            
        # nums.append(-1)
        # last = 0
        # for i in range(1, n+1):
        #     if nums[i] != nums[i-1]:
        #         length = i-last
        #         last = i
        #         res = res + ((length-1)*length*(2*length-1))//6 + length*(length-1)//2
        #         res = res - length*length*(length+1)//2
        #         res = res + length*(length+1)//2
        # return res
