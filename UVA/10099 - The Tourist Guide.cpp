#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define x first
#define y second
void fastInOut();
const int N = 100 + 5;
const double EPS = 1e-8;

struct DSU
{
    const int SIZE = N;
    int parent[N];
    int sz[N];

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
    }
};

DSU dsu;
vector<pii> G[N];
int vid = 0;
int vis[N];
int dfs(int s, int d, int cost)
{
    if(s == d) return cost;
    vis[s] = vid;
    int mx = 0;
    for(pii p : G[s]) {
        if(vis[p.x] == vid) continue;
        mx = max(mx, dfs(p.x, d, min(cost, p.y)));
    }
    return mx;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T = 0;
    while(++T) {
        int n, r; cin >> n >> r;
        if(n == 0 && r == 0) return 0;
        vid++;
        dsu.init(n);
        for(int i=0; i<=n; i++) G[i].clear();
        vector<piii> edges(r);
        for(int i=0; i<r; i++) {
            cin >> edges[i].y.x
                >> edges[i].y.y
                >> edges[i].x;
        }
        sort(edges.rbegin(), edges.rend());
        for(piii e : edges) {
            if(dsu._find(e.y.x) == dsu._find(e.y.y))
                continue;
            dsu._union(e.y.x, e.y.y);
            G[e.y.x].push_back({e.y.y, e.x});
            G[e.y.y].push_back({e.y.x, e.x});
        }
        int s, d, t;
        cin >> s >> d >> t;
        int mx = dfs(s, d, 1e9);
        cout << "Scenario #" << T << "\n";
        cout << "Minimum Number of Trips = ";
        cout << (t + mx - 2) / (mx - 1) << "\n\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
