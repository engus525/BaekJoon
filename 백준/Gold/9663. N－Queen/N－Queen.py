import sys
si = sys.stdin.readline
N = int(si())
dfs_count = 0

row = [0] * (N)
answer = 0

def isPromising(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False

    return True

def dfs(index):
    global dfs_count
    global answer

    dfs_count += 1

    if index == N:
        answer += 1

    else:
        for i in range(N):
            row[index] = i
            if isPromising(index):
                dfs(index + 1)            

dfs(0)
print(answer)
