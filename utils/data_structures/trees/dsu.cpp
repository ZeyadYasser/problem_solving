int N = 1e5 + 5;

struct DSU
{
    int p[N];
    int sz[N];

    void init(int n) {
        // (+1) for 1 based idx
        iota(p, p + n + 1, 0); // 0 1 2 . . . n
        fill(sz, sz + n + 1, 1);
    }

    int _find(int u) {
        return p[u] = (p[u] == u ? u : _find(p[u]));
    }

    void _union(int a, int b) {
        a = _find(a);
        b = _find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = p[b];
    }
};