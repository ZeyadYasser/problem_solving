#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
#define x first
#define y second
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
void fastInOut();
const int N = 1e2 + 5;

int n, e, t;
vector<pii> G[N];
int dist[N];
int vid = 1;
int vis[N];
void clear()
{
    vid++;
    fill(dist, dist + n, INT_MAX);
    for(int i=0; i<n; i++)
        G[i].clear();
}

void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[e] = 0;
    pq.push({0, e});
    while(!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        if(vis[u.y] == vid)
            continue;
        vis[u.y] = vid;
        for(pii p : G[u.y]) {
            if(u.x + p.x < dist[p.y]) {
                dist[p.y] = u.x + p.x;
                pq.push({dist[p.y], p.y});
            }
        }
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    while(T--) {
        cin >> n >> e >> t;
        e--;
        int m; cin >> m;
        clear();
        while(m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            G[v].push_back({w, u});
        }
        dijkstra();
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += (dist[i] <= t) ? 1 : 0;
        cout << ans << '\n';
        if(T)
            cout << '\n';
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
