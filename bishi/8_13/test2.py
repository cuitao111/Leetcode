from collections import deque

def RevertNums(nums):
    n = len(nums)
    if n == 1:
        print(nums[0])
    if n== 2:
        print(nums[0] + " " + nums[1])
    ret = deque()
    ret.append(nums[n - 2])
    ret.append(nums[n - 1])
    i = n - 3
    while(i >= 0):
        ret.appendleft(nums[i])
        j = 0
        while(j < 2):
            tmp = ret.pop()
            ret.appendleft(tmp)
            j = j+ 1
        i= i-1

    for num in ret:
        print(num)


RevertNums([1,2,3,4])