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

const int N = 1e3 + 5;

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
piii edges[N]; // x weight, x.x u, x.y v

vector<pii> mst[N];

void kruskal(int m, int n)
{
    dsu.init(m);
    sort(edges, edges + n);
    for(int i=0; i<n; i++) {
        piii e = edges[i];
        if(dsu._find(e.y.x) == dsu._find(e.y.y))
            continue;
        dsu._union(e.y.x, e.y.y);
        mst[e.y.x].push_back({e.y.y, e.x});
        mst[e.y.y].push_back({e.y.x, e.x});
    }
}

int vid = 0;
int vis[N];
int dfs(int u, int cost,int target)
{
    if(u == target) return cost;
    int mn = 1e9;
    vis[u] = vid;
    for(pii p : mst[u]) {
        if(vis[p.x] == vid) continue;
        mn = min(mn, dfs(p.x, max(cost, p.y), target));
    }
    return mn;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T = 0;
    int c, s, q;
    cin >> c >> s >> q;
    while(true) {
        T++;
        for(int i=0; i<=c; i++)
            mst[i].clear();
        for(int i=0; i<s; i++) {
            cin >> edges[i].y.x
                >> edges[i].y.y
                >> edges[i].x;
        }
        kruskal(c, s);
        cout << "Case #" << T << "\n";
        for(int i=0; i<q; i++) {
            vid++;
            int u, v; cin >> u >> v;
            if(dsu._find(u) != dsu._find(v)) {
                cout << "no path\n";
                continue;
            }
            cout << dfs(u, 0, v) << "\n";
        }
        cin >> c >> s >> q;
        if(c == 0 && s == 0 && q == 0)
            return 0;
        else
            cout << "\n";
    }

    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
