class Solution:
    def climbStairs(self, n):
        if n <= 1:
            return 1
        first = 1
        second = 2
        for i in range(3, n + 1, 1):
            third = first + second
            first = second
            second = third
        return second

    def climbStairs2(self, n):
        if n == 0:
            return 1
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        list = [None] * (n + 1)
        list[0] = 1
        list[1] = 1
        list[2] = 2
        i = 3
        while i <= n:
            list[i] = list[i - 1] + list[i - 2]
            i += 1
        return list[n]
