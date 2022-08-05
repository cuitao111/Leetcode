

from calendar import Calendar


class Solution:
    def test(self, n):

        if(n == 1):
            return 1
        if(n == 2):
            return 2
        if(n == 3):
            return 4

        

        f = [1] * (n + 1)
        f[1] = 1
        f[2] = 1
        f[3] = 3
        f[4] = 6

        for i in range(4, n):
            f[i] = f[i - 1]
            if(i >= 4):
                f[i] += f[i - 4]

        
        print(f[n - 1])
        print(f[n - 2])
        print(f[n - 3])
        print(f[n - 4])

        f[n] = f[n -1] + f[n -2] + f[n -3]

        return f[n]


if __name__ == "__main__":
    s = Solution()
    print(s.test(4))