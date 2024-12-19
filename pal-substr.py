n = 2 * len(s) + 3
v = '#'.join(f'^{s}$')

C, R = 0, 0
P = [0] * n
for i in range(1, n - 1):
    M = 2 * C - i
    if i < R:
        P[i] = min(R - i, P[M])
    while v[i + P[i] + 1] == v[i - P[i] - 1]:
        P[i] += 1
    if R < i + P[i]:
        C, R = i, i + P[i]
