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
    int repr_cnt;
    void init(int n) {
        // (+1) for 1 based idx
        iota(parent, parent + n + 1, 0); // 0 1 2 . . . n
        fill(sz, sz + n + 1, 1);
        repr_cnt = n;
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
        repr_cnt--;
    }
};

DSU dsu;

pii coords[N];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        int s, p;
        cin >> s >> p;
        dsu.init(p);
        for(int i=1; i<=p; i++)
            cin >> coords[i].x >> coords[i].y;
        vector<piii> edges;
        for(int i=1; i<=p; i++) {
            for(int j=i+1; j<=p; j++) {
                int dst = (coords[i].x-coords[j].x)*(coords[i].x-coords[j].x);
                dst += (coords[i].y-coords[j].y)*(coords[i].y-coords[j].y);
                edges.push_back({dst, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        double D = 0;
        for(piii e : edges) {
            if(dsu.repr_cnt <= s) break;
            if(dsu._find(e.y.x) == dsu._find(e.y.y))
                continue;
            D = max(D, sqrt((double)e.x));
            dsu._union(e.y.x, e.y.y);
        }
        cout << fixed << setprecision(2)
             << D << "\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
