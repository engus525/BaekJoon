n = int(input())
m = int(input())
graph = []
ans = 0

for _ in range(m):
    u, v, w = map(int, input().split())
    graph.append((u, v, w))

parent = [i for i in range(n + 1)]

def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x == y:
        return False

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

    return True

graph.sort(key=lambda x: x[2])

for g in graph:
    if union(g[0], g[1]):
        ans += g[2]

print(ans)