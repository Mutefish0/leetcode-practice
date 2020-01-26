class DisjointSets:
    def __init__(self):
        self.keys = {}
        self.ranks = {}
        self.parents = {}     

    def make_set(self, key):
        if key not in self.keys:
            self.keys[key] = key
            self.ranks[key] = 0
            self.parents[key] = key

    def find(self, key):
        node = key
        parent = self.parents[node]
        while parent != node:
            node = parent
            parent = self.parents[node]
        self.parents[key] = node
        return node

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a == root_b:
            return
        (rank_a, rank_b) = (self.ranks[root_a], self.ranks[root_b])
        if rank_a < rank_b:
            (root_a, root_b) = (root_b, root_a)
            (rank_a, rank_b) = (rank_b, rank_a)
        self.parents[root_b] = root_a
        self.ranks[root_a] = max(rank_a, rank_b + 1)
    

    def get_count(self):
        result = 0
        for key in self.keys:
            if self.parents[key] == key:
                result += 1
        return result


