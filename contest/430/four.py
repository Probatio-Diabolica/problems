from math import comb


def countGoodArrays(n: int, m: int, k: int) -> int:
         return comb(n-1, n-k-1) * (m * (m-1)**(n-k-1)) % (10**9 + 7)