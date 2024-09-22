class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        
        x, k = 1, k - 1

        def count(p, nx):
            cnt = 0
            while p <= n:
                cnt += min(n + 1, nx) - p
                p, nx = 10 * p, 10 * nx
            return cnt

        while k > 0:
            cnt = count(x, x + 1)
            if cnt > k:
                x, k = x * 10, k - 1
            else:
                x, k = x + 1, k - cnt
        
        return x
