#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
#define x first
#define y second

void fastInOut();
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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();

    while(true) {
        int m, n;
        cin >> m >> n;
        if(m == 0) return 0;
        unsigned int total = 0;
        dsu.init(m);
        vector<piii> edges(n);
        for(int i=0; i<n; i++) {
            cin >> edges[i].y.x
                >> edges[i].y.y
                >> edges[i].x;
            total += edges[i].x;
        }
        sort(edges.begin(), edges.end());
        for(piii e : edges) {
            if(dsu._find(e.y.x) == dsu._find(e.y.y))
                continue;
            total -= e.x;
            dsu._union(e.y.x, e.y.y);
        }
        cout << total << "\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
