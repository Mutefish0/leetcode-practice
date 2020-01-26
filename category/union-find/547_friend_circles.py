from disjoint_sets import DisjointSets

class Solution:
    def findCircleNum(self, M) -> int:
        n = len(M)
        ds = DisjointSets()
        for i in range(n):
            ds.make_set(i)
        for i in range(n):
            for j in range(i + 1):
                if M[i][j] == 1:
                    ds.union(i, j)
        return ds.get_count()



