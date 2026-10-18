class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        # Pascal's triangle se nCr precompute
        C = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            C[i][0] = 1
            for j in range(1, i + 1):
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD

        def solve(arr):
            if len(arr) <= 2:
                return 1
            root = arr[0]
            left = [x for x in arr if x < root]
            right = [x for x in arr if x > root]
            L, R = len(left), len(right)
            return C[L + R][L] * solve(left) % MOD * solve(right) % MOD

        return (solve(nums) - 1) % MOD