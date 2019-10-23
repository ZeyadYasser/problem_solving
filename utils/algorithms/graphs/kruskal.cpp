typedef pair<int, pair<int, int>> piii;
#define x first
#define y second

const int N = 2e5 + 5;

struct DSU
{
    const int SIZE = N;
    int parent[N];
    int sz[N];

    void init(int n) {
        iota(parent, parent + n + 1, 0); // for 1 based idx
        fill(sz, sz + n + 1, 1);
    }

    int _find(int u) {
        return parent[u] = (parent[u] == u ? u : _find(parent[u]));
    }

    void _union(int u, int v) {
        int a = _find(u);
        int b = _find(v);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        parent[a] = parent[b];
    }
};

DSU dsu;
int m, n; // number of nodes, number of edges
// long long for large inputs
piii edges[N]; // x weight, x.x u, x.y v

int kruskal() {
    dsu.init(m);
    sort(edges, edges + n);
    int total = 0;
    for(int i=0; i<n; i++) {
        piii e = edges[i];
        if(dsu._find(e.y.x) == dsu._find(e.y.y))
            continue;
        total += e.x;
        dsu._union(e.y.x, e.y.y);
    }
    return total;
}

int main()
{
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        cin >> edges[i].y.x // node u
            >> edges[i].y.y // node v
            >> edges[i].x;  // weight
    }

    cout << kruskal() << "\n";
    return 0;
}
