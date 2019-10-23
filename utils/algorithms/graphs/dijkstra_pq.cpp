const int INF = 1e9;
const int N = 1e6 + 5;

typedef pair<int, int> pii;

vector<pii> G[N];
int dist[N];
int vis[N];

void Dijkstra(int s, int n) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    fill(dist, dist + n + 1, INF); // accounts for 1 based nodes
    dist[s] = 0;
    Q.push({0, s});

    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto c : G[u]) {
            int v = c.first;
            int w = c.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}