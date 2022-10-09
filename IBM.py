
# from sys import setrecursionlimit
# setrecursionlimit(10 ** 6)

# def dfs(x, y, vi, a, n, m, memo):
#     if not (0 <= x < n and 0 <= y < m) or a[x][y] == '0': return 0
#     if vi[x][y]: return memo[x][y]
#     vi[x][y] = 1
#     max_ = 0
#     for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
#         i += x
#         j += y
#         max_ = max(max_, dfs(i, j, vi, a, n, m, memo))
#     memo[x][y] = max_ + 1
#     return memo[x][y]

# def get_big():
#     n = int(input())
#     m = int(input())
#     a = [0] * n
#     for i in range(n):
#         a[i] = input().split()
#     vi = [[0] * m for _ in range(n)]
#     memo = [[0] * m for _ in range(n)]
#     max_ = 0
#     for i in range(n):
#         for j in range(m):
#             if vi[i][j] or a[i][j] == '0': continue
#             max_ = max(max_, dfs(i, j, vi, a, n, m, memo))
#     for i in memo:
#         print(i)
#     return max_

# print(get_big())

# from collections import deque

# def bfs(x, y, vi, a, n, m):
#     q = deque()
#     count = 0
#     q.append((x, y))
#     while len(q):
#         r, c = q.popleft()
#         vi[r][c] = 1
#         count += 1
#         for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
#             i += r
#             j += c
#             if 0 <= i < n and 0 <= j < m and a[i][j] == '1' and not vi[i][j]:
#                 q.append((i, j))
#     return count



# def solve():
#     n = int(input())
#     a = list(map(int, input().split()))
#     l, r = [0] * n, [0] * n
#     l[0], r[-1] = 1, 1
#     for i in range(1, n):
#         if a[i - 1] < a[i]:
#             l[i] = l[i - 1] + 1
#         else: l[i] = 1
#     for i in range(n - 2, -1, -1):
#         if a[i + 1] < a[i]:
#             r[i] = r[i + 1] + 1
#         else: r[i] = 1
#     sum_ = 0
#     for i, j in zip(l, r):
#         sum_ += max(i, j)
#     return sum_

# print(solve())

############################### 4:00 session ##############################

# n = int(input())
# count = 0
# while not (n & 1):
#     count += 1
#     n >>= 1
# print(count + (n & 1 != 0))


# n, m, r = map(int, input().split())
# memo = {}
# for _ in range(r):
#     r, s, e = map(int, input().split())
#     memo[r] = memo.get(r, []) + [[s, e]]
# for k, lt in memo.items():
#     ln = len(lt)
#     tp = sorted(lt)
#     nl = [lt[0]]
#     for i in range(1, ln):
#         if tp[i - 1][1] >= tp[i][1]:
#             continue
#         nl.append(tp[i])
#     memo[k] = [[0, 0]] + nl + [[m + 1, m + 1]]
# sum_ = 0
# for k in range(1, n + 1):
#     lt = memo.get(k, [[0, 0], [m + 1, m + 1]])
#     ln = len(lt)
#     for i in range(1, ln):
#         sum_ += max(0, lt[i][0] - lt[i - 1][1] - 1)
# print(sum_)


# n = int(input())
# a = sorted(list(map(int, input().split())))
# b = sorted(list(map(int, input().split())))
# print(0 + (a == b))


# n = int(input())
# cost = (n // 50) * 15000
# n = n % 50
# cost += (n // 10) * 3250
# n = n % 10
# cost += (n // 2) * 750
# n = n % 2
# cost += n * 400
# print(cost)
