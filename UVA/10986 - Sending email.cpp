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
const int N = 2e4 + 5;

int n, m, src, dst;
vector<pii> G[N];

int vid = 1;
int vis[N];
int dist[N];

int dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()) {
        pii u = pq.top();
        pq.pop();
        if(u.y == dst)
            return dist[dst];
        if(vis[u.y] == vid)
            continue;
        vis[u.y] = vid;
        for(pii v : G[u.y]) {
            if(dist[u.y] + v.x < dist[v.y]) {
                dist[v.y] = dist[u.y] + v.x;
                pq.push({dist[v.y], v.y});
            }
        }
    }
    return -1;
}

clear()
{
    vid++;
    for(int i=0; i<n; i++)
        G[i].clear();
    fill(dist, dist + n, INT_MAX);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastInOut();
    int T; cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> n >> m >> src >> dst;
        clear();
        for(int i=0; i<m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({w, v});
            G[v].push_back({w, u});
        }
        cout << "Case #" << t << ": ";
        int res = dijkstra();
        if(~res)
            cout << res << '\n';
        else
            cout << "unreachable\n";
    }
    return 0;
}

void fastInOut(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}
