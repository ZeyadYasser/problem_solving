#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define x first
#define y second
void fastInOut();
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

struct DSU
{
    const int SIZE = N;
    int parent[N];
    int sz[N];

    int mode_sz=0, mode=0;

    void init(int n) {
        // (+1) for 1 based idx
        iota(parent, parent + n + 1, 0); // 0 1 2 . . . n
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
        if(sz[b] > mode_sz) {
            mode = b;
            mode_sz = sz[b];
        }
    }
};

pii coords[N];
DSU dsu;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        dsu.init(n);
        for(int i=1; i<=n; i++)
            cin >> coords[i].x >> coords[i].y;
        int m; cin >> m;
        for(int i=0; i<m; i++) {
            int u, v; cin >> u >> v;
            dsu._union(u, v);
        }
        vector<piii> edges;
        for(int i=1; i<=n; i++) {
            if(dsu._find(i) == dsu.mode)
                continue;
            for(int j=1; j<=n; j++) {
                if(i == j) continue;
                int dst = (coords[i].x-coords[j].x)*(coords[i].x-coords[j].x);
                dst += (coords[i].y-coords[j].y)*(coords[i].y-coords[j].y);
                edges.push_back({dst, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<pii> new_roads;
        for(piii e : edges) {
            if(dsu._find(e.y.x) == dsu._find(e.y.y))
                continue;
            dsu._union(e.y.x, e.y.y);
            new_roads.push_back({min(e.y.x, e.y.y), max(e.y.x, e.y.y)});
        }
        for(auto p : new_roads) {
            cout << p.x << " " << p.y << "\n";
        }
        if(new_roads.empty())
            cout << "No new highways need\n";
        if(T)
            cout << "\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
