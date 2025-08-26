class Solution:
    # def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    #     G = collections.defaultdict(dict)
    #     for (x, y), v in zip(equations, values):
    #         G[x][y] = v
    #         G[y][x] = 1/v
    #     def bfs(src, dst):
    #         if not (src in G and dst in G): return -1.0
    #         q, seen = [(src, 1.0)], set()
    #         for x, v in q:
    #             if x == dst:
    #                 return v
    #             seen.add(x)
    #             for y in G[x]:
    #                 if y not in seen:
    #                     q.append((y, v*G[x][y]))
    #         return -1.0
    #     return [bfs(s, d) for s, d in queries]
    def calcEquation(self, equations, values, queries):
        root = {}
        def find(x):
            p, xr = root.setdefault(x, (x, 1.0))
            if x != p:
                r, pr = find(p)
                root[x] = (r, xr*pr)
            return root[x]

        def union(x, y, ratio):
            px, xr, py, yr = *find(x), *find(y)
            if not ratio:
                return xr / yr if px == py else -1.0
            if px != py:
                root[px] = (py, yr/xr*ratio)

        for (x, y), v in zip(equations, values):
            union(x, y, v)

        return [union(x, y, 0) if x in root and y in root else -1.0 for x, y in queries]
